package AbstractClass;

public class Square extends Shape
{
    int side;

    Square(int side){

        this.color = "blue";
        System.out.println("Inside Square Constructor");
        this.side = side;
    }

    @Override
    public int area() {
        return side * side;
    }
}