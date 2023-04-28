package ChainOfResponsibilityDesignPattern.Logger;

public abstract class Logger {

    public static int CONSOLE = 1;
    public static int ERROR = 2;
    public static int DEBUG = 3;


    // Every class which inherits this class should have below data members
    protected Logger nextLevelLogger;
    protected int level;


    // For creating chain of object
    public void setNextLevelLogger(Logger nextLevelLogger){

        this.nextLevelLogger = nextLevelLogger;
    }

    // Reach the target logger
    public void logMessage(int level, String message){

        if(this.level <= level){

            this.displayLogInfo(message);
        }

        if(this.nextLevelLogger != null){

            this.nextLevelLogger.logMessage(level, message);
        }
    }

    protected abstract void displayLogInfo(String message);
}
