import java.util.Scanner();

public class Figures0{

    public static Scanner input = new Scanner(System.in);
    //para evitar estar sempre a passar o Scanner input como parametro dum metodo

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        int s = getInt("Spaces ?"/*, input*/);
        int b = getInt("Branches ?"/*, input*/);
        int bs = getInt("Branch Size? "/*, input*/);

        writeTree(s,b,bs);


        /*do {
            System.out.println("Spaces?");
            s = input.nextInt();
        } while(s < 0);

        int b;
        do {
            System.out.println("Branches?");
            b = input.nextInt;
        } while ();

        int bs // blablabla..*/


    }
    public static int getInt(String message /*, Scanner input*/){

        int v;
        do {
            System.out.println(message);
            v = input.nextInt;
        } while (v < 0);
    }


    public static void writeTree(int spaces, int branches, int branchSize){
        for (int b = 0; b < branches; ++b){
            writeTriangle(spaces,branchSize)
        }
        writeRectangle(spaces,2,1);
    }

    public static void writeTriangle(int spaces, int lines){
        for (int l = 0; l < lines; ++l){
            writeLine(spaces - 1, 2 * l + 1)
        }
    }

    public static void writeLine(int spaces, int columns){
        for (int s = 0; s < spaces; ++s){
            System.out.print(' ');
        }
        for (int c = 0; c < columns; ++c){
            System.out.print('*');
        }
        System.out.println();
    }

    public static void writeRectangle(int spaces, int lines, int columns){
        for (int l = 0; l < lines; ++l){
            writeLines(spaces,columns);
        }

    }
}
