package StackCalculator;

import StackCalculator.Command.CommandFactory;
import StackCalculator.Command.ICommand;
import StackCalculator.Exceptions.CommandNotFound;
import StackCalculator.Exceptions.WrongConfigFileFormat;

import java.io.*;
import java.lang.reflect.InvocationTargetException;

public class CommandStream {

    private BufferedReader reader;

    public CommandStream() throws NoSuchMethodException, IOException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        reader = new BufferedReader(new InputStreamReader(System.in));
    }

    public CommandStream(String fileName) throws IOException, NoSuchMethodException, WrongConfigFileFormat, InstantiationException, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        reader = new BufferedReader(new FileReader(fileName));
    }

    public ICommand NextCommand() throws IOException, CommandNotFound, NoSuchMethodException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        String line;
        if((line = reader.readLine()) == null) return null;
        String[] tmp = CommandFileParser.split(line);
        if(tmp.length == 1)
            return CommandFactory.getInstance().CreateCommand(tmp[0], null);
        else
            return CommandFactory.getInstance().CreateCommand(tmp[0], tmp[1]);
    }

    public void Close() throws IOException {
        reader.close();
    }

}
