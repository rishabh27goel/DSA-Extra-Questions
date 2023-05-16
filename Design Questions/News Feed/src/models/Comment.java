package models;

import java.sql.Timestamp;
import java.util.Date;
import java.util.List;

public class Comment {

    private Integer commentId;
    private Integer commentByUserId;
    private String commentMessage;
    private Integer commentUpVotes;
    private Integer commentDownVotes;
    private Date commentTimestamp;
    private List<Integer> commentsReplyList;

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

    public Date getCommentTimestamp() {
        return commentTimestamp;
    }

    public void setCommentTimestamp(Date commentTimestamp) {
        this.commentTimestamp = commentTimestamp;
    }

    public List<Integer> getCommentsReplyList() {
        return commentsReplyList;
    }

    public void setCommentsReplyList(List<Integer> commentsReplyList) {
        this.commentsReplyList = commentsReplyList;
    }

    public Integer getCommentUpVotes() {
        return commentUpVotes;
    }

    public void setCommentUpVotes(Integer commentUpVotes) {
        this.commentUpVotes = commentUpVotes;
    }

    public Integer getCommentDownVotes() {
        return commentDownVotes;
    }

    public void setCommentDownVotes(Integer commentDownVotes) {
        this.commentDownVotes = commentDownVotes;
    }
}
