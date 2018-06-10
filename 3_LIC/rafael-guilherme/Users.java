

import java.sql.Time;
import java.time.*;
import java.io.IOException;
import java.util.Calendar;
import java.util.concurrent.TimeUnit;

public class Users {

    public static User[] lista = new User[App.maxUsers];
    public static final String file_name = "C:\\Users\\Guilherme\\Desktop\\USERS.txt";
    private static final int ERROR = -1;

    public static void main(String[] args) {
        loadPersons();
        updateUsers();
    }

    public static void updateUsers() {
            try{
                FileAccess data = new FileAccess(file_name);
                FileAccess data2 = new FileAccess(file_name, true);
                String TextLine;
                int i = 0;
                for (User a : lista){//data.readLines();
                    if (a != null){
                        TextLine = a.user + ";" + a.code + ";" + a.name + ";" + User.convertToHours(a.time);
                        if (i == 1)data.writeToFile(TextLine);
                        else data2.writeToFile(TextLine);
                    }
                    i++;
                }
            }
            catch (IOException e) {
                System.out.print("FILE ERROR - WRITING");
            }
        }


    public static void addPerson(User user) { // para ser usado na manutenção
            lista[user.user] = user;
    }


    public static void loadPersons(){
        try{
            FileAccess data = new FileAccess(file_name,true);
            String [] lines = data.OpenFile();
            String [] divided_line;
            for(String line : lines){
                divided_line = line.split(";");
                lista[Integer.parseInt(divided_line[0])] = new User(line);
            }
        }
        catch (IOException e){
            System.out.print("FILE ERROR - LOADING");
        }
    }

    public static int getUserPassword(int user){
        if(lista[user] != null) {
            return lista[user].code;
        }
        return ERROR;
    }

    public static String getUserName(int user){
        if (lista[user] != null) {
            return lista[user].name;
        }
        return "ERROR";
    }



    public static String getTimeSpent(int user){
        float a = lista[user].lastEntrance;
        lista[user].time  = (System.currentTimeMillis() - a);
        return String.format("%02d.%02d",TimeUnit.MILLISECONDS.toHours((long)lista[user].time), TimeUnit.MILLISECONDS.toMinutes((long)lista[user].time) -
                TimeUnit.HOURS.toMinutes(TimeUnit.MILLISECONDS.toHours((long)lista[user].time)));

    }

    public static void setTimeOfEntrance(int user){
        lista[user].lastEntrance = System.currentTimeMillis();
        lista[user].time = 0.01f;
    }

    public static float getUserTimeSpent(int user){
        if (lista[user] != null) {
            return lista[user].time;
        }
        return ERROR;
    }

    public static void ResetTime(int user) {
        lista[user].time = 0;
    }
    public static boolean isIn(int user){
        return (Users.getUserTimeSpent(user) != 0);
    }

    public static void setUserPassword(int currentUser, int newCode) {
       lista[currentUser].code = newCode;
    }

    public static void ResetLastEntrance(int currentUser) {
        lista[currentUser].lastEntrance = 0;
    }

    public static int getFirstSpot() {
        for(int i = 1; i<lista.length;i++){
            if(lista[i]==null) return i;
        }
        return -1; //ñ se pode adicionar mais galera
    }

    public static void deleteUser(int user) {
        lista[user]= null;
    }
   /* public static String getUser(int user){
        if(lista[user]!= null){
            return lista[user].code + " " + lista[user].name + " " + lista[user].time;
        }
        return ""+ERROR;
    }*/
}
