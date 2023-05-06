package models;

public class Review {

    private int reviewId;
    private int reviewRating;
    private String reviewComment;

    Review(int reviewId, int reviewRating, String reviewComment){

        this.reviewId = reviewId;
        this.reviewRating = reviewRating;
        this.reviewComment = reviewComment;
    }


    public int getReviewId() {
        return reviewId;
    }

    public void setReviewId(int reviewId) {
        this.reviewId = reviewId;
    }

    public int getReviewRating() {
        return reviewRating;
    }

    public void setReviewRating(int reviewRating) {
        this.reviewRating = reviewRating;
    }

    public String getReviewComment() {
        return reviewComment;
    }

    public void setReviewComment(String reviewComment) {
        this.reviewComment = reviewComment;
    }
}
