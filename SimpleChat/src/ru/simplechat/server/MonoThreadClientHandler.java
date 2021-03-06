package ru.simplechat.server;

import ru.simplechat.GUI.IUI;
import ru.simplechat.client.SChatClient;
import ru.simplechat.datatypes.Message;
import ru.simplechat.datatypes.User;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Logger;

public class MonoThreadClientHandler implements Runnable {

    private final Logger logger = Logger.getLogger(SChatServer.class.getName());

    private boolean running = true;
    public boolean isRunning() {return running;}
    private SChatServer server;
    private Socket client;

    private String nickname;

    public ArrayList<Message> messages;

    DataOutputStream out;
    DataInputStream in;

    public MonoThreadClientHandler(Socket client, SChatServer server) {
        this.client = client;
        this.server = server;
    }

    @Override
    public void run() {

        try {
            out = new DataOutputStream(client.getOutputStream());
            in = new DataInputStream(client.getInputStream());

            while (nickname == null && running) {
                if(!client.isClosed()) {
                    String entry = in.readUTF();
                    nickname = entry;

                    if(nickname.equalsIgnoreCase("/quit")) {
                        running = false;
                        break;
                    }

                    if(server.isUserRegistered(nickname)) {

                        if(server.isUserOnline(nickname)) {
                            out.writeUTF("Nickname " + nickname + " is already taken! Try another one.");
                            nickname = null;
                        } else {
                            server.changeUserOnline(nickname, true);
                            out.writeUTF("Welcome back, " + nickname + "!");
                        }
                    } else {
                        server.registerUser(nickname);
                        server.changeUserOnline(nickname, true);
                        out.writeUTF("You registered as " + nickname);
                    }

                    out.flush();
                } else {
                    running = false;
                }
            }


            while(running && client != null && !client.isClosed()){
                String entry;
                if(in == null) break;
                try {
                    entry = in.readUTF();
                    if(entry.charAt(0) != '/') {
                        server.addMessage(nickname, entry);
                    } else {
                        switch (entry) {
                            case "/quit":
                                running = false;
                                break;
                            case "/users":
                                out.writeUTF(server.getUsersInfo());
                                break;
                            default:
                                logger.warning("Unknown command");//System.out.println("Unknown command");
                                out.writeUTF("Unknown command");
                                break;
                        }
                        server.updateServer();
                    }
                } catch (Exception e) {
                    running = false;
                    server.updateServer();
                }
            }

            logger.info("Client disconnected");

            if(!nickname.equalsIgnoreCase("/quit"))server.changeUserOnline(nickname, false);

            in.close();
            out.close();
            client.close();

            running = false;

            server.updateServer();
        } catch (IOException e) {
            running = false;
            server.updateServer();
            return;
        }

    }

    public void printMessage(Message message) throws IOException {
        //System.out.println(message.toString());
        try {
            out.writeUTF(message.toString());
            out.flush();
        } catch (IOException e) {
            //e.printStackTrace();
            running = false;
            return;
        }
    }
}
