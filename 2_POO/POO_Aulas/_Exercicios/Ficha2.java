import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.ArrayList;

public class Ficha2{
    public class Aluno{
        int number;
        String name;

        public Aluno(int n, String s){
            number = n;
            name = s;
        }
    }

    public class Turma{
        ArrayList<Aluno> alunos = new ArrayList<Aluno>();

        public void add(Aluno a){
            alunos.add(a);
        }
    }


    private void saveFile() {
        try {
            OutputStream o = openFileOutput("students.txt");
            PrintStream ps = new PrintStream(o);
            /*
            for(Point p: model.getSetOfPoints().getPoints()) {
                //p.save() - metodo em cada classe de shapes faz println(this) de acordo com as suas priopriedades
                ps.println(p);

            }
            */
            ps.close();
            System.out.println("saved");
        }
        catch(Exception e) {
            System.out.println("Error");
        }
    }

    private void loadFile() {
         //  BufferedReader in = null;
         Scanner in = null;
         String line = null;
         try {
             InputStream i = new FileInputStream("students.txt");
             // in = new BufferedReader(new InputStreamReader(i));
             in = new Scanner(i);
             //   while((line=in.readLine())!=null) {
             while(in.hasNextLine()) {
                 line = in.nextLine();
                 String[] lineElements = line.split(" ");
                 String number = lineElements[0];
                 int n = Integer.parseInt(number);
                 String name = lineElements[2];
             }
             in.close();
         }
         catch(IOException f){

         }
         catch(Exception e){
             System.out.println("erro genérico");
         }
         finally {
             if (in!=null) {
                 in.close();
             }
         }
     }
}
