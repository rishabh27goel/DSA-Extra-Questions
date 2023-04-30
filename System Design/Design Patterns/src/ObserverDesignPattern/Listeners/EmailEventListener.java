package ObserverDesignPattern.Listeners;

public class EmailEventListener implements EventListener{

    @Override
    public void update(String eventType) {

        System.out.println("Email for event type : " + eventType);
    }
}
