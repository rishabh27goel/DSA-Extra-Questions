package services;

import constants.Gender;
import dao.UserDao;

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

    public void followUser(String primaryUser, String secondaryUser) throws Exception {

        if(primaryUser.isEmpty() || primaryUser == null)
            throw new Exception("Primary username can not be empty");
        else if(secondaryUser.isEmpty() || secondaryUser == null)
            throw new Exception("Secondary username can not be empty");

        userDao.followUser(primaryUser, secondaryUser);
    }
}
