package ObserverDesignPattern.Listeners;

public class LogEventListener implements EventListener{

    @Override
    public void update(String eventType) {

        System.out.println("Logging for event type : " + eventType);
    }
}
