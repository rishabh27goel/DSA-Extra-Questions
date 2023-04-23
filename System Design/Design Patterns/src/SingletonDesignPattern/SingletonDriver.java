package SingletonDesignPattern;

public class SingletonDriver {
    public static void main(String[] args) {

        // Create an object of the Singleton class
        Singleton object1 = Singleton.getInstance();
        System.out.println("Instance 1 : " + object1);
        object1.sayHello();

        Singleton object2 = Singleton.getInstance();
        System.out.println("Instance 2 : " + object1);
        object2.sayHello();
    }
}
