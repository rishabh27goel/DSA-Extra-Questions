package services;

import dao.UserDao;

public class FeedServices {

    private static FeedServices instance = null;

    private FeedServices(){

    }

    public static FeedServices getInstance(){

        if(instance == null)
            instance = new FeedServices();

        return instance;
    }

    private UserDao userDao = UserDao.getInstance();


    public void createPost(String postMessage) throws Exception {

        if(postMessage.isEmpty() || postMessage == null)
            throw new Exception("Post message can not be empty");

        userDao.createPost(postMessage);
    }

    public void commentOnPost(Integer postId, String commentMessage) throws Exception {

        if(postId <= 0 || postId == null)
            throw new Exception("PostId should be non-zero positive number");
        else if(commentMessage.isEmpty() || commentMessage == null)
            throw new Exception("Comment message can not be empty");

        userDao.commentOnPost(postId, commentMessage);
    }

    public void upvotePost(Integer postId) throws Exception {

        if(postId <= 0 || postId == null)
            throw new Exception("PostId should be non-zero positive number");

        userDao.upvotePost(postId);
    }

    public void downvotePost(Integer postId) throws Exception {

        if(postId <= 0 || postId == null)
            throw new Exception("PostId should be non-zero positive number");

        userDao.downvotePost(postId);
    }

    public void showNewsFeed() throws Exception {

        userDao.showNewsFeed();
    }
}
