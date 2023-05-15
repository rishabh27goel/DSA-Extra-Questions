package services;

import constants.Gender;
import dao.UserDao;
import models.User;

public class UserServices {

    private static UserServices instance = null;

    private UserServices(){

    }

    public static UserServices getInstance(){

        if(instance == null)
            instance = new UserServices();

        return instance;
    }

    private UserDao userDao = UserDao.getInstance();


    public void signupUser(String userName, Long userPhoneNumber, Integer userAge, Gender userGender) throws Exception {

        if(userName.isEmpty() || userName == null)
            throw new Exception("Username can not be empty");
        else if(userPhoneNumber <= 0 || userPhoneNumber == null)
            throw new Exception("Phone number should be non-zero positive number");
        else if(userAge <= 0 || userAge == null)
            throw new Exception("Age should be non-zero positive number");

        userDao.signupUser(userName, userPhoneNumber, userAge, userGender);
    }

    public void loginUser(String userName) throws Exception {

        if(userName.isEmpty() || userName == null)
            throw new Exception("Username can not be empty");

        userDao.loginUser(userName);
    }

    public void followUser(String userName) throws Exception {

        if(userName.isEmpty() || userName == null)
            throw new Exception("Username can not be empty");

        userDao.followUser(userName);
    }
}
