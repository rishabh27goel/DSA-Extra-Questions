package SingletonDesignPattern;

public class Singleton {

    // Data Members
    private static Singleton instance = null;

    // Constructor
    private Singleton() {

    }

    public static Singleton getInstance(){

        // If instance is created
        // Object of the class can only be created once and from inside of the class only [Due to private constructor]
        if(instance == null)
            instance = new Singleton();

        return instance;
    }

    // Normal Function
    public void sayHello(){

        System.out.println("I am Hello Function" + this);
    }
}
