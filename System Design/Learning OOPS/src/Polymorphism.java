public class Polymorphism {
    public static void main(String[] args) {

        // Main method overloading
        System.out.println("Original Main Method");
        main(null, 345);

        System.out.println("Method Overloading");
        MethodOverloading methodOverloading = new MethodOverloading();
        methodOverloading.speak();
        methodOverloading.speak(6);
        methodOverloading.speak(7f);
        methodOverloading.speak(6, 5);
        MethodOverloading.help();
        MethodOverloading.help(10);
        System.out.println();

        System.out.println("Method Overriding");
        Animal animal = new Animal();
        animal.speak();

        Dog dog = new Dog();
        dog.speak();

        Cat cat = new Cat();
        cat.speak();
    }
    public static void main(String[] args, int abc){

        System.out.println("2 Parameter Main Method \n");
    }
}

// Method Overloading
class MethodOverloading
{
    void speak(){
        System.out.println("No Parameter");
    }

    static void help(){
        System.out.println("Static Member 1");
    }

    static void help(int a){
        System.out.println("Static Member 2");
    }

    // It will not work if we only change the return type
    // Number of args or type should be changed

    void speak(int a){
        System.out.println("One Parameter - Integer");
    }

    void speak(float a){
        System.out.println("One Parameter - Float");
    }

    void speak(int a, float b){
        System.out.println("Two Parameter");
    }
}

// Method Overriding
class Animal
{
    void speak() {
        System.out.println("Animal Sound !!");
    }
}

class Dog extends Animal
{
    void speak() {
        System.out.println("Woof !!");
    }
}

class Cat extends Animal
{
    void speak() {
        System.out.println("Meow !!");
    }
}