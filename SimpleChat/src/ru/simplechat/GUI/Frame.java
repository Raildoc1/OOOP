package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;
import ru.simplechat.server.SChatServer;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.util.*;
import java.util.Timer;

public class Frame extends JFrame {

    private static final String APP_NAME = "Simple Chat";
    private static final int WIN_WIDTH = 350;
    private static final int WIN_HEIGHT = 350;
    private static SChatClient client;

    private static Panel panel;
    private static TextFieldPanel panel1;

    /*public Frame() throws IOException {
        try{
            Frame.client = new SChatClient("localhost", 3434);
        } catch (Exception e) { IGNORE }
    }*/

    public void init() {
        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        panel = new Panel();
        panel1 = new TextFieldPanel(client, panel, this);
        setLayout(new FlowLayout());
        add(panel);
        add(panel1);
        setVisible(true);

        if(client != null){
            client.setToUpdate(panel);
            startClient();
            panel.printMessage("Connected!\n");
            return;
        }
        else {
            panel.printMessage("Connecting to server...\n");
            Timer timer = new Timer();
            TimerTask timerTask = new TimerTask() {
                @Override
                public void run() {
                    try{
                        Frame.client = new SChatClient("localhost", 3434);
                    } catch (Exception e) { /*IGNORE*/ }
                    if(client != null) {
                        timer.cancel();
                        panel.printMessage("Connected!\n");
                        panel1.addClient(client);
                        client.setToUpdate(panel);
                        startClient();
                        return;
                    }
                }
            };
            timer.schedule(timerTask, 0, 1000);
        }
        System.out.println("End init!");
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
    }

    public void restart() throws IOException {
        client = null;
        panel.printMessage("Connecting to server...\n");
        Timer timer = new Timer();
        TimerTask timerTask = new TimerTask() {
            @Override
            public void run() {
                try{
                    Frame.client = new SChatClient("localhost", 3434);
                } catch (Exception e) { /*IGNORE*/ }
                if(client != null) {
                    timer.cancel();
                    panel.printMessage("Connected!\n");
                    panel1.addClient(client);
                    client.setToUpdate(panel);
                    startClient();
                    return;
                }
            }
        };
        timer.schedule(timerTask, 0, 1000);
    }
}
