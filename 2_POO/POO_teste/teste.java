import java.lang.*;
import java.util.*;
import java.io.*;


public class teste {
    public enum Numbers{one, two, three};
    public interface I { void doIt(); }

    public static void main(String[] args) throws IOException{
        //System.out.println(RuntimeException.class instanceof Class);
        //System.out.println(RuntimeException.class instanceof Exception.class);

        // float f = 0.1;
        // double d = 0.8;
        //
        // System.out.println((int)(f + 0.5));
        // System.out.println((int)(d + 0.5));
        // Numbers[] ns = Numbers.values();
        // for (Numbers n : ns){
        //     System.out.println(n.ordinal());
        // }
        // System.out.println(Numbers.valueOf("three"));



        //I i = new I() { public void doIt() { System.out.println(“Did it”); } }
        I i = new I() { public void doIt() { System.out.println(“Did it”); } }

        //read();
    }

    public static void read() throws IOException{

            BufferedReader br = new BufferedReader(new FileReader("lol.txt"));

            String line = null;
            while ((line = br.readLine()) != null){
                System.out.println(line);
            }

    }
}
