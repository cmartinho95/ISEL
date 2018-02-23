public class Book {

    private String title;
    private String authors;

    public Book(String title, String authors){
        this.title=title;
        this.authors=authors;
    }

    public String toString(){
        return "Title: " + this.title + " - " + "Authors: " + this.authors;
    }

    public boolean hasTitle(String t) {
        return this.title.equals(t);
    }
}
