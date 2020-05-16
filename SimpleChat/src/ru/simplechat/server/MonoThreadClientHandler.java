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

public class MonoThreadClientHandler implements Runnable {

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

            if(!client.isClosed()) {
                String entry = in.readUTF();
                nickname = entry;

                server.registerUser(nickname);

                out.writeUTF("Your nickname is " + nickname);
                out.flush();
            } else {
                running = false;
            }

            while(running || client != null || !client.isClosed()){
                String entry;
                if(in == null) break;
                if(in.available() > 0) {
                    entry = in.readUTF();

                    if(entry.charAt(0) != '/') {
                        server.addMessage(nickname, entry);
                    } else {
                        switch (entry) {
                            case "/quit":
                                running = false;
                                break;
                            case "/users":
                                String temp = "";
                                for(User u : server.getUsers()) {
                                    temp += u.getNickname() + "\n";
                                }
                                out.writeUTF(temp);
                                break;
                            default:
                                System.out.println("Unknown command");
                                out.writeUTF("Unknown command");
                                break;
                        }
                    }
                }
            }

            System.out.println("Client disconnected");
            System.out.println("Closing connections & channels.");

            in.close();
            out.close();

            client.close();

            System.out.println("Closing connections & channels - DONE.");

            running = false;

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void printMessage(Message message) throws IOException {
        System.out.println(message.toString());
        try {
            out.writeUTF(message.toString());
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
