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
    private List<Long> restaurantServiceablePincodes;
    private List<Review> restaurantReviews = new ArrayList<>();

    public Restaurant(){

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

    public List<Long> getRestaurantServiceablePincodes() {
        return restaurantServiceablePincodes;
    }

    public void setRestaurantServiceablePincodes(List<Long> restaurantServiceablePincodes) {
        this.restaurantServiceablePincodes = restaurantServiceablePincodes;
    }

    public List<Review> getRestaurantReviews() {
        return restaurantReviews;
    }

    public void setRestaurantReviews(List<Review> restaurantReviews) {
        this.restaurantReviews = restaurantReviews;
    }
}
