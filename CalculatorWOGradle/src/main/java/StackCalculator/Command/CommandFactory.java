package StackCalculator.Command;

import StackCalculator.ConfigParser;
import StackCalculator.Exceptions.CommandNotFound;
import StackCalculator.Exceptions.WrongConfigFileFormat;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CommandFactory implements ICommandFactory {

    private static final String CONFIG_FILE_NAME = "src/main/resources/cfg.txt";
    private static Logger logger = Logger.getLogger(CommandFactory.class.getName());

    private Map<String, ICommand> commandsList;
    private volatile static CommandFactory instance = null;

    public static CommandFactory getInstance() throws NoSuchMethodException, IOException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        if(instance == null) {
            synchronized (CommandFactory.class) {
                if(instance == null) {
                    instance = new CommandFactory();
                }
            }
        }
        return instance;
    }

    public CommandFactory() throws IOException, WrongConfigFileFormat, ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {

        commandsList = new HashMap<String, ICommand>();

        Map<String, String> tmp = ConfigParser.ConvertConfigFileToMap(CONFIG_FILE_NAME);

        for(Map.Entry<String, String> entry : tmp.entrySet()) {
            System.out.println("\'" + entry.getValue() + "\'");
            ICommand command = (ICommand)(Class.forName(entry.getValue()).getDeclaredConstructor().newInstance());
            commandsList.put(entry.getKey(), command);
        }
    }

    @Override
    public ICommand CreateCommand(String name, String parameters) throws CommandNotFound {
        ICommand command = commandsList.get(name);
        if(command == null) {
            logger.log(Level.SEVERE, "Command " + name + " not found!");
            throw new CommandNotFound("Command " + name + " not found!");
        }
        command.putArgs(parameters);
        return command;
    }
}
