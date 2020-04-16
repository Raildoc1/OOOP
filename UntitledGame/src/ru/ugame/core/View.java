package ru.ugame.core;

import ru.ugame.objects.Board;

import javax.swing.*;

public class View extends JFrame {

    private final static String APP_NAME = "UntitledGame";

    private static final int WIN_WIDTH = 250;
    private static final int WIN_HEIGHT = 350;

    Board board;

    public View (Board board) {
        this.board = board;
    }

    public void init() {
        add(new GamePanel(board));

        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public void display() {}
}
