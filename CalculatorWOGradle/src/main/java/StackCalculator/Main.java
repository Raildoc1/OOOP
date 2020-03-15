package StackCalculator;

import StackCalculator.Command.CommandFactory;

import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

public class Main {

    private static Logger logger = Logger.getLogger(Main.class.getName());

    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        LogManager logManager = LogManager.getLogManager();
        try {
            logManager.readConfiguration(Main.class.getResourceAsStream("/resources/logging.properties"));
            calculator.ExecuteCommands("src/main/resources/in.txt");
        } catch (Exception e) {
            e.printStackTrace();
        }
        logger.log(Level.INFO, "Main executed successfully");
    }
}
