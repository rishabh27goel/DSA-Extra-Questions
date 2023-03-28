public class Main {
    public static void main(String []args){

        // Creating Human Object
        Human human = new Human();
        Human paraHuman = new Human(5, 6);
        human.age = 20;
        human.weight = 70;

        System.out.println("Human Age is : " + human.age);
        System.out.println("Human Weight is : " + human.weight + "kg");

        human.sleep();
        human.eating();
    }
}

class Human {

    // Properties / Data Members
    int age;
    int weight;

    // Constructor
    // No-args Constructor
    public Human(){

        System.out.println("I am Human Constructor with no parameters !!");
        System.out.println(this);
    }

    // Parameterized Constructor
    public Human(int a, int b){

        System.out.println("I am Human Constructor with some parameters !!");
        System.out.println("Values : " + a + " " + b);
        System.out.println(this);
    }

    // Behaviour / Function
    void sleep(){
        System.out.println("Human is Sleeping !!");
    }

    void eating(){
        System.out.println("Human is Eating !!");
    }
}