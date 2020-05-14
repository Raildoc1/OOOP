package ru.simplechat.server;

import ru.simplechat.GUI.IUI;
import ru.simplechat.client.SChatClient;
import ru.simplechat.datatypes.Message;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;

public class MonoThreadClientHandler implements Runnable {

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
            }

            while(!client.isClosed()){
                String entry = in.readUTF();

                server.addMessage(nickname, entry);

                if(entry.equalsIgnoreCase("/quit")){
                    System.out.println("Client initialize connections suicide ...");
                    out.writeUTF("Server reply - " + entry + " - OK");
                    break;
                }

                //System.out.println(nickname + ": " + entry);
                //out.writeUTF(nickname + ": " + entry);

                //out.flush();
            }

            System.out.println("Client disconnected");
            System.out.println("Closing connections & channels.");

            in.close();
            out.close();

            client.close();

            System.out.println("Closing connections & channels - DONE.");

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
