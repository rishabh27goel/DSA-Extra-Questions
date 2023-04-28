package ChainOfResponsibilityDesignPattern;

import ChainOfResponsibilityDesignPattern.Logger.ConsoleLogger;
import ChainOfResponsibilityDesignPattern.Logger.DebugLogger;
import ChainOfResponsibilityDesignPattern.Logger.ErrorLogger;
import ChainOfResponsibilityDesignPattern.Logger.Logger;

public class CORDriver {

    public static Logger doChaining(){

        // Logger Objects
        ConsoleLogger consoleLogger = new ConsoleLogger(Logger.CONSOLE);
        ErrorLogger errorLogger = new ErrorLogger(Logger.ERROR);
        DebugLogger debugLogger = new DebugLogger(Logger.DEBUG);

        // Create Chain
        consoleLogger.setNextLevelLogger(errorLogger);
        errorLogger.setNextLevelLogger(debugLogger);

        return consoleLogger;
    }

    public static void main(String[] args) {

        // Create the chain for logger
        Logger chainLogger = doChaining();

        chainLogger.logMessage(Logger.CONSOLE, "Enter your number");
        chainLogger.logMessage(Logger.DEBUG, "An error is found");
        chainLogger.logMessage(Logger.ERROR, "Debugging is required");
    }
}
