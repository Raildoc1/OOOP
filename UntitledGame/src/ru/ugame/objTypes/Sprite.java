package ru.ugame.objTypes;

import ru.ugame.core.GameObject;

import javax.swing.*;

public abstract class Sprite extends GameObject {

    ImageIcon img;

    public Sprite(ImageIcon img) {
        this.img = img;
    }

    @Override
    public ImageIcon getImage() {
        return img;
    }
}
