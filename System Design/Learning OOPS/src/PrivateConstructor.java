public class PrivateConstructor {
    public static void main(String []args){

        // Can not create an object [with private constructor]
        // Car car = new Car();
        Car.getConstructor();
        System.out.println();

        // Object Cloning
        ObjectCloning obj1 = new ObjectCloning(5, 8);
        ObjectCloning obj2 = obj1.getClone();

        System.out.println("Object 1 : " + obj1.para1);
        System.out.println("Object 1 : " + obj1.para2);
        System.out.println("Object Ref : " + obj1);

        System.out.println("Object 2 : " + obj2.para1);
        System.out.println("Object 2 : " + obj2.para2);
        System.out.println("Object Ref : " + obj2);
    }
}

class Car
{
    // Data Members
    static String color;
    int modelNumber;

    // Private Constructor
    private Car(){

        System.out.println("I am Constructor - " + this);
    }

    public static void getConstructor() {

        // Creating the object [Inside the static function]
        Car car1 = new Car();
        System.out.println(car1.color + " " + car1);

        Car.color = "red";

        // Creating the object [Inside the static function]
        Car car2 = new Car();
        System.out.println(car2.color + " " + car2);
    }
}

class ObjectCloning
{
    int para1;
    int para2;

    ObjectCloning(int para1, int para2){

        this.para1 = para1;
        this.para2 = para2;
    }

    public ObjectCloning getClone(){

        return this;
    }
}
