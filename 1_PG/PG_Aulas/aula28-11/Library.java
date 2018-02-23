import java.util.Scanner;

public class Library {

    private static final int MAX_BOOKS = 10;
    private static Scanner input = new Scanner(System.in);
    private static Book[] books;
    private static int numberOfBooks;

    public static void main(String[] args){
        init();
        //TODO switch
        for(;;){
            char cmd = getCmd();
            if(cmd == 'a') add();
            else if(cmd =='l') list();
            else if(cmd =='s' ) search();
            else if(cmd == 'e') break;
            else System.out.println("Invalid Command");
        }
    }

    private static void search() {

        System.out.println("Title?");
        String title = input.nextLine();
        int index = indexOf(title);
        if(index == -1){
            System.out.println("No book available");
        }else{
            System.out.println(books[index].toString());
        }
    }

    private static int indexOf(String title) {

        for(int i=0; i < numberOfBooks; ++i){
            if(books[i].hasTitle(title))
                return i;
        }
        return -1;
    }

    private static void init(){
        books = new Book[MAX_BOOKS];
        numberOfBooks=0;
    }

    private static char getCmd() {
        String line;
        do{
            System.out.print('>');
            line = input.nextLine();

        }while(line.length()==0);
        return line.charAt(0);

    }

    private static void add() {

        if(numberOfBooks==MAX_BOOKS) {
            System.out.println("Library full");
            return;
        }
        System.out.println("Title?");
        String title = input.nextLine();
        System.out.println("Authors?");
        String author = input.nextLine();
        Book b = new Book(title,author);

        books[numberOfBooks] = b;
        numberOfBooks++;
    }

    private static void list() {
        for(int i=0; i<numberOfBooks ;++i){
            Book b = books[i];
            System.out.println(b);
        }

    }

}
