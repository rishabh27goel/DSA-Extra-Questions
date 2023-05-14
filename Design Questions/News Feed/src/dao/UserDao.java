package dao;

import constants.Gender;
import constants.IDType;
import models.User;
import services.UserServices;
import utils.IDGenerator;

import java.util.ArrayList;
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


    // Data Storage
    private User loggedInUser = null;
    private Map<Integer, User> userInfoMap = new HashMap<>();
    private Map<String, Integer> existedUserNameMap = new HashMap<>();


    // User Services
    public void signupUser(String userName, Long userPhoneNumber, Integer userAge, Gender userGender) throws Exception {

        // If user already exist
        if(existedUserNameMap.containsKey(userName))
            throw new Exception("Username already exists with username " + userName);

        // If user do not exist
        User newUser = new User();
        newUser.setUserId(IDGenerator.generateId(IDType.USER));
        newUser.setUserName(userName);
        newUser.setUserPhoneNumber(userPhoneNumber);
        newUser.setUserAge(userAge);
        newUser.setUserGender(userGender);
        newUser.setUserFollowers(new ArrayList<>());
        newUser.setUserFollowing(new ArrayList<>());

        System.out.println("User created successfully");
        System.out.println("User Id : " + newUser.getUserId());
        System.out.println("Username : " + newUser.getUserName());
    }

    public void loginUser(String userName) throws Exception {

        // If user do not exist
        if(!existedUserNameMap.containsKey(userName))
            throw new Exception("Username do not exist with username " + userName);

        // If user exists
        loggedInUser = userInfoMap.get(existedUserNameMap.get(userName));

        // Call the feed for user
        showNewsFeed();
    }

    public void followUser(String primaryUser, String secondaryUser) throws Exception {


    }


    // Feed Services
    public void createPost(String postMessage) throws Exception {


    }

    public void commentOnPost(Integer postId, String commentMessage) throws Exception {


    }

    public void upvotePost(Integer postId) throws Exception {


    }

    public void downvotePost(Integer postId) throws Exception {


    }

    public void showNewsFeed() throws Exception {


    }
}
