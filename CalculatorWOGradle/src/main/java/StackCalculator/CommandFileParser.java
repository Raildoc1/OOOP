package StackCalculator;

public class CommandFileParser {
    public static String[] split(String commandLine) {
        String[] tmp = new String[2];
        tmp = commandLine.split(" ", 2);
        return tmp;
    }
}
