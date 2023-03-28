package AccessHelper;
import AccessModifiers.Human;

public class DefaultAccessModifier {
    public static void main(String[] args) {

        Human human = new Human();
        // Can not access outside the package in default access modifier
        human.height = 110;
    }
}
