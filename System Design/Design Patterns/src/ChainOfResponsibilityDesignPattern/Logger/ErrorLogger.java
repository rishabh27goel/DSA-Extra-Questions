package ChainOfResponsibilityDesignPattern.Logger;

public class ErrorLogger extends Logger {

    public ErrorLogger(int level){

        this.level = level;
    }

    @Override
    public void displayLogInfo(String message) {

        System.out.println("Error Logger : " + message);
    }
}
