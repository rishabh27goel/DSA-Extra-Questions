package ChainOfResponsibilityDesignPattern.Logger;

public class ConsoleLogger extends Logger{

    public ConsoleLogger(int level){

        this.level = level;
    }

    @Override
    public void displayLogInfo(String message) {

        System.out.println("Console Logger : " + message);
    }
}
