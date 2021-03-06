package grades_v3;

public abstract class ComposedGrade extends Grade{
    protected int nrGrades;
    protected Grade[] grades;

    public ComposedGrade(String description){
        super(description);
        grades = new Grade[10];
    }

    public ComposedGrade(){
        super("Composed"); // = a this("Composed")
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

}
