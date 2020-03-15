package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Sqrt implements ICommand {
    @Override
    public retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        if (DEV_MODE) System.out.println("sqrt(" + Double.parseDouble(values[0]) + ") = " + Math.sqrt(Double.parseDouble(values[0])));
        return new retValue(Math.sqrt(Double.parseDouble(values[0])));
    }

    @Override
    public void putArgs(String args) {

    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
