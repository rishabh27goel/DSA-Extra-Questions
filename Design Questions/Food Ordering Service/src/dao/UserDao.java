package dao;

import constants.Gender;
import models.Restaurant;
import models.User;

import java.util.HashMap;
import java.util.Map;

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
    private HashMap<Integer, User> usersInfoMap = new HashMap<>();
    private HashMap<Long, Integer> phoneNumbersMap = new HashMap<>();
    private HashMap<String, Restaurant> restaurantsInfoMap = new HashMap<>();
    private User loggedInUser = null;


    // User Services
    public void registerUser(String userName, Gender userGender, Long userPhoneNumber, Long userPincode){

    }

    public void loginUser(int userId){

    }


    // Restaurant Services
    public void registerRestaurant(String restaurantName, String restaurantFoodItemName, int restaurantFoodItemPrice, int restaurantInitialQuantity){

    }

    public void updateQuantity(String restaurantName, int quantityAddition){


    }

    public void rateRestaurant(String restaurantName, int rating, String comment){


    }

    public void showRestaurant(String sortBy){


    }


    // Order Services
    public void placeOrder(String restaurantName, int quantity){


    }

    public void orderHistory(int userId){


    }
}
