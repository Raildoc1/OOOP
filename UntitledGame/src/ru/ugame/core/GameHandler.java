package ru.ugame.core;

import java.util.ArrayList;
import java.util.List;

public class GameHandler {

    /*
    private static GameHandler _gameHandler;
    public static GameHandler getInstance() {
        if(_gameHandler == null) _gameHandler = new GameHandler();
        return _gameHandler;
    }
    */
    private boolean running = false;
    private int frameCount = 0;
    private List<GameObject> gameObjects;

    public GameHandler() {
        gameObjects = new ArrayList<GameObject>();
    }

    public void registerGameobject(GameObject obj) {
        gameObjects.add(obj);
    }

    public void removeGameobject(GameObject obj) {
        gameObjects.remove(obj);
    }

    public void init() {
        for (GameObject obj : gameObjects) {
            obj.awake();
        }
        for (GameObject obj : gameObjects) {
            obj.start();
        }
        running = true;
    }

    public void update() {
        frameCount++;

        if(frameCount % 15 == 0) {
            for (GameObject obj : gameObjects) {
                obj.fixedUpdate();
            }
        }

        for (GameObject obj : gameObjects) {
            obj.update();
        }

        for (GameObject obj : gameObjects) {
            obj.lateUpdate();
        }
    }

    public boolean isRunning() {
        return running;
    }

}
