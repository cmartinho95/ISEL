package grades_v4;

public class WeightedGrade extends ComposedGrade{
    private WeightedFunction function;
    public WeightedGrade (String description, WeightedFunction function){
        super(description);
        this.function = function;
    }

    public int getValue(){
        if (nrgrades == 0) return -1;
        int value = 0;
        for (int i = 0; i < nrgrades; i++){
            value += grades[i].getValue() * function.getWeight(i);
        }
        return value;
    }


}
