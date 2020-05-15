package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;

public class Frame1 extends JFrame {

    private static final String APP_NAME = "Simple Chat";
    private static final int WIN_WIDTH = 350;
    private static final int WIN_HEIGHT = 350;

    private SChatClient client;

    public Frame1() throws IOException {
        this.client = new SChatClient("localhost", 3434);
    }

    public void init() {
        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        Panel panel = new Panel();
        TextFieldPanel panel1 = new TextFieldPanel(client);
        setLayout(new FlowLayout());
        add(panel);
        add(panel1);
        client.setToUpdate(panel);
    }

    public void startClient(){
        client.start();
    }

    public static void main(String[] args) throws IOException {
        Frame1 frame = new Frame1();
        EventQueue.invokeLater(() -> {
            frame.init();
            frame.setVisible(true);
        });
        frame.startClient();
    }

}
