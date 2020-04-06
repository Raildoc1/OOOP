package ru.ugame.objects;

import ru.ugame.core.GameObject;
import ru.ugame.math.Vector2;

public class SnakeSegment extends GameObject {

    private Vector2 position;
    private SnakeSegment nextSegment = null;

    public void UpdatePosition(Vector2 position) {
        nextSegment.UpdatePosition(this.position);
        this.position = position;
    }

}
