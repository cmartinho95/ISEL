import java.time.LocalDate;
import java.time.LocalTime;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class Testes_App {
    public static void main(String[] args){
        long time = System.currentTimeMillis();

        DateFormat df = new SimpleDateFormat("EEE. HH:mm");
        Date today = Calendar.getInstance().getTime();

        System.out.println(time);
        System.out.println(df.format(today));
    }


    public static String convertToHours(long time){ // millis to hours:minutes
        long hours = TimeUnit.MILLISECONDS.toHours(time);
        long minutes = TimeUnit.MILLISECONDS.toMinutes(time) - TimeUnit.HOURS.toMinutes(TimeUnit.MILLISECONDS.toHours(time));
        return String.format("%02d:%02d", hours, minutes);
    }

}
