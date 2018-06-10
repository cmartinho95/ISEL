package grades_v4;

public class MyWeights1 implements WeightedFunction{
    private double[] a = new double[]{0.4, 0.6};

    public double getWeight(int i){
        return a[i];
    }
    public int numberOfWeights(){
        return a.length;
    }
}
