package utils;

import models.Location;

public class Utils {

    public static double findDistance(Location l1, Location l2){

        return Math.sqrt(Math.pow(l1.getxCoordinate() - l2.getxCoordinate(), 2) + Math.pow(l1.getyCoordinate() - l2.getyCoordinate(), 2));
    }
}
