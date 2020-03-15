package StackCalculator;

import StackCalculator.Command.ICommand;
import StackCalculator.Exceptions.*;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Stack;

public class Calculator {

    private Stack<Double> stack;
    private CalcMemory memory;

    public Calculator () {
        stack = new Stack<Double>();
        memory = new CalcMemory();
    }

    // Stack
    public void ExecuteCommands(String fileName) throws IOException, NoSuchMethodException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException, CommandNotFound, WrongAmountOfArguments, UndefinedVariable, VarNameHasAlreadyExist, ArithmeticException {

        CommandStream commandStream;

        ICommand command;

        if(fileName == "") {
            commandStream = new CommandStream();
        } else {
            commandStream = new CommandStream(fileName);
        }

        while((command = commandStream.NextCommand()) != null) {
            ICommand.retValue result;
            int argsAmount = command.GetArgumentsAmount();
            if(argsAmount == 0) result = command.Execute(null, memory);
            else {
                String[] args = new String[argsAmount];
                for(int i = argsAmount - 1; i >= 0; i--) {
                    args[i] = stack.pop().toString();
                }
                result = command.Execute(args, memory);
            }
            if(result.hasValue) stack.push(result.value);
        }

        commandStream.Close();
    }

    public void ExecuteCommands() throws IOException, NoSuchMethodException, CommandNotFound, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException, WrongAmountOfArguments, UndefinedVariable, VarNameHasAlreadyExist {
        ExecuteCommands("");
    }

    public double getStackTop() {
        return stack.peek();
    }
}
