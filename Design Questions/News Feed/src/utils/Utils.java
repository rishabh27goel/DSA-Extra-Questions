package utils;

import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;

public class Utils {

    public static String formatTimestamp(Date timestamp){

        String formattedTimestamp = new SimpleDateFormat("yyyy-MM-dd hh:mm").format(timestamp) + " ";
        formattedTimestamp += new SimpleDateFormat("a").format(timestamp).toUpperCase();

        String timeAgoStr = "";
        long timeAgo = new Date().getTime() - timestamp.getTime();

        formattedTimestamp += " (";

        if(TimeUnit.MILLISECONDS.toDays(timeAgo) / 365 > 0){

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toDays(timeAgo) / 365);
            timeAgoStr += " years ago";
        }
        else if(TimeUnit.MILLISECONDS.toDays(timeAgo) > 0){

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toDays(timeAgo));
            timeAgoStr += " days ago";
        }
        else if(TimeUnit.MILLISECONDS.toHours(timeAgo) > 0){

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toHours(timeAgo));
            timeAgoStr += " hours ago";
        }
        else if(TimeUnit.MILLISECONDS.toMinutes(timeAgo) > 0){

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toMinutes(timeAgo));
            timeAgoStr += " minutes ago";
        }
        else if(TimeUnit.MILLISECONDS.toSeconds(timeAgo) > 0){

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toSeconds(timeAgo));
            timeAgoStr += " minutes ago";
        }
        else{

            timeAgoStr += String.valueOf(TimeUnit.MILLISECONDS.toMillis(timeAgo));
            timeAgoStr += " milliseconds ago";
        }

        formattedTimestamp += timeAgoStr;
        formattedTimestamp += ")";

        return formattedTimestamp;
    }
}
