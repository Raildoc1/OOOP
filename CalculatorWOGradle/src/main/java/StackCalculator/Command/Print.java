package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Print implements ICommand {
    @Override
    public retValue Execute(String[] args, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        System.out.println(args[0]);
        return new retValue(Double.parseDouble(args[0]));
    }

    @Override
    public void putArgs(String args) {

    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
