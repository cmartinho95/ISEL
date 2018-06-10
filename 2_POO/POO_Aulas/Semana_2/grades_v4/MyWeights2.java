package grades_v4;

public class MyWeights1 implements WeightedFunction{
    private double[] a = new double[];

    public double getWeight(int i){
        return 0.5;
    }
    public int numberOfWeights(){
        return 2;
    }
}
