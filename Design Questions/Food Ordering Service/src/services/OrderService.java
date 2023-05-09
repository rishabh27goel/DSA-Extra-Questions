package services;

import dao.UserDao;

public class OrderService {
    private static OrderService instance = null;
    private OrderService(){

    }
    public static OrderService getInstance(){

        if(instance == null)
            instance = new OrderService();

        return instance;
    }

    // Every service needs a reference for Dao
    private UserDao userDao = UserDao.getInstance();


    public void placeOrder(String restaurantName, int quantity) throws Exception{

        if(restaurantName.isEmpty())
            throw new Exception("Restaurant name can not be empty");
        else if(quantity <= 0)
            throw new Exception("Food Quantity should be a non-zero positive number");

        userDao.placeOrder(restaurantName, quantity);
    }

    public void orderHistory() throws Exception{

        userDao.orderHistory();
    }
}
