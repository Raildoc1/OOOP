package ru.ugame.objects;

import ru.ugame.core.GameObject;
import ru.ugame.core.Input;
import ru.ugame.math.Vector2;

import java.awt.event.KeyEvent;

public class Head extends GameObject {

    private Vector2 position;
    private Vector2 direction;
    private SnakeSegment nextSegment;

    private int loop_x = 10;
    private int loop_y = 10;

    public Head(Vector2 position) {
        super();
        this.position = position;
        direction = new Vector2(0, 1);
    }

    public Head(Vector2 position, int loop_x, int loop_y) {
        super();
        this.position = position;
        this.loop_x = loop_x > 0 ? loop_x : 10;
        this.loop_y = loop_y > 0 ? loop_y : 10;
        direction = new Vector2(0, 1);
    }

    /*
    @Override
    public void update() {

        if(Input.getKeyPressed() == KeyEvent.VK_W) {
            direction = new Vector2(0, 1);
        } else
        if(Input.getKeyPressed() == KeyEvent.VK_S) {
            direction = new Vector2(0, -1);
        } else
        if(Input.getKeyPressed() == KeyEvent.VK_D) {
            direction = new Vector2(1, 0);
        } else
        if(Input.getKeyPressed() == KeyEvent.VK_A) {
            direction = new Vector2(-1, 0);
        }

        position = new Vector2((position.x + direction.x) % loop_x, (position.y + direction.y) % loop_y);

        System.out.println(direction);
    }
*/
    public void setPosition(int x, int y) {
        Vector2 oldPosition =  new Vector2(position.x, position.y);
        position.x = x % loop_x;
        position.y = y % loop_y;
        nextSegment.setPosition(oldPosition, loop_x, loop_y);
    }
}
