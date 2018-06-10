import java.io.*;

public class Streams{
    public static void fileCopy(String pathNameIn, String pathNameOut) throws IOException, FileNotFoundException{
        BufferedReader br = null;
        PrintWriter pw = null;
        try{
            br = new BufferedReader(new FileReader(pathNameIn));
            pw = new PrintWriter(pathNameOut);
            String line;
            String[] lines;

            while((line = br.readLine()) != null){
                lines = line.split(" ");

                for(int i = 0; i < lines.length; i++){
                    pw.printf(lines[i] + "%n");
                }
            }
        }
        finally{
            if (br != null) br.close();
            if (pw != null) pw.close();
        }
    }

    public static void main(String[] args){
        try{
            fileCopy("alunos.txt","alunos2.txt");

        }
        catch(Exception e){
            System.out.println("error: " + e.getMessage());
            e.printStackTrace();
        }
    }

}
