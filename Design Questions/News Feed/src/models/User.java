package models;

import constants.Gender;

import java.util.List;

public class User {

    private Integer userId;
    private String userName;
    private Integer userAge;
    private Long userPhoneNumber;
    private Gender userGender;
    private List<Integer> userFollowers;
    private List<Integer> userFollowing;


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

    public Integer getUserAge() {
        return userAge;
    }

    public void setUserAge(Integer userAge) {
        this.userAge = userAge;
    }

    public Long getUserPhoneNumber() {
        return userPhoneNumber;
    }

    public void setUserPhoneNumber(Long userPhoneNumber) {
        this.userPhoneNumber = userPhoneNumber;
    }

    public Gender getUserGender() {
        return userGender;
    }

    public void setUserGender(Gender userGender) {
        this.userGender = userGender;
    }

    public List<Integer> getUserFollowers() {
        return userFollowers;
    }

    public void setUserFollowers(List<Integer> userFollowers) {
        this.userFollowers = userFollowers;
    }

    public List<Integer> getUserFollowing() {
        return userFollowing;
    }

    public void setUserFollowing(List<Integer> userFollowing) {
        this.userFollowing = userFollowing;
    }
}
