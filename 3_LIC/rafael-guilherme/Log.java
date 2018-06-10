import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Log {

    public static final String file_name = "C:\\Users\\Guilherme\\Desktop\\Log.txt";
    private static String[] logs = new String[1000];
    private static int counter = 0;

    public static void loadLog(){
        try{
            FileAccess data = new FileAccess(file_name,true);
            String [] lines = data.OpenFile();
            int i = 0;
            for(String line : lines){
                logs[i] = line;
                i++;
            }
        }
        catch (IOException e){
            System.out.print("FILE ERROR - LOADING");
        }
    }

    public static void saveLog() {
        for (int i = 0; i < logs.length; i++) {
            if (logs[i] != null) {
                String TextLine = logs[i];
                try {
                    FileAccess data = new FileAccess(file_name, true);
                    data.writeToFile(TextLine);
                } catch (IOException e) {
                    System.out.print("FILE ERROR - WRITING");
                }
            }
        }
    }

    public static void readLogs() {
        try {
            FileReader file_to_examine = new FileReader(file_name);
            BufferedReader textCounter = new BufferedReader(file_to_examine);
            while (textCounter.readLine() != null) {
                counter++;
            }
            textCounter.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void addLog(int user, String name) {
        String seta = (Users.isIn(user)) ? "-<" : "->";
        if (logs[counter++] == null) {
            logs[counter] = App.tempo + seta + user + ":" + name+"\n";
        }
    }


    public static String getLastDate(int user) {
        String [] divided_line;
        String [] divided_line2;
        String data = "";
        for (String line : logs) {
            divided_line = line.split(" ");
            divided_line2 = divided_line[3].split(":");
            if (Integer.parseInt(divided_line2[0]) == user){
                data = divided_line[0];
            }
        }
        return data;
    }
}
