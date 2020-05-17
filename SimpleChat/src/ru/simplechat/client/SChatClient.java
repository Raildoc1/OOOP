package ru.simplechat.client;

import ru.simplechat.GUI.IUI;
import ru.simplechat.datatypes.Message;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.ArrayList;

public class SChatClient extends Socket {

    private boolean running = true;
    public boolean isRunning() {return running;}

    private DataOutputStream oos;
    private DataInputStream ois;

    public ArrayList<Message> messages;

    private IUI toUpdate;

    public static void main(String[] args) throws IOException {
        SChatClient client = new SChatClient("localhost", 3434);
        client.start();
    }

    public SChatClient(String host, int port) throws IOException {
        super(host, port);
        messages = new ArrayList<Message>();
    }

    public void start(){

        running = true;

        System.out.print("Enter nickname: ");

        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));){

            oos = new DataOutputStream(this.getOutputStream());
            ois = new DataInputStream(this.getInputStream());

            while(!this.isOutputShutdown()){
                if(!running) break;
                if(ois.available() > 0) {
                    String in = ois.readUTF();
                    printlnMessage(in);
                    System.out.println(in);
                }
            }

        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setMessages(ArrayList<Message> messages) {
        this.messages = messages;
    }

    public void printMessage(String mess) {
        if(toUpdate == null) return;
        toUpdate.printMessage(mess);
    }

    public void printlnMessage(String mess) {
        if(toUpdate == null) return;
        toUpdate.printMessage(mess + "\n");
    }

    public void setToUpdate(IUI toUpdate) {
        this.toUpdate = toUpdate;
    }

    public void sendMessage(String message) throws IOException {
        oos.writeUTF(message);
        oos.flush();

        //String in = ois.readUTF();
        //printlnMessage(in);
        //System.out.println(in);
    }

    public void stop() throws IOException {
        oos.writeUTF("/quit");
        oos.flush();
        running = false;
    }
}
