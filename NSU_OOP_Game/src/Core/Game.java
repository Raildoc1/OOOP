package core;

import javax.swing.*;
import java.awt.*;

public class Game extends JFrame {

    private final String APP_NAME = "Game";

    private int WIN_WIDTH = 250;
    private int WIN_HEIGHT = 350;

    public Game () {
        initUI();
    }

    private void initUI() {
        add(new GamePanel());

        setSize(WIN_WIDTH, WIN_HEIGHT);
        setTitle(APP_NAME);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            Game game = new Game();
            game.setVisible(true);
        });
    }

}
