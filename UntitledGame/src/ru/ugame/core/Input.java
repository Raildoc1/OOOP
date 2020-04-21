package ru.ugame.core;

import ru.ugame.math.Vector2;
import ru.ugame.objects.Board;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.security.cert.CertPathValidatorException;
import java.util.Deque;

public class Input extends KeyAdapter {

    Board board;

    public Input(Board board) {
        this.board = board;
    }

    @Override
    public void keyPressed(KeyEvent event) {
        //if(board == null) return;
        System.out.println(event.getKeyCode());
        if (event.getKeyCode() == 87) board.changeDirection(0, -1); // W
        if (event.getKeyCode() == 83) board.changeDirection(0, 1); // S
        if (event.getKeyCode() == 68) board.changeDirection(1, 0); // D
        if (event.getKeyCode() == 65) board.changeDirection(-1 ,0); // A
    }
}
