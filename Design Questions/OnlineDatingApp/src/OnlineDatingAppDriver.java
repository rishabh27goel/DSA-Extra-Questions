import constants.Gender;
import services.MatchServices;
import services.UserServices;

public class OnlineDatingAppDriver {
    public static void main(String[] args) {

        try {

            // Services
            UserServices userServices = UserServices.getInstance();
            MatchServices matchServices = MatchServices.getInstance();
            System.out.println("Services Created");

            // Users
            userServices.createUser("Harry", 5, 4, 27, Gender.MALE);
            userServices.createUser("Robert", 2, 7, 24, Gender.MALE);
            userServices.createUser("Chris", 1, 2, 34, Gender.MALE);

            userServices.createUser("Ana", 4, 1, 21, Gender.FEMALE);
            userServices.createUser("Emma", 3, 6, 25, Gender.FEMALE);
            userServices.createUser("Sophia", 7, 4, 28, Gender.FEMALE);


            matchServices.potentialMatch("Harry");
            matchServices.potentialMatch("Emma");

            matchServices.like("Harry", "Emma");
            matchServices.showMatches("Harry");

            matchServices.like("Emma", "Harry");
            matchServices.showMatches("Harry");
            matchServices.showMatches("Emma");

            matchServices.ignore("Harry", "Ana");
            matchServices.potentialMatch("Harry");

            matchServices.like("Ana", "Chris");
            matchServices.like("Chris", "Ana");

            matchServices.showAllMatches();

            matchServices.like("Ana", "Harry");
            matchServices.like("Harry", "Ana");

            matchServices.showAllMatches();
            matchServices.showMatches("Harry");
            matchServices.showMatches("Ana");

            userServices.deleteUser("Harry");
            matchServices.showMatches("Ana");

            matchServices.showAllMatches();
            matchServices.showMatches("Emma");

            userServices.deleteUser("Ana");
            matchServices.showAllMatches();
        }
        catch (Exception e){

            System.out.println(e.fillInStackTrace());
        }
    }
}
