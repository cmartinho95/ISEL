package grades_v3;

public class GreaterGrade extends ComposedGrade{

    public GreaterGrade(String description){
        super(description);
    }

    public int getValue(){
        int greatervalue = -1; // -1 nota invalida

        for (int i = 0; i < nrGrades; i++){
            if (greatervalue < grades[i].getValue()){
                greatervalue = grades[i].getValue();
            }
        }
        return greatervalue;
    }
}
