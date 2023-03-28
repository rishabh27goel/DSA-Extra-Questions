package AccessModifiers;

public class PrivateAccessModifier {
    public static void main(String[] args) {

        Human human = new Human();
        // Can not use private properties
        // human.age = 0;
        System.out.println("Human Height is : " + human.height);
        System.out.println("Human Weight is : " + human.weight);
    }
}

