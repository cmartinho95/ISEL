package grades_v2;

public class Main{
    public static void main(String[] args){
        SimpleGrade teste1 = new SimpleGrade("1.º teste", 12);
        Grade teste2 = new SimpleGrade("2.º teste", 14);
        GreaterGrade melhor = new GreaterGrade("Melhor avaliação");

        melhor.addGrade(teste1);
        melhor.addGrade(teste2);
        melhor.list("*");

        SimpleGrade p1 = new SimpleGrade("p1", 10);
        SimpleGrade p2 = new SimpleGrade("p2", 15);
        GreaterGrade melhorP = new GreaterGrade("Prática");

        melhorP.addGrade(p1);
        melhorP.addGrade(p2);
        melhor.addGrade(melhorP);
        melhor.getValue();
        melhor.list("*");
    }
}
