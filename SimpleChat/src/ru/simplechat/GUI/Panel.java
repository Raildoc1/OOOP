package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;
import ru.simplechat.datatypes.Message;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Panel extends JPanel implements IUI {

    private static final int M_HISTORY_SIZE = 17;
    private JTextArea textArea;
    private JScrollPane scrollPane;

    public Panel() {
        textArea = new JTextArea();
        textArea.setEditable(false);

        scrollPane = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        scrollPane.setPreferredSize(new Dimension(300, 250));

        add(scrollPane);

        textArea.append("Connecting to server...\n");
    }

    @Override
    public void printMessage(String mess) {
        textArea.append(mess);
    }

    @Override
    protected void paintComponent(Graphics g) {
        //System.out.println("Updated!");
    }
}
