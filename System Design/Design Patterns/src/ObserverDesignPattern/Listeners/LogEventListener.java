package ObserverDesignPattern.Listeners;

import java.io.File;

public class LogEventListener implements EventListener{

    private File log;

    public LogEventListener(String fileName){

        this.log = new File(fileName);
    }

    @Override
    public void update(String eventType, File file) {

        System.out.println("Save to Log " + log + " : Someone has performed " + eventType + " operation on file " + file.getName());
    }
}
