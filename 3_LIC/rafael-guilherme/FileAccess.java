import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;

public class FileAccess {

    private String path;
    private boolean append_to_file = false;

  /*  public static void main(String[] args)throws IOException {
        FileAccess co = new FileAccess("C:\\Users\\Guilherme\\Desktop\\USERS.txt", true);
        co.writeToFile("teste") ;
        FileAccess co2 = new FileAccess("C:\\Users\\Guilherme\\Desktop\\USERS.txt", false);
        co2.writeToFile("teste2");
        co.writeToFile("teste") ;
    }*/

    public FileAccess(String path){
        this.path = path;
    }

    public  FileAccess( String path , boolean append_to_file ) {
        this.path = path;
        this.append_to_file = append_to_file;
    }

    public void writeToFile( String textLine ) throws IOException {
        FileWriter write = new FileWriter(path , append_to_file);
        PrintWriter print_line = new PrintWriter( write );
        print_line.printf("%s" + "%n",textLine);
        print_line.close();
    }

    public String[] OpenFile() throws IOException{
        FileReader fileReader = new FileReader(path);
        BufferedReader textReader = new BufferedReader(fileReader);
        int numberOfLines = readLines();
        String[] textData = new String[numberOfLines];
        for (int i = 0; i < numberOfLines; i++) {
            textData[i] = textReader.readLine();
        }
        textReader.close( );
        return textData;
    }

    public int readLines() throws IOException{
        FileReader file_to_examine = new FileReader(path);
        BufferedReader  textCounter = new BufferedReader(file_to_examine);
        int numberOfLines = 0;
        while (textCounter.readLine() != null) {
            numberOfLines++;
        }
        textCounter.close();
        return numberOfLines;
    }
}
