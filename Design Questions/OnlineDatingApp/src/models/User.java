package models;

import constants.ActionType;
import constants.Gender;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class User {
    private Integer userId;
    private String userName;
    private Location userLocation;
    private Integer userAge;
    private Gender userGender;
    private Boolean isActive;

    private Map<Integer, ActionType> userActionTypeMap = new HashMap<Integer, ActionType>();
    private List<Integer> usersWhoLikedYou = new ArrayList<>();
    private List<Integer> userMatchHistory = new ArrayList<>();

    public User(){


    }


    public Integer getUserId() {
        return userId;
    }

    public void setUserId(Integer userId) {
        this.userId = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public Location getUserLocation() {
        return userLocation;
    }

    public void setUserLocation(Location userLocation) {
        this.userLocation = userLocation;
    }

    public Integer getUserAge() {
        return userAge;
    }

    public void setUserAge(Integer userAge) {
        this.userAge = userAge;
    }

    public Gender getUserGender() {
        return userGender;
    }

    public void setUserGender(Gender userGender) {
        this.userGender = userGender;
    }

    public Boolean getActive() {
        return isActive;
    }

    public void setActive(Boolean active) {
        isActive = active;
    }

    public Map<Integer, ActionType> getUserActionTypeMap() {
        return userActionTypeMap;
    }

    public void setUserActionTypeMap(Map<Integer, ActionType> userActionTypeMap) {
        this.userActionTypeMap = userActionTypeMap;
    }

    public List<Integer> getUsersWhoLikedYou() {
        return usersWhoLikedYou;
    }

    public void setUsersWhoLikedYou(List<Integer> usersWhoLikedYou) {
        this.usersWhoLikedYou = usersWhoLikedYou;
    }

    public List<Integer> getUserMatchHistory() {
        return userMatchHistory;
    }

    public void setUserMatchHistory(List<Integer> userMatchHistory) {
        this.userMatchHistory = userMatchHistory;
    }
}
