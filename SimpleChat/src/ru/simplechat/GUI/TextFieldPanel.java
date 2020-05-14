package ru.simplechat.GUI;

import javax.swing.*;
import java.awt.*;

public class TextFieldPanel extends JPanel {

    JTextField textField;
    JButton sendButton;

    public TextFieldPanel() {
        textField = new JTextField();
        textField.setPreferredSize(new Dimension(200, 20));
        sendButton = new JButton();
        sendButton.setText("Send");
        sendButton.setPreferredSize(new Dimension(70, 20));
        FlowLayout fl = new FlowLayout();
        setLayout(fl);
        add(textField);
        add(sendButton);
    }

}
