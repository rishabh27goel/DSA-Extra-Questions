package models;

public class Location {

    private Integer xCoordinate;
    private Integer yCoordinate;
    
    public Location(Integer xCoordinate, Integer yCoordinate){

        this.xCoordinate = xCoordinate;
        this.yCoordinate = yCoordinate;
    }
    
    
    public Integer getxCoordinate() {
        return xCoordinate;
    }

    public void setxCoordinate(Integer xCoordinate) {
        this.xCoordinate = xCoordinate;
    }

    public Integer getyCoordinate() {
        return yCoordinate;
    }

    public void setyCoordinate(Integer yCoordinate) {
        this.yCoordinate = yCoordinate;
    }
}
