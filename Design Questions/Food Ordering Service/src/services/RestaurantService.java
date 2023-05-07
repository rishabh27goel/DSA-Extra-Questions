package services;

import dao.UserDao;

public class RestaurantService {
    private static RestaurantService instance = null;
    private RestaurantService(){

    }
    public static RestaurantService getInstance(){

        if(instance == null)
            instance = new RestaurantService();

        return instance;
    }

    // Every service needs a reference for Dao
    private UserDao userDao = UserDao.getInstance();

    public void registerRestaurant(String restaurantName, String restaurantFoodItemName, int restaurantFoodItemPrice, int restaurantInitialQuantity) throws Exception {

        if(restaurantName.isEmpty())
            throw new Exception("Restaurant name can not be empty");
        else if(restaurantFoodItemName.isEmpty())
            throw new Exception("Food item can not be empty");
        else if(restaurantFoodItemPrice <= 0)
            throw new Exception("Food price should be a non-zero positive number");
        else if(restaurantInitialQuantity <= 0)
            throw new Exception("Food initial quantity should be a non-zero positive number");

        userDao.registerRestaurant(restaurantName, restaurantFoodItemName, restaurantFoodItemPrice, restaurantInitialQuantity);
    }

    public void updateQuantity(String restaurantName, int quantityAddition) throws Exception {

        if(restaurantName.isEmpty())
            throw new Exception("Restaurant name can not be empty");

        userDao.updateQuantity(restaurantName, quantityAddition);
    }

    public void rateRestaurant(String restaurantName, int rating, String comment) throws Exception {

        if(restaurantName.isEmpty())
            throw new Exception("Restaurant name can not be empty");
        else if(rating < 1 || rating > 5)
            throw new Exception("Rating should be between 1 to 5");

        userDao.rateRestaurant(restaurantName, rating, comment);
    }

    public void showRestaurant(String sortBy) throws Exception {

        if(!sortBy.equalsIgnoreCase("rating") && !sortBy.equalsIgnoreCase("price"))
            throw new Exception("You can only sort by either rating or price");

        userDao.showRestaurant(sortBy);
    }
}
