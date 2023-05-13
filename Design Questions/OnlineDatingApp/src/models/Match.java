package models;

import java.util.Date;

public class Match {

    private Integer matchId;
    private Integer primaryUser;
    private Integer secondaryUser;

    public Match(Integer matchId, Integer primaryUser, Integer secondaryUser){

        this.matchId = matchId;
        this.primaryUser = primaryUser;
        this.secondaryUser = secondaryUser;
    }

    public Integer getMatchId() {
        return matchId;
    }

    public void setMatchId(Integer matchId) {
        this.matchId = matchId;
    }

    public Integer getPrimaryUser() {
        return primaryUser;
    }

    public void setPrimaryUser(Integer primaryUser) {
        this.primaryUser = primaryUser;
    }

    public Integer getSecondaryUser() {
        return secondaryUser;
    }

    public void setSecondaryUser(Integer secondaryUser) {
        this.secondaryUser = secondaryUser;
    }
}
