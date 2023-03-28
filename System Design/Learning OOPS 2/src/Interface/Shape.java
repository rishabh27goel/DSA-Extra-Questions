package Interface;

public interface Shape
{
    String color = "red";

    public abstract int area();
    public static void help(){

        System.out.println("I am helper");
    }

    public default void work(){

        System.out.println("I am working - Shape");
    }
}
