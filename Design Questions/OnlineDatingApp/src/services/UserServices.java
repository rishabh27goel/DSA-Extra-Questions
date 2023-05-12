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

    public void createUser(String userName, Integer xCoordinate, Integer yCoordinate, Integer userAge, Gender gender) throws Exception{

        if(userName.isEmpty())
            throw new Exception("User Name can not be empty");
        else if(xCoordinate == null || yCoordinate == null)
            throw new Exception("Location coordinate can not be empty");
        else if(userAge == null || userAge <= 0)
            throw new Exception("User age is not valid");

        userDao.createUser(userName, xCoordinate, yCoordinate, userAge, gender);
    }

    public void deleteUser(String userName) throws Exception {

        if(userName.isEmpty())
            throw new Exception("User Name can not be empty");

        userDao.deleteUser(userName);
    }
}
