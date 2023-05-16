package utils;

import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Utils {

    public static String formatTimestamp(Date timestamp){

        String formattedTimestamp = new SimpleDateFormat("yyyy-MM-dd hh:mm").format(timestamp) + " ";
        formattedTimestamp += new SimpleDateFormat("a").format(timestamp).toUpperCase();

        return formattedTimestamp;
    }
}
