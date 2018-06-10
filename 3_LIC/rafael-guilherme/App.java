import isel.leic.utils.Time;

import java.awt.desktop.UserSessionEvent;
import java.io.IOException;
import java.util.Scanner;

public class App {
    public static final int COD_LENGTH = 4;
    public static final int USER_LENGTH= 3;
    private static int currentCode;
    public static String tempo = TUI.showDate();
    private static int currentUser;
    public static int maxUsers = 1000;
    private static int DOOR_OPEN_TIME = 3000;
    private static int MESSAGE_TIME = 3000;
    private static float ResetWorkTime = 0;
    private static  int APAGAR = -2;
    private static int MUDAR = -3;


    public static void main(String[] args) {
        HAL.init();
        SerialEmitter.init();
        KBD.init();
        LCD.init();
        Users.loadPersons();
        while (true) {
            for (;;) {
                Log.readLogs();
                if (M.isOn()) maintenance();
                setUser();
                if (currentUser == APAGAR) {
                    break;
                }
                else if(currentUser == MUDAR){
                    changePassword();
                    break;
                }
                setCode();
                if (currentCode == APAGAR) {
                    break;
                }
                else if(currentCode == MUDAR){
                   changePassword();
                    break;
                }
                else if (Users.getUserName(currentUser).equals("ERROR")){
                    TUI.clear();
                    TUI.showText("User not found             ");
                    Time.sleep(MESSAGE_TIME);
                    break;
                }
                else if(currentCode != Users.getUserPassword(currentUser)){
                    TUI.clear();
                    TUI.showText("wrong password           ");
                    Time.sleep(MESSAGE_TIME);
                    break;
                }
                TUI.clear();
                if(!Users.isIn(currentUser)) {
                    Users.setTimeOfEntrance(currentUser);
                    TUI.cursorCoord(0, 0);
                    TUI.showText("Boas, parceiro          ");
                    TUI.cursorCoord(2, 0);
                    TUI.showText(Users.getUserName(currentUser) + "        ");
                    Log.addLog(currentUser, Users.getUserName(currentUser));
                }
                else {
                    Log.addLog(currentUser, Users.getUserName(currentUser));
                    TUI.cursorCoord(0, 0);
                    TUI.showText("Horas Trabalho:");
                    TUI.cursorCoord(2, 0);
                    TUI.showText(Users.getTimeSpent(currentUser));
                    Users.ResetTime(currentUser);
                    Users.ResetLastEntrance(currentUser);
                }
                Door.open(14);
                Time.sleep(DOOR_OPEN_TIME);
                Door.close(14);
                Users.updateUsers();
            }
        }
    }

    public static void changePassword() {
        setUser();
        while(currentUser == -2 || currentUser == -3){
            setUser();
        }
        setCode();
        while(currentCode == -2 || currentCode == -3){
            setCode();
        }
        TUI.clear();
        if (Users.getUserPassword(currentUser) == currentCode) {
            TUI.showText(TUI.showDate());
            currentCode = -2;
            TUI.cursorCoord(2,0);
            TUI.showText("PIN:");
            while (currentCode == -2 || currentCode == -3) {
                TUI.clear();
                TUI.showText(TUI.showDate());
                TUI.cursorCoord(2,0);
                TUI.showText("PIN:");
                currentCode = TUI.integerReader(COD_LENGTH, false);
                TUI.clear();
                Users.setUserPassword(currentUser, currentCode);
            }
        }
        Users.updateUsers();
    }



    public static void maintenance(){
        TUI.clear();
        TUI.showText("Out of service");
        System.out.println("command: NEW  DEL  LST or OFF");
        Scanner in = new Scanner(System.in);
        while(true) {
            System.out.print("Maintenance> ");
            String dd = in.next();
            in.nextLine();   // o next() nao consome a mudança de linha. Tem que se pedir o nxtLine por isso
            if (dd.equals("OFF") || dd.equals("off")) {
                System.exit(0);
            }
            else if (dd.equals("NEW") || dd.equals("new")) {
                System.out.print("User name? ");
                String a = in.nextLine();
                System.out.print("PIN? ");
                int b = in.nextInt();
                int c = Users.getFirstSpot();
                User ssd = new User(c + ";" + b + ";" + a + ";" + "0.0");
                Users.addPerson(ssd);
                Users.updateUsers();
                System.out.println("added user: " + ssd.user+":"+ssd.name );
            }
            else if (dd.equals("LST") || dd.equals("lst")) {
                for(int i =0; i<Users.lista.length; i++ ){
                    if(Users.isIn(Users.lista[i].getUser())){
                        System.out.println(Users.lista[i].toString());
                    }
                }
            }
            else if (dd.equals("del") || dd.equals("DEL")) {
                System.out.print("UIN?");
                int user = in.nextInt();
                String b = Users.getUserName(user);
                if (!b.equals("ERROR")) {     //batota pra não criar um metodo pra ver se a posição está nula. não se vai usar o toString pq ao usar a string "b" só se vai ao
                    // metodo uma vez e se tem a informação toda
                    System.out.println("remove user: " + user + ":" + b + "\nY/N?");
                    String ddd= in.next();
                    if (ddd.equals("Y") || ddd.equals("y")) {
                        Users.deleteUser(user);
                        Users.updateUsers();
                        System.out.println("User deleted");
                    }
                    else {
                        System.out.println("command aborted");
                    }
                }
            }
            else {
                System.out.print("invalid command");
            }
        }
    }

    public static void setCode(){
        TUI.clear();
        TUI.showText(TUI.showDate());
        TUI.cursorCoord(2, 0);
        TUI.showText("PIN:");
        currentCode = TUI.integerReader(COD_LENGTH,true);
    }

    public static void setUser(){
        TUI.clear();
        TUI.cursorCoord(0,0);
        TUI.showText(TUI.showDate());
        TUI.cursorCoord(2, 0);
        TUI.showText("UIN:");
        currentUser = TUI.integerReader(USER_LENGTH,false);
    }
}
