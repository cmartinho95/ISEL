package grade_v0;

public class Main{
    public static void main(String[] args){
        Grade g = new Grade("Teste");
        g.setValue(12);
        System.out.println(g);
        System.out.println("-----");
        g.list("** ");
    }
}
