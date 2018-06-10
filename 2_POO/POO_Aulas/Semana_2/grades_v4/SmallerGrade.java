package grades_v4;

public class SmallerGrade extends ComposedGrade{

    public SmallerGrade(String description){
        super(description);
    }

    public int getValue(){
        int smallervalue = -1; // -1 nota invalida

        for (int i = 0; i < nrgrades; i++){
            if (smallervalue < grades[i].getValue()){
                smallervalue = grades[i].getValue();
            }
        }
        return smallervalue;
    }
}
