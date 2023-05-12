package dao;

import constants.Gender;
import constants.IDType;
import models.Location;
import models.Match;
import models.User;
import utils.IDGenerator;

import java.util.HashMap;
import java.util.List;
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
    private Map<Integer, User> userInfoMap = new HashMap<>();
    private Map<String, Integer> existingUserWithName = new HashMap<>();
    private Map<Integer, Match> matchInfoMap = new HashMap<>();


    // User Services
    public void createUser(String userName, Integer xCoordinate, Integer yCoordinate, Integer userAge, Gender gender) throws Exception {

        // If user exists
        if(existingUserWithName.containsKey(userName))
            throw new Exception("User already exists with user name " + userName);

        // If user do not exist
        User newUser = new User();
        newUser.setUserAge(IDGenerator.generateId(IDType.USER));
        newUser.setUserName(userName);
        newUser.setUserLocation(new Location(xCoordinate, yCoordinate));
        newUser.setUserAge(userAge);
        newUser.setUserGender(gender);

        userInfoMap.put(newUser.getUserId(), newUser);
        existingUserWithName.put(newUser.getUserName(), newUser.getUserId());

        System.out.println("User created Successfully");
        System.out.println("User ID : " + newUser.getUserId());
        System.out.println("User Name : " + newUser.getUserName());
    }

    public void deleteUser(String userName) throws Exception {

        // If user do not exist
        if(!existingUserWithName.containsKey(userName))
            throw new Exception("User does not exist with username " + userName);

        // If user exists

    }

    // Match Services
    public void potentialMatch(String userName){


    }

    public void like(String primaryName, String secondaryName) throws Exception {

        // If users do not exist
        if(!existingUserWithName.containsKey(primaryName))
            throw new Exception("User don't exist with username " + primaryName);
        else if(!existingUserWithName.containsKey(secondaryName))
            throw new Exception("User don't exist with username " + secondaryName);


        // If users exist


    }

    public void ignore(String primaryName, String secondaryName){


    }

    public void showMatches(String userName) throws Exception {

        // If user do not exist
        if(!existingUserWithName.containsKey(userName))
            throw new Exception("User does not exist with username " + userName);

        // If user exist
        List<Integer> userMatches = userInfoMap.get(existingUserWithName.get(userName)).getUserMatchHistory();

        if(userMatches.isEmpty())
            throw new Exception("No matches till now for username " + userName);

        System.out.println("Matches Found : "  );

        for(Integer matchId : userMatches){

            Match match = matchInfoMap.get(matchId);

            // If primary user matches with username -> Target is second user
            if(userInfoMap.get(match.getPrimaryUser()).getUserName().equals(userName)){

                User user = userInfoMap.get(match.getSecondaryUser());

                System.out.println("Username : " + user.getUserName());
                System.out.println("Gender : " + user.getUserGender());
                System.out.println("Age : " + user.getUserAge());
            }
            // If secondary user matches with username -> Target is first user
            else{

                User user = userInfoMap.get(match.getPrimaryUser());

                System.out.println("Username : " + user.getUserName());
                System.out.println("Gender : " + user.getUserGender());
                System.out.println("Age : " + user.getUserAge());
            }
        }
    }

    public void showAllMatches() throws Exception {

        // If no matches exist
        if(matchInfoMap.isEmpty())
            throw new Exception("No matches found in the system");

        // If matches are present
        for(Match match : matchInfoMap.values()) {

            User primary = userInfoMap.get(match.getPrimaryUser());
            User secondary = userInfoMap.get(match.getSecondaryUser());

            System.out.println("Match Id : " + match.getMatchId());
            System.out.println("Username : " + primary.getUserName() + "\t" + primary.getUserGender() + "\t" + primary.getUserAge());
            System.out.println("Username : " + secondary.getUserName() + "\t" + secondary.getUserGender() + "\t" + secondary.getUserAge());
        }
    }

}
