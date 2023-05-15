import constants.Gender;
import services.FeedServices;
import services.UserServices;

public class NewsFeedDriver {
    public static void main(String[] args) {

        try {
            UserServices userServices = UserServices.getInstance();
            FeedServices feedServices = FeedServices.getInstance();
            System.out.println("Services Created");

            userServices.signupUser("Lucious", 7983789487L, 23, Gender.MALE);
            userServices.signupUser("Albus", 236892378L, 24, Gender.MALE);
            userServices.signupUser("Tom", 846388927L, 29, Gender.MALE);

            userServices.loginUser("Tom");

            feedServices.createPost("I am going to be the darkest dark wizard of all time");
            feedServices.createPost("I am lord Voldemort btw 3:)");

            userServices.loginUser("Lucious");
            feedServices.upvotePost(1);

            userServices.followUser("Tom");
            feedServices.commentOnPost(1, "I am with you dark lord!");

            userServices.loginUser("Albus");
            feedServices.createPost("Happiness can be found, even in the darkest of times, if one only\n" +
                    "remembers to turn on the light");

            userServices.followUser("Tom");
            feedServices.downvotePost(1);
            feedServices.downvotePost(2);

            feedServices.commentOnPost(2, "LOL!");
            feedServices.showNewsFeed();
        }
        catch (Exception e){
            System.out.println(e.fillInStackTrace());
        }
    }
}