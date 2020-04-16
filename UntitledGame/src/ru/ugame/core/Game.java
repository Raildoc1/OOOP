package ru.ugame.core;

import ru.ugame.objects.Board;

import java.awt.*;

public class Game {

    public static void main(String[] args) {

        Input input = new Input();

        Board board = new Board();
        View view = new View(board);
        view.addKeyListener(input);

        EventQueue.invokeLater(() -> {
            view.init();
            view.setVisible(true);
        });

        board.start();
    }
}
