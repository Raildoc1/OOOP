package ru.ugame.objects;

import ru.ugame.core.IUpdatable;
import ru.ugame.math.Vector2;

import java.util.*;

public class Board {

    private static final boolean DEBUG_MODE = false;

    private ArrayList<IUpdatable> toUpdate;

    private Timer timer;
    private TimerTask timerTask;

    private int width = 20;
    private int height = 15;

    private int frameCounter = 0;
    private int deltaTimeMillis;
    private int targetFPS = 5;
    private int delayMillis = 500;

    private Vector2 direction;
    public Vector2 foodPosition;
    private Vector2 newSegment;
    private boolean newSegmentInstantiated = false;
    private boolean lost = false;
    private boolean lockMovement = false;

    public boolean isLost() {
        return lost;
    }

    public Deque<Vector2> snake;

    public void start() {

        init();

        timer = new Timer();
        timerTask = new TimerTask() {
            @Override
            public void run() {
                update();
            }
        };

        deltaTimeMillis = 1000/targetFPS;
        timer.schedule(timerTask, delayMillis, deltaTimeMillis);
    }

    private void init() {
        lost = false;
        Random random = new Random();
        Vector2 headPosition = new Vector2(random.nextInt(4) + 3, random.nextInt(4) + 3);
        foodPosition = new Vector2(random.nextInt(4) + 3, random.nextInt(4) + 3);
        snake = new ArrayDeque<Vector2>();
        snake.add(headPosition);
        direction = new Vector2(0, 1);
    }

    private void update() {
        frameCounter++;
        if(toUpdate != null) {
            for(IUpdatable updatable : toUpdate){
                updatable.update();
            }
        }
        if(lost)return;
        if(DEBUG_MODE) System.out.println(frameCounter);
        for (Vector2 v : snake) {
            if(v.x == foodPosition.x && v.y == foodPosition.y) eatFood();
        }
        newSegmentInstantiated = true;
        for (Vector2 v : snake) {
            //v.addVec(direction);
            //if(v.x < 0) v.x += width;
            //if(v.y < 0) v.y += height;
            //v.x %= width;
            //v.y %= height;
            if(snake.getFirst().x == v.x && snake.getFirst().y == v.y && v != snake.getFirst()) {lost = true; return;}
            if(newSegment != null) {
                if(newSegment.x == v.x && newSegment.y == v.y) newSegmentInstantiated = false;
            }
        }

        if(newSegment != null) {
            if(newSegmentInstantiated){
                Vector2 tempSeg = new Vector2(newSegment.x, newSegment.y);
                snake.add(tempSeg);
                newSegment = null;
                newSegmentInstantiated = false;
            }
        }

        Vector2 head = snake.getFirst();
        Vector2 temp = new Vector2((head.x + direction.x + width) % width, (head.y + direction.y + height) % height);
        snake.addFirst(temp);
        snake.removeLast();

        lockMovement = false;

        if(DEBUG_MODE) {
            for (Vector2 v : snake) {
                System.out.println(v.toString());
            }
        }
    }

    public void changeDirection(int x, int y) {
        if(lockMovement) return;
        if(direction.x == -x && direction.y == -y) return;
        direction.x = x;
        direction.y = y;
        lockMovement = true;
    }

    private void eatFood() {
        newSegment = foodPosition;
        Random random = new Random();
        foodPosition = new Vector2(random.nextInt(width), random.nextInt(height));
    }

    public void registerUpdateCallback(IUpdatable updatable) {
        if (toUpdate == null) toUpdate = new ArrayList<IUpdatable>();
        toUpdate.add(updatable);
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public void restart() {
        init();
    }
}
