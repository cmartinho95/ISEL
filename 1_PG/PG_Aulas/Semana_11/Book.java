public class Book{

    private String title; //nao static, instance.
    private String author;

    public Book(String t, String a){ // construtor com parametros - tem mesmo nome q classe
        this.title = title;
        this.author = author;
    }

    public String toString(){ // this so disponivel em campos de instancia, nao estaticos
        return "Title: " + this.title + " - Authors: " + this.author;
    }

    public boolean hasTitle(String t){
        return this.title.equals(t);
    }

}
