package dao;

import constants.Gender;
import models.Restaurant;
import models.Review;
import models.User;
import utils.IDGenerator;

import java.util.*;

public class UserDao {

    private static UserDao instance = null;
    private UserDao(){

    }
    public static UserDao getInstance(){

        if(instance == null)
            instance = new UserDao();

        return instance;
    }


    // In-Memory Store
    private HashMap<Integer, Long> existedUsersMap = new HashMap<Integer, Long>();
    private HashMap<Long, User> usersInfoMap = new HashMap<>();
    private HashMap<String, Restaurant> restaurantsInfoMap = new HashMap<>();
    private User loggedInUser = null;


    // User Services
    public void registerUser(String userName, Gender userGender, Long userPhoneNumber, Long userPincode) throws Exception{

        // If user exists
        if(usersInfoMap.containsKey(userPhoneNumber))
            throw new Exception("User already exists with phone number " + userPhoneNumber);

        // If no user is present -> create a new user
        User newUser = new User(IDGenerator.generateId("user"), userName, userGender, userPhoneNumber, userPincode);

        usersInfoMap.put(userPhoneNumber, newUser);
        existedUsersMap.put(newUser.getUserId(), userPhoneNumber);

        loggedInUser = newUser;

        System.out.println("Successfully registered user and logged in ------ " );
        System.out.println("User Id : " + newUser.getUserId());
        System.out.println("Phone Number : " + newUser.getUserPhoneNumber());
    }

    public void loginUser(int userId) throws Exception {

        // If user do not exist
        if(!existedUsersMap.containsKey(userId))
            throw new Exception("User do not exist with userid " + userId);

        // If user exists
        loggedInUser = usersInfoMap.get(existedUsersMap.get(userId));

        System.out.println("Successfully logged in user with userid : " + userId);
    }


    // Restaurant Services
    public void registerRestaurant(String restaurantName, String serviceablePincodes, String restaurantFoodItemName, int restaurantFoodItemPrice, int restaurantInitialQuantity) throws Exception {

        // If there is no user logged in
        if(loggedInUser == null)
            throw new Exception("No user logged in - either login / register");

        // If restaurant exists
        if(restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant already exists with restaurant name " + restaurantName);

        // If no restaurant is present -> create a new restaurant
        List<String> pincodesStringList = Arrays.asList(serviceablePincodes.split(","));

        if(pincodesStringList.isEmpty())
            throw new Exception("List of serviceable pincodes is empty");


        List<Long> pincodesList = new ArrayList<>();

        for(String pincode : pincodesStringList){

            for(int i=0; i<pincode.length(); i++){

                if(pincode.charAt(i) < '0' || pincode.charAt(i) > '9')
                    throw new Exception("Serviceable pincodes are not valid");
            }

            pincodesList.add(Long.parseLong(pincode));
        }

        // Builder Pattern
        Restaurant newRestaurant = new Restaurant();
        newRestaurant.setRestaurantId(IDGenerator.generateId("restaurant"));
        newRestaurant.setRestaurantName(restaurantName);
        newRestaurant.setRestaurantServiceablePincodes(pincodesList);
        newRestaurant.setRestaurantFoodItemName(restaurantFoodItemName);
        newRestaurant.setRestaurantFoodItemPrice(restaurantFoodItemPrice);
        newRestaurant.setRestaurantInitialQuantity(restaurantInitialQuantity);
        newRestaurant.setRestaurantOverallRating(0.0f);

        restaurantsInfoMap.put(restaurantName, newRestaurant);
        loggedInUser.getUserRestaurantList().add(newRestaurant);

        System.out.println("Successfully registered restaurant with name " + restaurantName);
    }

    public void updateQuantity(String restaurantName, int quantityAddition) throws Exception{

        // If restaurant do not exist
        if(!restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant do not exist with restaurant name " + restaurantName);


        // Update initial quantity of the restaurant
        Restaurant restaurant = restaurantsInfoMap.get(restaurantName);
        restaurant.setRestaurantInitialQuantity(restaurant.getRestaurantInitialQuantity() + quantityAddition);
    }

    public void rateRestaurant(String restaurantName, int rating, String comment) throws Exception{

        // If restaurant do not exist
        if(!restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant do not exist with restaurant name " + restaurantName);


        // If restaurant exists
        Restaurant restaurant = restaurantsInfoMap.get(restaurantName);
        Review review = new Review(IDGenerator.generateId("review"), rating, comment);

        // Added review to the review list of restaurant
        restaurant.getRestaurantReviews().add(review);

        // Updated overall rating
        float overallRating = restaurant.getRestaurantOverallRating();
        int currentSize = restaurant.getRestaurantReviews().size();

        overallRating = ((overallRating * Float.valueOf(currentSize-1)) + Float.valueOf(rating)) / Float.valueOf(currentSize);
        restaurant.setRestaurantOverallRating(overallRating);
    }

    public void showRestaurant(String sortBy){

        // Show restaurant by either rating or price for current logged-in user
        List<Restaurant> restaurantList = loggedInUser.getUserRestaurantList();
        List<Restaurant> serviceableRestaurants = new ArrayList<>();

        for(Restaurant restaurant : restaurantList){

            if(restaurant.getRestaurantServiceablePincodes().contains(loggedInUser.getUserPincode()) && restaurant.getRestaurantInitialQuantity() > 0){

                serviceableRestaurants.add(restaurant);
            }
        }

        // Sort by Rating
        if(sortBy.equalsIgnoreCase("rating")){

            Collections.sort(serviceableRestaurants, new SortByRating());
            System.out.println("Restaurant List : ");

            for(Restaurant restaurant : serviceableRestaurants){

                System.out.println("Restaurant Name : " + restaurant.getRestaurantName());
                System.out.println("Food Item Name : " + restaurant.getRestaurantFoodItemName());
                System.out.println("Food Item Price : " + restaurant.getRestaurantFoodItemPrice());
            }
        }

        // Sort by Price
        if(sortBy.equalsIgnoreCase("price")){

            Collections.sort(serviceableRestaurants, new SortByPrice());
            System.out.println("Restaurant List : ");

            for(Restaurant restaurant : serviceableRestaurants){

                System.out.println("Restaurant Name : " + restaurant.getRestaurantName());
                System.out.println("Food Item Name : " + restaurant.getRestaurantFoodItemName());
                System.out.println("Food Item Price : " + restaurant.getRestaurantFoodItemPrice());
            }
        }
    }


    // Order Services
    public void placeOrder(String restaurantName, int quantity) throws Exception{

        // If restaurant do not exist
        if(!restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant do not exist with restaurant name " + restaurantName);
    }

    public void orderHistory(int userId){


    }

    // Other Util Services
    class SortByPrice implements Comparator<Restaurant> {
        public int compare(Restaurant a, Restaurant b) {

            return a.getRestaurantFoodItemPrice() - b.getRestaurantFoodItemPrice();
        }
    }
    class SortByRating implements Comparator<Restaurant> {
        public int compare(Restaurant a, Restaurant b) {

            if(a.getRestaurantOverallRating() > b.getRestaurantOverallRating())
                return 1;
            else if(a.getRestaurantOverallRating() < b.getRestaurantOverallRating())
                return -1;
            else
                return 0;
        }
    }
}
