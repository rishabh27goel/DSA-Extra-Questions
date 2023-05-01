package ObserverDesignPattern;

import ObserverDesignPattern.Listeners.EventListener;
import java.io.File;
import java.util.*;

public class EventManager {

    // Mapping for editor services to [Users / Listeners]
    Map<String, List<EventListener>> listenersMapping = new HashMap<>();

    public EventManager(String... operations){

        for(String eventType : operations){

            this.listenersMapping.put(eventType, new ArrayList<>());
        }
    }

    public void subscribe(String eventType, EventListener eventListener){

        List<EventListener> users = listenersMapping.get(eventType);
        users.add(eventListener);
    }

    public void unsubscribe(String eventType, EventListener eventListener){

        List<EventListener> users = listenersMapping.get(eventType);
        users.remove(eventListener);
    }

    // Notify all users with particular eventType
    public void notify(String eventType, File file){

        List<EventListener> users = listenersMapping.get(eventType);

        for(EventListener user : users){

            user.update(eventType, file);
        }
    }
}
