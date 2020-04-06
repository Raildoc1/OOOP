package ru.ugame.core;

import ru.ugame.objects.Board;

import java.awt.*;

public class Game {

    private static GameHandler gameHandler;

    public static void registerGameobject(GameObject obj) {
        gameHandler.registerGameobject(obj);
    }

    public static void main(String[] args) {

        Input input = new Input();

        gameHandler = new GameHandler();
        View view = new View(gameHandler);
        view.addKeyListener(input);
        Board board = new Board();
        registerGameobject(board);
        gameHandler.init();

        EventQueue.invokeLater(() -> {
            view.init();
            view.setVisible(true);
        });

        while(gameHandler.isRunning()) {
            gameHandler.update();
            view.display();
        }
    }
}
