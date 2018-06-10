package grades_v4;

public class GreaterGrade extends ComposedGrade{

    public GreaterGrade(String description){
        super(description);
    }

    public int getValue(){
        int greatervalue = -1; // -1 nota invalida

        for (int i = 0; i < nrgrades; i++){
            if (greatervalue < grades[i].getValue()){
                greatervalue = grades[i].getValue();
            }
        }
        return greatervalue;
    }
}
