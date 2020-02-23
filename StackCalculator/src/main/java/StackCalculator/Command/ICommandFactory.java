package StackCalculator.Command;

import StackCalculator.Exceptions.CommandNotFound;

public interface ICommandFactory {
    public ICommand CreateCommand(String name, String parameters) throws CommandNotFound;
}
