import constants.Gender;
import models.Order;
import models.User;
import services.OrderService;
import services.RestaurantService;
import services.UserService;

public class FoodOrderingServiceDriver {
    public static void main(String[] args) {

        try {
            System.out.println("Execution Started : ");

            UserService userService = UserService.getInstance();
            OrderService orderService = OrderService.getInstance();
            RestaurantService restaurantService = RestaurantService.getInstance();

            System.out.println("Services Created");

            // Test Case 1
            userService.registerUser("Pralove", Gender.male, 478738932L, 3439L);
            userService.registerUser("Nitesh", Gender.male, 983658895L, 9384L);
            userService.registerUser("Nitesh", Gender.male, 846384834L, 9384L);


            userService.loginUser(1);
            restaurantService.registerRestaurant("Food Court 1", "3439/9384", "NI Thali", 100, 5);
            restaurantService.registerRestaurant("Food Court 2", "9384", "Burger", 120, 3);

            userService.loginUser(2);
            restaurantService.registerRestaurant("Food Court 3", "3439", "SI Thali", 150, 1);

            userService.loginUser(3);
            restaurantService.showRestaurant("price");

            // Place Order
            orderService.placeOrder("Food Court 1", 2);
            // orderService.placeOrder("Food Court 2", 7);

            restaurantService.rateRestaurant("Food Court 2", 3, "Good Food");
            restaurantService.rateRestaurant("Food Court 1", 5, "Nice Food");

            restaurantService.showRestaurant("rating");
            userService.loginUser(1);

            restaurantService.updateQuantity("Food Court 2", 5);
            // orderService.placeOrder("Food Court 2", 7);
            restaurantService.showRestaurant("price");
            orderService.placeOrder("Food Court 3", 1);
            // orderService.placeOrder("Food Court 3", 1);

            userService.loginUser(3);
            orderService.orderHistory();

            userService.loginUser(1);
            orderService.orderHistory();

        }
        catch (Exception e){
            System.out.println(e.fillInStackTrace());
        }
    }
}
