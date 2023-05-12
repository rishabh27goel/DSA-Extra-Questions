package services;

import dao.UserDao;
import models.Match;

public class MatchServices {

    private static MatchServices instance = null;

    private MatchServices(){

    }

    public static MatchServices getInstance(){

        if(instance == null)
            instance = new MatchServices();

        return instance;
    }

    private UserDao userDao = UserDao.getInstance();


    public void potentialMatch(String userName) throws Exception {

        if(userName.isEmpty())
            throw new Exception("User Name can not be empty");

        userDao.potentialMatch(userName);
    }

    public void like(String primaryName, String secondaryName) throws Exception {

        if(primaryName.isEmpty() || secondaryName.isEmpty())
            throw new Exception("User Names can not be empty");

        userDao.like(primaryName, secondaryName);
    }

    public void ignore(String primaryName, String secondaryName) throws Exception {

        if(primaryName.isEmpty() || secondaryName.isEmpty())
            throw new Exception("User Names can not be empty");

        userDao.ignore(primaryName, secondaryName);
    }

    public void showMatches(String userName) throws Exception {

        if(userName.isEmpty())
            throw new Exception("User Name can not be empty");

        userDao.showMatches(userName);
    }

    public void showAllMatches(){

        userDao.showAllMatches();
    }
}
