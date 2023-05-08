package models;

import constants.Gender;

import java.util.ArrayList;
import java.util.List;

public class User {

    private int userId;
    private String userName;
    private Gender userGender;
    private Long userPhoneNumber;
    private Long userPincode;
    private List<Restaurant> userRestaurantList;
    private List<Order> userOrderHistory;

    public User(int userId, String userName, Gender userGender, Long userPhoneNumber, Long userPincode){

        this.userId = userId;
        this.userName = userName;
        this.userGender = userGender;
        this.userPhoneNumber = userPhoneNumber;
        this.userPincode = userPincode;
        this.userRestaurantList = new ArrayList<>();
        this.userOrderHistory = new ArrayList<>();
    }


    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public Gender getUserGender() {
        return userGender;
    }

    public void setUserGender(Gender userGender) {
        this.userGender = userGender;
    }

    public Long getUserPhoneNumber() {
        return userPhoneNumber;
    }

    public void setUserPhoneNumber(long userPhoneNumber) {
        this.userPhoneNumber = userPhoneNumber;
    }

    public Long getUserPincode() {
        return userPincode;
    }

    public void setUserPincode(long userPincode) {
        this.userPincode = userPincode;
    }

    public List<Restaurant> getUserRestaurantList() {
        return userRestaurantList;
    }

    public void setUserRestaurantList(List<Restaurant> userRestaurantList) {
        this.userRestaurantList = userRestaurantList;
    }

    public List<Order> getUserOrderHistory() {
        return userOrderHistory;
    }

    public void setUserOrderHistory(List<Order> userOrderHistory) {
        this.userOrderHistory = userOrderHistory;
    }
}
