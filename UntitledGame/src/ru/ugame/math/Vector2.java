package ru.ugame.math;

public class Vector2 {
    public float x = 0f;
    public float y = 0f;

    public Vector2(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + " " + y +  ")";
    }
}
