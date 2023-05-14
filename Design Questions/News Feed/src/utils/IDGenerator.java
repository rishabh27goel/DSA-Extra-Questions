package utils;

import constants.IDType;

public class IDGenerator {

    private static Integer userId = 0;
    private static Integer postId = 0;
    private static Integer commentId = 0;

    public static Integer generateId(IDType idType){

        switch (idType){

            case USER:
                return ++userId;

            case POST:
                return ++postId;

            case COMMENT:
                return ++commentId;

            default:
                break;
        }

        return 0;
    }
}
