package grades_v2;

public class GreaterGrade extends Grade{
    private int nrGrades;
    private Grade[] grades;

    public GreaterGrade(String description){
        super(description);
        grades = new Grade[10];
    }
    public void addGrade(Grade g){
        if (nrGrades >= grades.length) increaseCapacity();
        grades[nrGrades++] = g; // igual a:
        /*
        grades[nrGrades] = g;
        nrGrades++;
        */
    }
    private void increaseCapacity(){
        Grade[] aux = new Grade[2 * grades.length];
        System.arraycopy(grades, 0, aux, 0, nrGrades);
        grades = aux;
    }
    public void list(String prefix){
        super.list(prefix);
        for (int i = 0; i < nrGrades; i++){
            grades[i].list(prefix + prefix);
        }
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
