package ChainOfResponsibilityDesignPattern.Logger;

public class DebugLogger extends Logger{

    public DebugLogger(int level){

        this.level = level;
    }

    @Override
    public void displayLogInfo(String message) {

        System.out.println("Debug Logger : " + message);
    }
}
