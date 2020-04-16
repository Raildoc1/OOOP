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

    public void setPosition(Vector2 position, int loop_x, int loop_y) {
        Vector2 oldPosition =  new Vector2(this.position.x, this.position.y);
        position.x = position.x % loop_x;
        position.y = position.y % loop_y;
        nextSegment.setPosition(oldPosition, loop_x, loop_y);
    }
}
