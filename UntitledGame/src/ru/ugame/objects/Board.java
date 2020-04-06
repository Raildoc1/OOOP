package ru.ugame.objects;

import ru.ugame.core.GameObject;
import ru.ugame.math.Vector2;

import java.util.Random;

public class Board extends GameObject {

    private int width = 10;
    private int height = 10;

    private GameObject[][] board = new GameObject[width][height];

    public Board() {
        super();
    }

    @Override
    public void awake() {
        super.awake();
        Random random = new Random();
        Vector2 headPosition = new Vector2(random.nextInt(4) + 3, random.nextInt(4) + 3);
        Head head = new Head(headPosition);
    }

    @Override
    public void update() {
        super.update();

    }
}
