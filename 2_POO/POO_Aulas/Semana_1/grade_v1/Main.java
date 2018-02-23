package grade_v1;

public class Main{
    public static void main(String[] args){
        SimpleGrade teste1 = new SimpleGrade("1.º teste", 12);
        Grade teste2 = new SimpleGrade("2.º teste", 14);

        System.out.println(teste1); // = teste1.toString()
        System.out.println("-----");
        teste2.list("** ");
    }
}
