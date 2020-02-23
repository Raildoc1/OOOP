package StackCalculator;

import StackCalculator.Command.ICommand;
import StackCalculator.Exceptions.*;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Stack;

public class Calculator {

    Stack<Double> stack;

    public Calculator () {
        stack = new Stack<Double>();
    }

    // Stack
    public void ExecuteCommands(String fileName, String configFileName) throws IOException, NoSuchMethodException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException, CommandNotFound, WrongAmountOfArguments, UndefinedVariable, VarNameHasAlreadyExist {

        CommandStream commandStream;

        ICommand command;

        if(fileName == "") {
            commandStream = new CommandStream(configFileName);
        } else {
            commandStream = new CommandStream(fileName, configFileName);
        }

        while((command = commandStream.NextCommand()) != null) {
            ICommand.retValue result;
            int argsAmount = command.GetArgumentsAmount();
            if(argsAmount == 0) result = command.Execute(null);
            else {
                String[] args = new String[argsAmount];
                for(int i = argsAmount - 1; i >= 0; i--) {
                    args[i] = stack.pop().toString();
                }
                result = command.Execute(args);
            }
            if(result.hasValue) stack.push(result.value);
        }

        commandStream.Close();
    }

    public void ExecuteCommands(String configFileName) throws IOException, NoSuchMethodException, CommandNotFound, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException, WrongAmountOfArguments, UndefinedVariable, VarNameHasAlreadyExist {
        ExecuteCommands("", configFileName);
    }
}
