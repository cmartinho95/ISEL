public class Figures{

    public static void main(String[] args){


        int s = 5; int b = 2; int bs = 3;
        writeTree(s,b,bs);

        writeTriangle(5,6);
        writeTriangle(2,3);
        writeRectangle(6,3,5); // chama metodo writeRectangle
        writeRectangle(4,3,9);
        writeRectangle(2,3,13);

        /*for (int l = 0; l < 3; ++l){  //repetido 3x com os outros parametros
            for (int s = 0; s < 6; ++s){
                System.out.print(' ');
            }
            for (int c = 0; c < 5; ++c){
                System.out.print('*');
            }
            System.out.println();
        }*/
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
