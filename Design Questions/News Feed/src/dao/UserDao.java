package dao;

import constants.Gender;
import constants.IDType;
import models.Comment;
import models.Post;
import models.User;
import services.UserServices;
import utils.IDGenerator;
import utils.Utils;

import java.sql.Timestamp;
import java.time.Instant;
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
    private User loggedInUser = null;
    private Map<String, Integer> existedUserNameMap = new HashMap<>();
    private Map<Integer, User> userInfoMap = new HashMap<>();
    private Map<Integer, Post> postInfoMap = new HashMap<>();
    private Map<Integer, Comment> commentInfoMap = new HashMap<>();


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

        existedUserNameMap.put(newUser.getUserName(), newUser.getUserId());
        userInfoMap.put(newUser.getUserId(), newUser);


        System.out.println("User created successfully");
        System.out.println("User Id : " + newUser.getUserId());
        System.out.println("Username : " + newUser.getUserName() + "\n");
    }

    public void loginUser(String userName) throws Exception {

        // If user do not exist
        if(!existedUserNameMap.containsKey(userName))
            throw new Exception("Username do not exist with username " + userName);

        // If user exists
        loggedInUser = userInfoMap.get(existedUserNameMap.get(userName));

        System.out.println("User logged-in successfully");

        // Call the feed for user
        showNewsFeed();
    }

    public void followUser(String userName) throws Exception {

        // If users do not exist
        if(!existedUserNameMap.containsKey(userName))
            throw new Exception("Username do not exist with username " + userName);


        // If users exists
        User user = userInfoMap.get(existedUserNameMap.get(userName));

        loggedInUser.getUserFollowing().add(user.getUserId());
        user.getUserFollowers().add(loggedInUser.getUserId());

        System.out.println(loggedInUser.getUserName() + " has started following " + userName + "\n");
    }


    // Feed Services
    public void createPost(String postMessage) throws Exception {

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");

        // If logged-in user exist
        Post newPost = new Post();
        newPost.setPostId(IDGenerator.generateId(IDType.POST));
        newPost.setPostMessage(postMessage);
        newPost.setPostTimestamp(new Date());
        newPost.setPostUpVotes(0);
        newPost.setPostDownVotes(0);
        newPost.setPostByUserId(loggedInUser.getUserId());
        newPost.setPostCommentsList(new ArrayList<>());

        postInfoMap.put(newPost.getPostId(), newPost);

        System.out.println("New Post created successfully");
        System.out.println("Post Id : " + newPost.getPostId());
        System.out.println("Post Message : " + newPost.getPostMessage());
        System.out.println("Username : " + loggedInUser.getUserName());
        System.out.println("Timestamp : " + newPost.getPostTimestamp() + "\n");
    }

    public void commentOnPost(Integer postId, String commentMessage) throws Exception {

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");

        // If postId don't exist
        if(!postInfoMap.containsKey(postId))
            throw new Exception("Post do not exist with postId " + postId);


        // If logged-in user exist
        Comment newComment = createCommentObject(commentMessage);

        commentInfoMap.put(newComment.getCommentId(), newComment);
        postInfoMap.get(postId).getPostCommentsList().add(newComment.getCommentId());

        System.out.println(loggedInUser.getUserName() + " has commented on postId " + postId + "\n");
    }

    public void upvotePost(Integer postId) throws Exception {

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");

        // If postId don't exist
        if(!postInfoMap.containsKey(postId))
            throw new Exception("Post do not exist with postId " + postId);


        // If logged-in user exist
        Post post = postInfoMap.get(postId);
        post.setPostUpVotes(post.getPostUpVotes() + 1);

        System.out.println(loggedInUser.getUserName() + " has upvoted postId " + postId + "\n");
    }

    public void downvotePost(Integer postId) throws Exception {

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");

        // If postId don't exist
        if(!postInfoMap.containsKey(postId))
            throw new Exception("Post do not exist with postId " + postId);


        // If logged-in user exist
        Post post = postInfoMap.get(postId);
        post.setPostDownVotes(post.getPostDownVotes() + 1);

        System.out.println(loggedInUser.getUserName() + " has downvoted postId " + postId + "\n");
    }

    public void showNewsFeed() throws Exception {

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");

        if(postInfoMap.size() == 0){

            System.out.println("No post created yet\n");
            return;
        }

        // If logged-in user exist
        List<Integer> postList = fetchPostList();

        Collections.sort(postList,  new Comparator<Integer>() {
            public int compare(Integer postId1, Integer postId2) {

                Post p1 = postInfoMap.get(postId1);
                Post p2 = postInfoMap.get(postId2);

                Boolean a = loggedInUser.getUserFollowing().contains(p1.getPostByUserId());
                Boolean b = loggedInUser.getUserFollowing().contains(p2.getPostByUserId());

                // If both users are in following list
                if((a && b) || (!a && !b)){

                    // Order by score
                    if(p1.getPostUpVotes() - p1.getPostDownVotes() > p2.getPostUpVotes() - p2.getPostDownVotes()){

                        return -1;
                    }
                    else if(p1.getPostUpVotes() - p1.getPostDownVotes() < p2.getPostUpVotes() - p2.getPostDownVotes()){

                        return 1;
                    }
                    else{

                        // Order by number of comments
                        if(p1.getPostCommentsList().size() > p2.getPostCommentsList().size()){

                            return 1;
                        }
                        else if(p1.getPostCommentsList().size() < p2.getPostCommentsList().size()){

                            return -1;
                        }
                        else{

                            // Order by timestamp
                            return p2.getPostTimestamp().compareTo(p1.getPostTimestamp());
                        }
                    }
                }
                // If user one is in following list
                else if(a){

                    return -1;
                }
                // If user two is in following list
                else{

                    return 1;
                }
            }
        });


        for(Integer postId : postList){
            Post post = postInfoMap.get(postId);
            System.out.println("Post Id : " + post.getPostId());
            System.out.println("(" + post.getPostUpVotes() + " upvotes, " + post.getPostDownVotes() + " downvotes" + ")");
            System.out.println(userInfoMap.get(post.getPostByUserId()).getUserName());
            System.out.println(post.getPostMessage());
            System.out.println(Utils.formatTimestamp(post.getPostTimestamp()));

            // Get comments related to this post
            getPostComments(post.getPostCommentsList(), 1);
            System.out.println();
        }
    }
    
    
    // Bonus Task
    public void replyOnComments(Integer commentId, String replyMessage) throws Exception{

        // If no logged-in user exist
        if(loggedInUser == null)
            throw new Exception("No user logged-in currently ");
        
        // If commentId do not exist
        if(!commentInfoMap.containsKey(commentId))
            throw new Exception("Comment do not exist with commentId " + commentId);

        
        // If comment exist
        Comment newComment = createCommentObject(replyMessage);
        
        commentInfoMap.put(newComment.getCommentId(), newComment);
        commentInfoMap.get(commentId).getCommentsReplyList().add(newComment.getCommentId());

        System.out.println(loggedInUser.getUserName() + " has replied on commentId " + commentId);
    }
    

    // Helper Functions
    public List<Integer> fetchPostList(){

        List<Integer> postList = new ArrayList<>();

        for(Integer postId : postInfoMap.keySet()){

            postList.add(postId);
        }

        return postList;
    }

    public Comment createCommentObject(String commentMessage){

        Comment newComment = new Comment();
        newComment.setCommentId(IDGenerator.generateId(IDType.COMMENT));
        newComment.setCommentTimestamp(new Date());
        newComment.setCommentMessage(commentMessage);
        newComment.setCommentUpVotes(0);
        newComment.setCommentDownVotes(0);
        newComment.setCommentByUserId(loggedInUser.getUserId());
        newComment.setCommentsReplyList(new ArrayList<>());

        return newComment;
    }

    public void getPostComments(List<Integer> commentsList, int level){

        if(commentsList.size() == 0)
            return;


        String tabSpace = "";

        for(int i=1; i<=level; i++)
            tabSpace += "\t\t";


        for(Integer commentId : commentsList){

            Comment comment = commentInfoMap.get(commentId);

            System.out.println(tabSpace + "Comment Id : " + comment.getCommentId());
            System.out.println(tabSpace + "(" + comment.getCommentUpVotes() + " upvotes, " + comment.getCommentDownVotes() + " downvotes" + ")");
            System.out.println(tabSpace + userInfoMap.get(comment.getCommentByUserId()).getUserName());
            System.out.println(tabSpace + comment.getCommentMessage());
            System.out.println(tabSpace + Utils.formatTimestamp(comment.getCommentTimestamp()));
            getPostComments(comment.getCommentsReplyList(), level+1);
        }
    }
}
