package ru.ugame.math;

public class Vector2 {
    public int x = 0;
    public int y = 0;

    public void addVec(Vector2 v) {
        x += v.x;
        y += v.y;
    }

    public Vector2(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + " " + y +  ")";
    }
}
