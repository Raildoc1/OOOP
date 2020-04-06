package ru.ugame.core;

import javax.swing.*;

public abstract class GameObject implements DefaultBehaviour {

    public GameObject() {
        Game.registerGameobject(this);
    }

    public ImageIcon getImage() {
        return null;
    }

    @Override
    public void awake() {}

    @Override
    public void start() {

    }

    @Override
    public void update() {}

    @Override
    public void lateUpdate() {

    }

    @Override
    public void fixedUpdate() {

    }
}
