package StackCalculator;

import StackCalculator.Exceptions.*;
import org.junit.Before;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.InvocationTargetException;

import static org.junit.Assert.*;

public class CalculatorTest {

    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();

    @Before
    public void setUpStreams() {
        System.setOut(new PrintStream(outContent));
    }

    @Test
    public void executeCommands() {
        Calculator calculator = new Calculator();
        try {
            calculator.ExecuteCommands("in.txt", "cfg.txt");
            assertEquals(new Double(2.0), Double.valueOf(outContent.toString()));
        } catch (IOException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (WrongConfigFileFormat wrongConfigFileFormat) {
            wrongConfigFileFormat.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (CommandNotFound commandNotFound) {
            commandNotFound.printStackTrace();
        } catch (WrongAmountOfArguments wrongAmountOfArguments) {
            wrongAmountOfArguments.printStackTrace();
        } catch (UndefinedVariable undefinedVariable) {
            undefinedVariable.printStackTrace();
        } catch (VarNameHasAlreadyExist varNameHasAlreadyExist) {
            varNameHasAlreadyExist.printStackTrace();
        }
    }
}