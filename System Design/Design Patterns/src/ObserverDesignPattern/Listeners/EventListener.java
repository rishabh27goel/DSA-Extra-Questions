package ObserverDesignPattern.Listeners;

import java.io.File;
import java.lang.reflect.Field;

public interface EventListener {

    public void update(String eventType, File file);
}
