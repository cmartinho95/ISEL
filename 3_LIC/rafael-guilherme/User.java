import isel.leic.utils.Time;

import java.util.concurrent.TimeUnit;

public class User{

    public String name;
    public int user;
    public int code;
    public float time;
    public float lastEntrance;

    public User(String linha){
        String[] dividida = linha.split(";");
        this.user = Integer.parseInt(dividida[0]);
        this.code = Integer.parseInt(dividida[1]);
        this.name = dividida[2];
        this.time = convertToMillis(Float.parseFloat(dividida[3]));
        float d = (float) System.currentTimeMillis();
        lastEntrance = (this.time==0)? 0: (d - this.time);
    }

    private float convertToMillis(float v) {
        return (v*60*60*1000);
    }
    public static String convertToHours(float v){
        return String.format("%02d.%02d", TimeUnit.MILLISECONDS.toHours((long)v), TimeUnit.MILLISECONDS.toMinutes((long)v) -
                TimeUnit.HOURS.toMinutes(TimeUnit.MILLISECONDS.toHours((long)v)));
    }



    public String getName() {
        return this.name;
    }

    public float getTime() {
        return this.time;
    }

    public int getCode() {
        return this.code;
    }

    public void  setLastEntrance(float lastEntrance){this.lastEntrance = lastEntrance;}

    public int getUser() {
        return this.user;
    }
    public String toString(){
        return (this.user+":"+this.name+":"+this.lastEntrance);
    }
}