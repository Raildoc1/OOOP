package core;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GamePanel extends JPanel implements ActionListener {

    private int WIN_WIDTH = 250;
    private int WIN_HEIGHT = 350;

    private boolean x_dir = true;
    private boolean y_dir = true;

    private int test_x = 0;
    private int test_y = 0;
    private Timer timer;
    private final int DELAY = 25;

    public GamePanel() {
        setBackground(Color.BLACK);
        timer = new Timer(DELAY, this);
        timer.start();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        ImageIcon img =  new ImageIcon("src/resources/Woodcutter/Woodcutter.png");
        g.drawImage(img.getImage(), test_x, test_y, this);
        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if(x_dir) {
            if(test_x > WIN_WIDTH  - 3) x_dir = !x_dir;
            test_x++;
        } else {
            if(test_x < 3) x_dir = !x_dir;
            test_x--;
        }

        if(y_dir) {
            if(test_y > WIN_HEIGHT - 3) y_dir = !y_dir;
            test_y++;
        } else {
            if(test_y < 3) y_dir = !y_dir;
            test_y--;
        }

        repaint();
    }

}
