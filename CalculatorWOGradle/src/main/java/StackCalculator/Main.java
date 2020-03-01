package StackCalculator;

public class Main {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        try {
            calculator.ExecuteCommands("in.txt", "cfg.txt");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
