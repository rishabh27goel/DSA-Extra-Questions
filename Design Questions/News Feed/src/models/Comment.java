package models;

import java.sql.Timestamp;
import java.util.Date;

public class Comment {

    private Integer commentId;
    private Integer commentByUserId;
    private String commentMessage;
    private Timestamp commentTimestamp;

    public Comment(){


    }


    public Integer getCommentId() {
        return commentId;
    }

    public void setCommentId(Integer commentId) {
        this.commentId = commentId;
    }

    public Integer getCommentByUserId() {
        return commentByUserId;
    }

    public void setCommentByUserId(Integer commentByUserId) {
        this.commentByUserId = commentByUserId;
    }

    public String getCommentMessage() {
        return commentMessage;
    }

    public void setCommentMessage(String commentMessage) {
        this.commentMessage = commentMessage;
    }

    public Timestamp getCommentTimestamp() {
        return commentTimestamp;
    }

    public void setCommentTimestamp(Timestamp commentTimestamp) {
        this.commentTimestamp = commentTimestamp;
    }
}
