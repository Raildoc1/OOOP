package StackCalculator;

import StackCalculator.Exceptions.*;
import org.junit.Test;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

import static org.junit.Assert.*;

public class CalculatorTest {

    double actual, expected;
    double epsilon = 0.01;

    @Test
    public void ExecuteCommands() throws IOException, InstantiationException, InvocationTargetException, NoSuchMethodException, UndefinedVariable, IllegalAccessException, VarNameHasAlreadyExist, WrongAmountOfArguments, ClassNotFoundException, CommandNotFound, WrongConfigFileFormat {

        Calculator calculator = new Calculator();

        calculator.ExecuteCommands("in.txt", "cfg.txt");
        actual = calculator.getStackTop();
        expected = 2.0;

        assertTrue(Math.abs(actual - epsilon) < epsilon);

        calculator.ExecuteCommands("in1.txt", "cfg.txt");
        actual = calculator.getStackTop();
        expected = 28.4632;

        assertTrue(Math.abs(actual - epsilon) < epsilon);
    }

}