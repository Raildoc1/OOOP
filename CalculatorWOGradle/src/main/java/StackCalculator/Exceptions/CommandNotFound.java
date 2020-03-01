package StackCalculator.Exceptions;

public class CommandNotFound extends Exception {
    public CommandNotFound() { }
    CommandNotFound(String msg) { super(msg); }
}
