package ru.ugame.core;

import ru.ugame.math.Vector2;
import ru.ugame.objects.Board;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GamePanel extends JPanel implements ActionListener, IUpdatable {

    private Board board;

    private int WIN_WIDTH = 250;
    private int WIN_HEIGHT = 350;

    private boolean x_dir = true;
    private boolean y_dir = true;

    private int test_x = 0;
    private int test_y = 0;
    private Timer timer;
    private final int DELAY = 25;

    private int grid_scale = 15;

    public GamePanel(Board board) {
        this.board = board;
        setBackground(Color.BLACK);
        timer = new Timer(DELAY, this);
        timer.start();
        board.registerUpdateCallback(this);
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(new Color(255, 250, 253));
        g.fillRect(0,0, grid_scale*11, grid_scale);
        g.fillRect(0,grid_scale, grid_scale, grid_scale*10);
        g.fillRect(grid_scale*11,0, grid_scale, grid_scale*12);
        g.fillRect(0,grid_scale*11, grid_scale*12, grid_scale);
        g.setColor(new Color(156, 200, 90));
        for(Vector2 v : board.snake) {
            if(v == board.snake.getFirst()) g.setColor(new Color(255, 255, 0));
            else g.setColor(new Color(156, 200, 90));
            g.fillRect((v.x + 1) * grid_scale,(v.y + 1) * grid_scale, grid_scale, grid_scale);
        }
        g.setColor(new Color(71, 210, 206));
        g.fillRect((board.foodPosition.x + 1) * grid_scale,(board.foodPosition.y + 1) * grid_scale, grid_scale, grid_scale);

        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void actionPerformed(ActionEvent e) { }

    @Override
    public void update() {
        repaint();
    }
}
