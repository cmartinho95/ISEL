import javax.xml.crypto.Data;
import isel.leic.utils.Time;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import static java.lang.System.currentTimeMillis;

public class TUI {

    public static String showDate(){
        DateFormat df = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        Date today = Calendar.getInstance().getTime();
        String data = df.format(today);
        return data;
    }

    public static void showText(String txt){
        LCD.write(txt);
    }

    public static  void  showTextTime(String str, long time){
        long a = (currentTimeMillis() + time);
        while (currentTimeMillis() != a) {
            showText(str);
        }
        LCD.clear();
    }

    public static int integerReader(int length,boolean code) {
        char b;
        String g = "";
        String c = "";
        for(int i = 0; i<length; i++)c += "?";
        for (; ; ) {
            String x = "";
            boolean t = false;
            showText(c);
            cursorCoord(2, 4);
            for (int i = 0; i < length; i++) {
                b = KBD.waitKey(5000);
                if (b == '*') {
                    cursorCoord(2, 4);
                    x = "";
                    g = "";
                    showText(c);
                    cursorCoord(2, 4);
                    t = true;
                    break;
                }
                else if (b == KBD.NONE) return -2;
                else if (b == '#')  {
                    return -3;
                }
                else if (code) g += '*';
                        x += b;
                        cursorCoord(2, 4);
                        if (code) showText(g);
                        else showText(x);

                }
                if ((!t)) return Integer.parseInt(x);
            }
        }

    public static void clear(){
        LCD.clear();
    }
    public static void cursorCoord(int x, int y){
        LCD.cursor(x,y);
    }
}
