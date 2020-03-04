package Core;

import javax.swing.*;
import java.awt.*;

public class Game extends JFrame {

    private final String APP_NAME = "Game";

    private int WIN_WIDTH = 300;
    private int WIN_HEIGHT = 300;

    public Game () {
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
