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

    public Panel() {
        textArea = new JTextArea();
        textArea.setEditable(false);
        add(textArea);
    }

    @Override
    public void printMessage(String mess) {
        textArea.append(mess);
    }
}
