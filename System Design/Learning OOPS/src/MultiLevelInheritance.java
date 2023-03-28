public class MultiLevelInheritance {

    public static void main(String[] args){

        Scorpio scorpio = new Scorpio();
        scorpio.getModelNumber();
        scorpio.run();
        scorpio.brake();
    }
}

class Scorpio extends Mahindra
{

}

class Mahindra extends CarParent
{
    String modelNumber;

    Mahindra(){
        this.modelNumber = "12345";
    }

    void getModelNumber(){
        System.out.println("Mahindra model number is : " + modelNumber);
    }
}

class CarParent
{
    String color;
    int weight;

    CarParent(){
        this.color = "red";
        this.weight = 120;
    }

    void run() {
        System.out.println("A " + this.color + " color car is running !!");
    }

    void brake() {
        System.out.println("Brakes are applied to the car !!");
    }
}
