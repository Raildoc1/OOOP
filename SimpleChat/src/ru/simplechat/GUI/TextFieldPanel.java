package ru.simplechat.GUI;

import ru.simplechat.client.SChatClient;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class TextFieldPanel extends JPanel implements ActionListener {

    private JTextField textField;
    private JButton sendButton;
    private SChatClient client;

    public TextFieldPanel(SChatClient client) {
        this.client = client;
        textField = new JTextField();
        textField.setPreferredSize(new Dimension(200, 20));
        sendButton = new JButton();
        sendButton.setText("Send");
        sendButton.addActionListener(this);
        sendButton.setPreferredSize(new Dimension(70, 20));
        FlowLayout fl = new FlowLayout();
        setLayout(fl);
        add(textField);
        add(sendButton);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(client == null) return;
        try {
            if(textField.getText().isEmpty()) return;
            client.sendMessage(textField.getText());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        textField.setText("");
    }

    public void addClient(SChatClient client) {
        this.client = client;
    }
}
