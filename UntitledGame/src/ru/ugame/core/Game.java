package ru.ugame.core;

import ru.ugame.objects.Board;

import java.awt.*;

public class Game {

    public static void main(String[] args) {

        Board board = new Board();

        Input input = new Input(board);
        View view = new View(board);
        view.addKeyListener(input);

        EventQueue.invokeLater(() -> {
            view.init();
            view.setVisible(true);
        });

        board.start();
    }
}
