package AccessHelper;
import AccessModifiers.Human;
import AccessModifiers.PrivateAccessModifier;

public class ProtectedAccessModifier extends Human {

    ProtectedAccessModifier(){

        System.out.println("Constructor of Protected !!");
    }

    public static void main(String[] args) {

        ProtectedAccessModifier human = new ProtectedAccessModifier();
        System.out.println("Human Weight is : " + human.weight);
    }
}
