package grades_v4;

public class Main{
    public static void main(String[] args){
        WeightedFunction f1 = new WeightedFunction(){ //classe anonima com objecto unico:
            private double[] a = new double[]{0.4, 0.4, 0.2};

            public double getWeight(int i){
                return a[i];
            }
            public int numberOfWeights(){
                return a.length;
            }
        };

        WeightedFunction f2 = new WeightedFunction(){
            private double[] a = new double[]{0.5,0.5};

            public double getWeight(int i){
                return a[i];
            }
            public int numberOfWeights(){
                return a.length;
            }
        };

        WeightedFunction f3 = new WeightedFunction(){
            private double[] a = new double[]{0.33, 0.33, 0.33};

            public double getWeight(int i){
                return a[i];
            }
            public int numberOfWeights(){
                return a.length;
            }
        };

        SimpleGrade PGt = new SimpleGrade("Teste", 13);
        WeightedGrade PGf = new WeightedGrade("Média fichas", f3);
        SimpleGrade PGf1 = new SimpleGrade("Ficha 1", 15);
        SimpleGrade PGf2 = new SimpleGrade("Ficha 2", 17);
        SimpleGrade PGf3 = new SimpleGrade("Ficha 3", 19);
        PGf.addGrade(PGf1);
        PGf.addGrade(PGf2);
        PGf.addGrade(PGf3);
        SimpleGrade PGp = new SimpleGrade("PG discussão", 12);
        WeightedGrade PG = new WeightedGrade("PG nota final", f1);
        PG.addGrade(PGt);
        PG.addGrade(PGp);
        PG.addGrade(PGf);

        SimpleGrade ALt1 = new SimpleGrade("Teste 1", 10);
        SimpleGrade ALt2 = new SimpleGrade("Teste 2", 15);
        WeightedGrade ALGA = new WeightedGrade("Álgebra nota final", f2);
        ALGA.addGrade(ALt1);
        ALGA.addGrade(ALt2);

        SimpleGrade LSDt = new SimpleGrade("Teste", 12);
        SimpleGrade LSDp = new SimpleGrade("Discussão", 12);
        WeightedGrade LSD = new WeightedGrade("LSD nota final", f2);
        LSD.addGrade(LSDt);
        LSD.addGrade(LSDp);

        SimpleGrade Electrot1 = new SimpleGrade("Teste 1", 16);
        SimpleGrade Electrot2 = new SimpleGrade("Teste 2", 12);
        SimpleGrade Electrotp1 = new SimpleGrade("Trabalho 1", 13);
        SimpleGrade Electrotp2 = new SimpleGrade("Trabalho 2", 12);
        WeightedGrade Electrot = new WeightedGrade("Testes", f2);
        Electrot.addGrade(Electrot1);
        Electrot.addGrade(Electrot2);
        WeightedGrade Electrop = new WeightedGrade("Trabalhos", f2);
        Electrop.addGrade(Electrotp1);
        Electrop.addGrade(Electrotp2);
        WeightedGrade Electronica = new WeightedGrade("Electrónica nota final", f2);
        Electronica.addGrade(Electrop);
        Electronica.addGrade(Electrot);

        PG.list("*");
        ALGA.list("*");
        LSD.list("*");
        Electronica.list("*");

    }
}
