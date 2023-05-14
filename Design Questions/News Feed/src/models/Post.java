package models;

import java.sql.Timestamp;
import java.util.List;

public class Post {

    private Integer postId;
    private Integer postByUserId;
    private String postMessage;
    private Integer postUpVotes;
    private Integer postDownVotes;
    private Timestamp postTimestamp;
    private List<Integer> postCommentsList;

    public Post(){

    }


    public Integer getPostId() {
        return postId;
    }

    public void setPostId(Integer postId) {
        this.postId = postId;
    }

    public Integer getPostByUserId() {
        return postByUserId;
    }

    public void setPostByUserId(Integer postByUserId) {
        this.postByUserId = postByUserId;
    }

    public String getPostMessage() {
        return postMessage;
    }

    public void setPostMessage(String postMessage) {
        this.postMessage = postMessage;
    }

    public Integer getPostUpVotes() {
        return postUpVotes;
    }

    public void setPostUpVotes(Integer postUpVotes) {
        this.postUpVotes = postUpVotes;
    }

    public Integer getPostDownVotes() {
        return postDownVotes;
    }

    public void setPostDownVotes(Integer postDownVotes) {
        this.postDownVotes = postDownVotes;
    }

    public Timestamp getPostTimestamp() {
        return postTimestamp;
    }

    public void setPostTimestamp(Timestamp postTimestamp) {
        this.postTimestamp = postTimestamp;
    }

    public List<Integer> getPostCommentsList() {
        return postCommentsList;
    }

    public void setPostCommentsList(List<Integer> postCommentsList) {
        this.postCommentsList = postCommentsList;
    }
}
