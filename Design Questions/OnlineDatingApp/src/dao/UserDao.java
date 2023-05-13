package dao;

import constants.ActionType;
import constants.Gender;
import constants.IDType;
import models.Location;
import models.Match;
import models.User;
import utils.IDGenerator;
import utils.Utils;

import java.util.*;

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
        newUser.setUserId(IDGenerator.generateId(IDType.USER));
        newUser.setUserName(userName);
        newUser.setUserLocation(new Location(xCoordinate, yCoordinate));
        newUser.setUserAge(userAge);
        newUser.setUserGender(gender);

        userInfoMap.put(newUser.getUserId(), newUser);
        existingUserWithName.put(newUser.getUserName(), newUser.getUserId());

        System.out.println("User created Successfully");
        System.out.println("User ID : " + newUser.getUserId());
        System.out.println("User Name : " + newUser.getUserName());
        System.out.println();
    }

    public void deleteUser(String userName) throws Exception {

        // If user do not exist
        if(!existingUserWithName.containsKey(userName))
            throw new Exception("User does not exist with username " + userName);


        // If user exists
        User user = userInfoMap.get(existingUserWithName.get(userName));

        // List of user who liked you
        for(Integer userId : user.getUsersWhoLikedYou()){

            userInfoMap.get(userId).getUserActionTypeMap().remove(user.getUserId());
        }

        // Remove matches data from other users match history
        for(Integer matchId : user.getUserMatchHistory()){

            User otherUser;

            if(matchInfoMap.get(matchId).getPrimaryUser() == user.getUserId())
                otherUser = userInfoMap.get(matchInfoMap.get(matchId).getSecondaryUser());
            else
                otherUser = userInfoMap.get(matchInfoMap.get(matchId).getPrimaryUser());


            otherUser.getUserMatchHistory().remove(matchId);
            matchInfoMap.remove(matchId);
        }

        // Users you have liked
        for(Integer userId : user.getUserActionTypeMap().keySet()){

            if(user.getUserActionTypeMap().get(userId) == ActionType.LIKE){

                userInfoMap.get(userId).getUsersWhoLikedYou().remove(user.getUserId());
            }
        }

        // Remove data from user maps
        user.getUsersWhoLikedYou().clear();
        user.getUserMatchHistory().clear();
        user.getUserActionTypeMap().clear();

        userInfoMap.remove(user.getUserId());
        existingUserWithName.remove(user.getUserName());

        System.out.println("User deleted successfully from the system \n");
    }

    // Match Services
    public void potentialMatch(String userName) throws Exception {

        // If user do not exist
        if(!existingUserWithName.containsKey(userName))
            throw new Exception("User does not exist with username " + userName);

        // Order of relevance
        // 1. Gender
        // 2. Proximity
        // 3. Age

        // If user exist
        User currentUser = userInfoMap.get(existingUserWithName.get(userName));
        List<Integer> potentialUsers = fetchUsers(currentUser);

        if(potentialUsers.isEmpty())
            throw new Exception("No potential match found");


        Collections.sort(potentialUsers, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {

                if(userInfoMap.get(a).getUserAge() - userInfoMap.get(b).getUserAge() == 0){

                    double d1 = Utils.findDistance(currentUser.getUserLocation(), userInfoMap.get(a).getUserLocation());
                    double d2 = Utils.findDistance(currentUser.getUserLocation(), userInfoMap.get(b).getUserLocation());

                    if(d1 > d2)
                        return 1;
                    else if(d1 < d2)
                        return -1;
                    else
                        return 0;
                }

                return Math.abs(currentUser.getUserAge() - userInfoMap.get(a).getUserAge()) - Math.abs(currentUser.getUserAge() - userInfoMap.get(b).getUserAge());
            }
        });

        System.out.println("Potential Matches : ---------");

        for(Integer userId : potentialUsers){

            User user = userInfoMap.get(userId);
            System.out.println("User Id : " + user.getUserId());
            System.out.println("User Name : " + user.getUserName());
            System.out.println("Age : " + user.getUserAge());
            System.out.println("Gender : " + user.getUserGender());
            System.out.println("Distance : " + Utils.findDistance(currentUser.getUserLocation(), user.getUserLocation()));
        }

        System.out.println();
    }

    public void like(String primaryName, String secondaryName) throws Exception {

        // If users do not exist
        if(!existingUserWithName.containsKey(primaryName))
            throw new Exception("User don't exist with username " + primaryName);
        else if(!existingUserWithName.containsKey(secondaryName))
            throw new Exception("User don't exist with username " + secondaryName);


        // If users exist [primary is liking secondary]
        User primary = userInfoMap.get(existingUserWithName.get(primaryName));
        User secondary = userInfoMap.get(existingUserWithName.get(secondaryName));

        // Add the user to action type map of user
        primary.getUserActionTypeMap().put(secondary.getUserId(), ActionType.LIKE);
        secondary.getUsersWhoLikedYou().add(primary.getUserId());


        // If both have liked each other we create a match
        if(secondary.getUserActionTypeMap().containsKey(primary.getUserId())){

            // Both users have each in the action type map
            if(secondary.getUserActionTypeMap().get(primary.getUserId()) == ActionType.LIKE){

                Match match = new Match(IDGenerator.generateId(IDType.MATCH), primary.getUserId(), secondary.getUserId());
                matchInfoMap.put(match.getMatchId(), match);

                // Update match list for both users
                primary.getUserMatchHistory().add(match.getMatchId());
                secondary.getUserMatchHistory().add(match.getMatchId());
            }
        }

        System.out.println(primaryName + " has liked " + secondaryName + " successfully" + "\n");
    }

    public void ignore(String primaryName, String secondaryName) throws Exception {

        // If users do not exist
        if(!existingUserWithName.containsKey(primaryName))
            throw new Exception("User don't exist with username " + primaryName);
        else if(!existingUserWithName.containsKey(secondaryName))
            throw new Exception("User don't exist with username " + secondaryName);


        // If users exist [primary is ignoring secondary]
        User primary = userInfoMap.get(existingUserWithName.get(primaryName));
        User secondary = userInfoMap.get(existingUserWithName.get(secondaryName));

        primary.getUserActionTypeMap().put(secondary.getUserId(), ActionType.IGNORE);

        System.out.println(primaryName + " has ignored " + secondaryName + " successfully" + "\n");
    }

    public void showMatches(String userName) throws Exception {

        // If user do not exist
        if(!existingUserWithName.containsKey(userName))
            throw new Exception("User does not exist with username " + userName);

        // If user exist
        List<Integer> userMatches = userInfoMap.get(existingUserWithName.get(userName)).getUserMatchHistory();

        if(userMatches.isEmpty()){

            System.out.println("No matches till now for username " + userName + "\n");
            return;
        }

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

        System.out.println();
    }

    public void showAllMatches() throws Exception {

        // If no matches exist
        if(matchInfoMap.isEmpty()){

            System.out.println("No matches found in the system");
            return;
        }

        System.out.println("All Matches : ");

        // If matches are present
        for(Match match : matchInfoMap.values()) {

            User primary = userInfoMap.get(match.getPrimaryUser());
            User secondary = userInfoMap.get(match.getSecondaryUser());

            System.out.println("Match Id : " + match.getMatchId());
            System.out.println("Username : " + primary.getUserName() + "   " + primary.getUserGender() + "   " + primary.getUserAge());
            System.out.println("Username : " + secondary.getUserName() + "   " + secondary.getUserGender() + "   " + secondary.getUserAge());
        }

        System.out.println();
    }

    // Other Services
    public List<Integer> fetchUsers(User currentUser){

        List<Integer> potentialUsers = new ArrayList<>();

        // Iterate all the users in the system
        for(User user : userInfoMap.values()){

            // User should not be the person ignored by current user
            if(currentUser.getUserActionTypeMap().containsKey(user.getUserId()) && currentUser.getUserActionTypeMap().get(user.getUserId()) == ActionType.IGNORE)
                continue;

            // Opposite Gender
            if(currentUser.getUserGender().equals(user.getUserGender()))
                continue;

            potentialUsers.add(user.getUserId());
        }

        return potentialUsers;
    }
}
