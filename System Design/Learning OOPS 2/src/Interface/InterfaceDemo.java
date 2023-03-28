package Interface;

import Interface.Square;

public class InterfaceDemo{
    public static void main(String[] args) {

        Square square = new Square(23);
        System.out.println("Area is : " + square.area());
        square.work();

        System.out.println("Shape Color is : " + Shape.color);
    }
}
