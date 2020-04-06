package ru.ugame.core;

import javax.swing.*;

public class View extends JFrame {

    private final static String APP_NAME = "UntitledGame";

    private static final int WIN_WIDTH = 250;
    private static final int WIN_HEIGHT = 350;

    GameHandler gameHandler;

    public View (GameHandler gameHandler) {
        this.gameHandler = gameHandler;
    }

    public void init() {
        add(new GamePanel(gameHandler));

        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public void display() {}
}
