package ru.simplechat.server;

import ru.simplechat.client.SChatClient;
import ru.simplechat.datatypes.Message;
import ru.simplechat.datatypes.User;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Logger;

public class SChatServer {

    private final Logger logger = Logger.getLogger(SChatServer.class.getName());

    ExecutorService executorService = Executors.newFixedThreadPool(255);

    private ArrayList<User> users;
    private ArrayList<Message> messages;
    private ArrayList<MonoThreadClientHandler> userThreads;

    public SChatServer () {
        users = new ArrayList<User>();
        messages = new ArrayList<Message>();
        userThreads = new ArrayList<MonoThreadClientHandler>();
    }

    public static void main(String[] args) {
        SChatServer server = new SChatServer();
        server.start();
    }

    public void start() {

        try(
                ServerSocket server = new ServerSocket(3434);
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))
        ) {

            //System.out.println("Server socket created");

            logger.info("Server socket created");

            while (!server.isClosed()) {

                Socket client = server.accept();

                MonoThreadClientHandler userThread = new MonoThreadClientHandler(client, this);

                userThreads.add(userThread);

                executorService.execute(userThread);
                //System.out.println("Connection accepted");
                logger.info("Connection accepted");
            }

            executorService.shutdown();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void registerUser(String nickname) {
        if(isUserRegistered(nickname)) {
            logger.warning("user " + nickname + " is already registered!");
            return;
        }
        users.add(new User(nickname));
        logger.info("user " + nickname + " registered");
    }

    public boolean isUserRegistered (String nickname) {
        for(User u : users) {
            if(u.getNickname().equals(nickname)) {
                return true;
            }
        }
        return false;
    }

    public void changeUserOnline(String nickname, boolean online) {
        for(User u : users){
            if(u.getNickname().equals(nickname)){
                u.setOnline(online);
                if(online) logger.info(nickname + " is now online");
                else logger.info(nickname + " is now offline");
                return;
            }
        }
        logger.warning("Checking online of unregistered user!");
        System.out.println("User " + nickname + " not registered!");
        // Log "user not found"
    }

    public void addMessage(String nickname, String message) throws IOException {
        Message tmp = new Message(nickname, message);
        messages.add(tmp);
        for(MonoThreadClientHandler t: userThreads) {
            if(!t.isRunning()) userThreads.remove(t);
        }
        for (MonoThreadClientHandler t: userThreads) {
            t.printMessage(tmp);
        }
    }

    public ArrayList<Message> getMessages() {
        ArrayList<Message> ms = (ArrayList<Message>)messages.clone();
        return ms;
    }

    public ArrayList<User> getUsers() {
        ArrayList<User> us = (ArrayList<User>)users.clone();
        return us;
    }

    public String getUsersInfo() {
        String info = "";
        for(User u : users) {
            info += u.getNickname();
            info += " - ";
            info += (u.isOnline() ? "online" : "offline") + "\n";
        }
        return info;
    }
}
