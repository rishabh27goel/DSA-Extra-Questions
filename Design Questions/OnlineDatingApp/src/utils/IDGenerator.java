package utils;

import constants.IDType;

public class IDGenerator {

    private static Integer userId = 0;
    private static Integer matchId = 0;
    public static Integer generateId(IDType idType){

        switch (idType){

            case USER:
                return ++userId;

            case MATCH:
                return ++matchId;

            default :
                break;
        }

        return 0;
    }
}
