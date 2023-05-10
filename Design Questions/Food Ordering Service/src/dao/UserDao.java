package dao;

import constants.Gender;
import models.Order;
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
    private HashMap<Long, List<Restaurant>> serviceableRestaurantsForPincode = new HashMap<>();
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

        System.out.println("Successfully registered user ----- " );
        System.out.println("User Id : " + newUser.getUserId());
        System.out.println("Phone Number : " + newUser.getUserPhoneNumber());
        System.out.println();
    }

    public void loginUser(int userId) throws Exception {

        // If user do not exist
        if(!existedUsersMap.containsKey(userId))
            throw new Exception("User do not exist with userid " + userId);

        // If user exists
        loggedInUser = usersInfoMap.get(existedUsersMap.get(userId));

        System.out.println("Successfully logged in user with userid : " + userId);
        System.out.println();
    }


    // Restaurant Services
    public void registerRestaurant(String restaurantName, String serviceablePincodes, String restaurantFoodItemName, int restaurantFoodItemPrice, int restaurantInitialQuantity) throws Exception {

        // If restaurant exists
        if(restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant already exists with restaurant name " + restaurantName);

        // If no restaurant is present -> create a new restaurant
        List<String> pincodesStringList = Arrays.asList(serviceablePincodes.split("/"));

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

        // For each pincode adding the restaurant object
        for(Long pincode : pincodesList){

            if(!serviceableRestaurantsForPincode.containsKey(pincode))
                serviceableRestaurantsForPincode.put(pincode, new ArrayList<>());

            serviceableRestaurantsForPincode.get(pincode).add(newRestaurant);
        }

        System.out.println("Successfully registered restaurant with name " + restaurantName);
    }

    public void updateQuantity(String restaurantName, int quantityAddition) throws Exception{

        // If restaurant do not exist
        if(!restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant do not exist with restaurant name " + restaurantName);


        // Update initial quantity of the restaurant
        Restaurant restaurant = restaurantsInfoMap.get(restaurantName);
        restaurant.setRestaurantInitialQuantity(restaurant.getRestaurantInitialQuantity() + quantityAddition);

        System.out.println("Food quantity updated to " + restaurant.getRestaurantInitialQuantity() + " for " + restaurantName);
        System.out.println();
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

        System.out.println("Review Summary ---- : ");
        System.out.println("Review Id : " + review.getReviewId());
        System.out.println("Rating : " + review.getReviewRating());
        System.out.println("Comment  : " + review.getReviewComment());
        System.out.println();
    }

    public void showRestaurant(String sortBy) throws Exception {

        // Show restaurant by either rating or price sort for current user
//        List<Restaurant> serviceableRestaurants = new ArrayList<>();

//        for(String restaurantName : restaurantsInfoMap.keySet()){
//
//            for(Long pincode : restaurantsInfoMap.get(restaurantName).getRestaurantServiceablePincodes()){
//
//                if(pincode.equals(loggedInUser.getUserPincode())){
//
//                    serviceableRestaurants.add(restaurantsInfoMap.get(restaurantName));
//                    break;
//                }
//            }
//        }

        if(!serviceableRestaurantsForPincode.containsKey(loggedInUser.getUserPincode()))
            throw new Exception("No serviceable restaurant exists");


        List<Restaurant> serviceableRestaurants = serviceableRestaurantsForPincode.get(loggedInUser.getUserPincode());

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
    public void placeOrder(String restaurantName, int quantity) throws Exception {

        // If restaurant do not exist
        if (!restaurantsInfoMap.containsKey(restaurantName))
            throw new Exception("Restaurant do not exist with restaurant name " + restaurantName);


        // If restaurant exists
        Restaurant restaurant = restaurantsInfoMap.get(restaurantName);

        // If restaurant does not deliver to users pincode
        if(!restaurant.getRestaurantServiceablePincodes().contains(loggedInUser.getUserPincode()))
            throw new Exception("Cannot place order -> Requested restaurant does not deliver to users pincode");


        // Not enough quantity
        if (restaurant.getRestaurantInitialQuantity() < quantity)
            throw new Exception("Cannot place order -> Restaurant do have requested food quantity");


        // Create the order
        Order order = new Order();
        order.setOrderId(IDGenerator.generateId("order"));
        order.setUserId(loggedInUser.getUserId());
        order.setRestaurantId(restaurant.getRestaurantId());
        order.setItemName(restaurant.getRestaurantFoodItemName());
        order.setItemPrice(restaurant.getRestaurantFoodItemPrice());
        order.setItemQuantity(restaurant.getRestaurantInitialQuantity());
        order.setTotalCost(Long.valueOf(quantity) * Long.valueOf(restaurant.getRestaurantFoodItemPrice()));

        // Update restaurant quantity
        restaurant.setRestaurantInitialQuantity(restaurant.getRestaurantInitialQuantity() - quantity);

        // Adding order to the users history
        loggedInUser.getUserOrderHistory().add(order);

        System.out.println("Order placed successfully");
        System.out.println("Order Id : " + order.getOrderId());
        System.out.println("Food Item Name : " + order.getItemName());
        System.out.println("Food Item Price : " + order.getItemPrice());
        System.out.println("Total Cost : " + order.getTotalCost());
        System.out.println();
    }

    public void orderHistory() throws Exception {

        if (loggedInUser == null)
            throw new Exception("No user is currently logged in");

        if (loggedInUser.getUserOrderHistory().isEmpty())
            throw new Exception("No orders yet for user id " + loggedInUser.getUserId());


        System.out.println("Order History : ");

        for(Order order : loggedInUser.getUserOrderHistory()){

            System.out.println("Order Id : " + order.getOrderId());
            System.out.println("Food Item Name : " + order.getItemName());
            System.out.println("Food Item Price : " + order.getItemPrice());
            System.out.println("Total Cost : " + order.getTotalCost());
        }

        System.out.println();
    }

    // Other Util
    class SortByPrice implements Comparator<Restaurant> {
        public int compare(Restaurant a, Restaurant b) {

            return b.getRestaurantFoodItemPrice() - a.getRestaurantFoodItemPrice();
        }
    }
    class SortByRating implements Comparator<Restaurant> {
        public int compare(Restaurant a, Restaurant b) {

            if(a.getRestaurantOverallRating() > b.getRestaurantOverallRating())
                return -1;
            else if(a.getRestaurantOverallRating() < b.getRestaurantOverallRating())
                return 1;
            else
                return 0;
        }
    }
}
