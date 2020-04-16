package ru.ugame.objects;

import ru.ugame.core.DefaultBehaviour;
import ru.ugame.core.GameObject;
import ru.ugame.math.Vector2;

import java.util.*;

public class Board {

    private static final boolean DEBUG_MODE = true;

    private Timer timer;
    private TimerTask timerTask;

    private int width = 10;
    private int height = 10;

    private int frameCounter = 0;
    private int deltaTimeMillis;
    private int targetFPS = 30;
    private int delayMillis = 500;

    private GameObject[][] board = new GameObject[width][height];
    private List<DefaultBehaviour> defaultBehaviours;

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
        Random random = new Random();
        Vector2 headPosition = new Vector2(random.nextInt(4) + 3, random.nextInt(4) + 3);
        defaultBehaviours = new ArrayList<DefaultBehaviour>();
        Head head = new Head(headPosition);
    }

    private void update() {
        frameCounter++;
        if(DEBUG_MODE) System.out.println(frameCounter);
        for (DefaultBehaviour dBeh : defaultBehaviours) {
            dBeh.update();
        }
    }
}
