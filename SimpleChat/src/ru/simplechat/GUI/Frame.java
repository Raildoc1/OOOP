package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;
import ru.simplechat.server.SChatServer;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;

public class Frame extends JFrame {

    private static final String APP_NAME = "Simple Chat";
    private static final int WIN_WIDTH = 250;
    private static final int WIN_HEIGHT = 350;

    private SChatClient client;

    public Frame() throws IOException {
        this.client = new SChatClient("localhost", 3434);
    }

    public void init() {
        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        Panel panel = new Panel();
        add(panel);
        client.setToUpdate(panel);
    }

    public void startClient(){
        client.start();
    }

    public static void main(String[] args) throws IOException {
        Frame frame = new Frame();
        EventQueue.invokeLater(() -> {
            frame.init();
            frame.setVisible(true);
        });
        frame.startClient();
    }

}
