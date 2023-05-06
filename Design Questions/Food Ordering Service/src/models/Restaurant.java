package models;

import java.util.List;

public class Restaurant {

    private int restaurantId;
    private String restaurantName;
    private String restaurantFoodItemName;
    private int restaurantFoodItemPrice;
    private int restaurantInitialQuantity;
    private float restaurantOverallRating;
    private List<long> restaurantServiceablePincodes;
    private List<Review> restaurantReviews;
}
