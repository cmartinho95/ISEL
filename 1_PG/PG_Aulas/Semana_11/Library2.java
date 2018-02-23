import java.util.Scanner;

public class Library2{

    private static final int MAX_BOOKS = 10; // constante
    private static Scanner input = new Scanner(System.in); // campo estatico
    private static Book[] books;
    private static int numberOfBooks;
    //private static int i;

    public static void main(String[] args){
        init();

        for (;;){
            char cmd = getCmd();

            if(cmd == 'a') add();
            else if (cmd == 'l') list();
            else if (cmd == 's') search();
            else if (cmd == 'e') break;
            else System.out.println("Invalid Command");
        }
    }
    private static void search(){
        System.out.println("Title? ");
        String title = input.nextLine();
        int index = indexOf(title);
        if (index == -1){
            System.out.println("No book available");
        }
        else{
            System.out.println(books[index].toString()); // imprime info do livro com esse indice
        }
    }

    private static int indexOf(String title){
        for (int i = 0; i < numberOfBooks; i++){
            if(books[i].hasTitle(title)){
                return i;
            }
        }
        return -1;
    }

    public static void init(){

        books = new Book[MAX_BOOKS]; //array bidimencional (pq classe Book tem 2 parametros)
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

        String title, author;

        if (numberOfBooks == MAX_BOOKS){
            System.out.println("Library full");
            return;
        }

        do{
            System.out.println("Title?");
            title = input.nextLine();
        } while(title == "");

        do{
            System.out.println("Authors?");
            author = input.nextLine();
        } while(author == "");

        Book b = new Book(title, author);
        books[numberOfBooks] = b;
        numberOfBooks++;
    }

    public static void list(){
        for (int i = 0; i < numberOfBooks; i++){
            Book b = books[i];
            //System.out.println("Title: " + b.title + " - Authors" + b.author);
            System.out.println(b); // se toString esta definido b = b.toString;
        }
    }

}
