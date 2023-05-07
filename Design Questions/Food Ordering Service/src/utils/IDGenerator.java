package utils;

public class IDGenerator {

    private static int orderId = 0;
    private static int restaurantId = 0;
    private static int reviewId = 0;
    private static int userId = 0;

    public static int generateId(String idType){

        final String ORDER = "order";
        final String RESTAURANT = "restaurant";
        final String REVIEW = "review";
        final String USER = "user";

        switch (idType) {

            case ORDER:
                return ++orderId;

            case RESTAURANT:
                return ++restaurantId;

            case REVIEW:
                return ++reviewId;

            case USER:
                return ++userId;

            default:
                break;
        }

        return 0;
    }
}
