package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Print implements ICommand {
    @Override
    public retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        System.out.println(values[0]);
        return new retValue(Double.parseDouble(values[0]));
    }

    @Override
    public void putArgs(String args) {

    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
