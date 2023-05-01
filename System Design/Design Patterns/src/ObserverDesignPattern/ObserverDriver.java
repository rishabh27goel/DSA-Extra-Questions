package ObserverDesignPattern;

import ObserverDesignPattern.Listeners.EmailEventListener;
import ObserverDesignPattern.Listeners.LogEventListener;

public class ObserverDriver {
    public static void main(String[] args) {

        // Create Editor
        Editor editor = new Editor();

        editor.getEvents().subscribe("open", new LogEventListener("/path/to/log/file.txt"));
        editor.getEvents().subscribe("save", new LogEventListener("/path/to/log/file.txt"));
        editor.getEvents().subscribe("open", new EmailEventListener("email@abc.com"));

        try {

            editor.openFile("coding.txt");
            editor.saveFile();
        }
        catch (Exception e){

            e.printStackTrace();
        }
    }
}
