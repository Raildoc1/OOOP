package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Push implements ICommand {

    String args;

    @Override
    public retValue Execute(String[] args, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(args!= null) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        double value = memory.get(this.args);
        return new retValue(value);
    }

    @Override
    public void putArgs(String args) {
        this.args = args;
    }

    @Override
    public int GetArgumentsAmount() {
        return 0;
    }
}
