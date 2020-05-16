package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;
import ru.simplechat.server.SChatServer;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;

public class Frame1 extends JFrame {

    private static final String APP_NAME = "Simple Chat";
    private static final int WIN_WIDTH = 350;
    private static final int WIN_HEIGHT = 350;

    private static SChatClient client;

    public Frame1() throws IOException {
        Frame1.client = new SChatClient("localhost", 3434);
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

    public static void startClient(){
        if(client != null)client.start();
    }
    public static void closeClient() throws IOException {
        if(client != null)client.stop();
    }

    public static void main(String[] args) throws IOException {
        Frame frame = new Frame();
        EventQueue.invokeLater(() -> {
            frame.init();
            frame.setVisible(true);
        });
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                try {
                    closeClient();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
                System.exit(0);
            }
        });
        frame.startClient();
    }
}
