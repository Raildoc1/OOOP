package ru.ugame.core;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.security.cert.CertPathValidatorException;

public class Input extends KeyAdapter {

    private static int KEY_PRESSED = -1;

    @Override
    public void keyPressed(KeyEvent event) {
        //System.out.println(event.getKeyCode());
        KEY_PRESSED = event.getKeyCode();
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if(KEY_PRESSED == e.getKeyCode()) KEY_PRESSED = -1;
    }

    public static int getKeyPressed() {
        return KEY_PRESSED;
    }
}
