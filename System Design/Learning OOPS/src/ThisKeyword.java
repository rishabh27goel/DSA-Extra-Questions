public class ThisKeyword {
    public static void main(String []args){

        Vehicle vehicle = new Vehicle();
    }
}

class Vehicle
{
    int age;
    Vehicle(){

        this(8);
        System.out.println("First Constructor !!");
    }

    Vehicle(int age){

        this.age = age;
        System.out.println("Second Constructor !!");
        this.printAge();
    }

    public void printAge(){

        System.out.println("Age is : " + this.age);
    }


}