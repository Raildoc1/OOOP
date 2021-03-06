package ru.ugame.core;

import ru.ugame.objects.Board;

import javax.swing.*;

public class View extends JFrame {

    private final static String APP_NAME = "UntitledGame";

    private static final int WIN_WIDTH = 250;
    private static final int WIN_HEIGHT = 350;
    private static final int GRID_SCALE = 15;

    Board board;

    public View (Board board) {
        this.board = board;
    }

    public void init() {
        add(new GamePanel(board, GRID_SCALE));
        setSize((board.getWidth() + 3) * GRID_SCALE, (board.getHeight() + 3) * GRID_SCALE + 22);
        setTitle(APP_NAME);
        setResizable(false);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.addKeyListener(new Input(board));
        setLocationRelativeTo(null);
    }

    public void display() {}
}
