package StackCalculator;

import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;

import java.util.HashMap;
import java.util.Map;

public class CalcMemory {

    private Map<String, Double> memory;

    public static CalcMemory instance;

    public static CalcMemory getInstance() {
        if(instance == null) instance = new CalcMemory();
        return instance;
    }

    private CalcMemory() {
        memory = new HashMap<String, Double>();
    }

    public void put(String name, double value) throws VarNameHasAlreadyExist {
        if(memory.get(name) != null) throw new VarNameHasAlreadyExist(name);
        memory.put(name, value);
    }

    public double get(String name) throws UndefinedVariable {
        if(memory.get(name) == null) throw new UndefinedVariable(name);
        return memory.get(name);
    }
}
