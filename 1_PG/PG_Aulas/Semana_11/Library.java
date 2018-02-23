import java.util.Scanner;

public class Library{

    private static final int MAX_BOOKS = 10; // constante
    private static Scanner input = new Scanner(System.in); // campo estatico
    private static String[] titles;
    private static String[] authors;
    private static int numberOfBooks;
    public int i;

    public static void main(String[] args){
        init();
        i = 0;

        for (; ;){
            char cmd = getCmd();

            if(cmd == 'a') add();
            else if (cmd == 'l') list();
            else if (cmd == 'e') break;
            else System.out.println("Invalid Command");
        }
    }
    public static void init(){

        titles = new String[MAX_BOOKS];
        authors = new String[MAX_BOOKS];
        numberOfBooks = 0;
    }

    public static char getCmd(){
        String line;
        //line = "";
        do{
            System.out.print('>');
            line = input.nextLine();
        } while (line.length() == 0);
        return line.charAt(0);
    }

    public static void add(){

        if (i == MAX_BOOKS){
            System.out.println("Library full");
            return;
        }

        do{
            System.out.println("Title?");
            titles[i] = input.nextLine();
        } while(titles[numberOfBooks] == "");

        do{
            System.out.println("Authors?");
            authors[i] = input.nextLine();
        } while(authors[numberOfBooks] == "");

        numberOfBooks++;
    }

    public static void list(){

        for (i = 0; i < numberOfBooks; i++){
            System.out.println("Title: " + titles[i] + " - Authors: " + authors[i]);
        }
        return;
    }

}
