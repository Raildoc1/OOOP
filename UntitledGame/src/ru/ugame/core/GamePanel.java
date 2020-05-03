package ru.ugame.core;

import ru.ugame.math.Vector2;
import ru.ugame.objects.Board;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GamePanel extends JPanel implements ActionListener, IUpdatable {

    private Board board;

    private boolean x_dir = true;
    private boolean y_dir = true;

    private int test_x = 0;
    private int test_y = 0;
    private int hScore = 0;
    //private Timer timer;
    private final int DELAY = 25;

    private int grid_scale;

    public GamePanel(Board board, int grid_scale) {
        this.board = board;
        setBackground(Color.BLACK);
        this.grid_scale = grid_scale;
        board.registerUpdateCallback(this);
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        if(board.isLost()) {
            g.setColor(new Color(228, 61, 56));
            g.setFont(g.getFont().deriveFont(g.getFont().getSize() * 3f));
            g.drawString("You Lost!", (board.getWidth() + 2) * grid_scale / 2 - 70, (board.getHeight() + 4) * grid_scale / 2);
            g.setFont(g.getFont().deriveFont(g.getFont().getSize() / 3f));
            g.drawString("(press any key)", (board.getWidth() + 2) * grid_scale / 2 - 50, (board.getHeight() + 4) * grid_scale / 2 + 20);
            g.setColor(new Color(57, 228, 69));
            g.drawString("Your score: " + board.snake.size(), (board.getWidth() + 2) * grid_scale / 2 - 50, (board.getHeight() + 4) * grid_scale / 2 + 40);
            hScore = hScore < board.snake.size() ? board.snake.size() : hScore;
            g.drawString("Highest: " + hScore, (board.getWidth() + 2) * grid_scale / 2 - 50, (board.getHeight() + 4) * grid_scale / 2 + 60);
            return;
        }

        g.setColor(new Color(226, 226, 226));
        g.fillRect(0,0, grid_scale*(board.getWidth() + 1), grid_scale);
        g.fillRect(0,grid_scale, grid_scale, grid_scale*(board.getHeight()));
        g.fillRect(grid_scale*(board.getWidth() + 1),0, grid_scale, grid_scale*(board.getHeight() + 2));
        g.fillRect(0,grid_scale*(board.getHeight() + 1), grid_scale*(board.getWidth() + 2), grid_scale);
        g.setColor(new Color(156, 200, 90));
        for(Vector2 v : board.snake) {
            if(v == board.snake.getFirst()) g.setColor(new Color(255, 255, 0));
            else g.setColor(new Color(156, 200, 90));
            g.fillRect((v.x + 1) * grid_scale,(v.y + 1) * grid_scale, grid_scale, grid_scale);
        }
        g.setColor(new Color(71, 210, 206));
        g.fillRect((board.foodPosition.x + 1) * grid_scale,(board.foodPosition.y + 1) * grid_scale, grid_scale, grid_scale);

        g.setColor(new Color(0, 0, 0));
        g.setFont(g.getFont().deriveFont(g.getFont().getSize() * 1.3f));
        g.drawString("Score: " + board.snake.size(), 5, 13);

        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void actionPerformed(ActionEvent e) { }

    @Override
    public void update() {
        repaint();
    }
}
