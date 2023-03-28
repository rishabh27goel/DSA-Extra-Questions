package AbstractClass;

abstract class Shape
{
    String color;

    Shape(){

        System.out.println("Abstract Constructor");
    }

    public abstract int area();
}