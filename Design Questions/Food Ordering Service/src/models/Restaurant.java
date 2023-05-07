package models;

import java.util.ArrayList;
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

    Restaurant(int restaurantId, String restaurantName, String restaurantFoodItemName, int restaurantFoodItemPrice, int restaurantInitialQuantity, float restaurantOverallRating){

        this.restaurantId = restaurantId;
        this.restaurantName = restaurantName;
        this.restaurantFoodItemName = restaurantFoodItemName;
        this.restaurantFoodItemPrice = restaurantFoodItemPrice;
        this.restaurantInitialQuantity = restaurantInitialQuantity;
        this.restaurantOverallRating = restaurantOverallRating;
        this.restaurantServiceablePincodes = new ArrayList<long>();
        this.restaurantReviews = new ArrayList<>();
    }


    public int getRestaurantId() {
        return restaurantId;
    }

    public void setRestaurantId(int restaurantId) {
        this.restaurantId = restaurantId;
    }

    public String getRestaurantName() {
        return restaurantName;
    }

    public void setRestaurantName(String restaurantName) {
        this.restaurantName = restaurantName;
    }

    public String getRestaurantFoodItemName() {
        return restaurantFoodItemName;
    }

    public void setRestaurantFoodItemName(String restaurantFoodItemName) {
        this.restaurantFoodItemName = restaurantFoodItemName;
    }

    public int getRestaurantFoodItemPrice() {
        return restaurantFoodItemPrice;
    }

    public void setRestaurantFoodItemPrice(int restaurantFoodItemPrice) {
        this.restaurantFoodItemPrice = restaurantFoodItemPrice;
    }

    public int getRestaurantInitialQuantity() {
        return restaurantInitialQuantity;
    }

    public void setRestaurantInitialQuantity(int restaurantInitialQuantity) {
        this.restaurantInitialQuantity = restaurantInitialQuantity;
    }

    public float getRestaurantOverallRating() {
        return restaurantOverallRating;
    }

    public void setRestaurantOverallRating(float restaurantOverallRating) {
        this.restaurantOverallRating = restaurantOverallRating;
    }

    public List<long> getRestaurantServiceablePincodes() {
        return restaurantServiceablePincodes;
    }

    public void setRestaurantServiceablePincodes(List<long> restaurantServiceablePincodes) {
        this.restaurantServiceablePincodes = restaurantServiceablePincodes;
    }

    public List<Review> getRestaurantReviews() {
        return restaurantReviews;
    }

    public void setRestaurantReviews(List<Review> restaurantReviews) {
        this.restaurantReviews = restaurantReviews;
    }
}
