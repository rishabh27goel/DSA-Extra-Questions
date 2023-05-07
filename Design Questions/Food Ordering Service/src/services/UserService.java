package services;

import constants.Gender;
import dao.UserDao;

public class UserService {
    private static UserService instance = null;
    private UserService(){

    }
    public static UserService getInstance(){

        if(instance == null)
            instance = new UserService();

        return instance; 
    }

    // Every service needs a reference for Dao
    private UserDao userDao = UserDao.getInstance();


    public void registerUser(String userName, Gender userGender, Long userPhoneNumber, Long userPincode) throws Exception {

        if(userName.isEmpty())
            throw new Exception("Username can not be empty");
        else if(userPhoneNumber == null || userPhoneNumber <= 0)
            throw new Exception("Invalid phone number");
        else if(userPincode == null || userPincode <= 0)
            throw new Exception("Invalid pincode");

        userDao.registerUser(userName, userGender, userPhoneNumber, userPincode);
    }

    public void loginUser(int userId) throws Exception{

        if(userId <= 0)
            throw new Exception("Invalid UserId");

        userDao.loginUser(userId);
    }
}
