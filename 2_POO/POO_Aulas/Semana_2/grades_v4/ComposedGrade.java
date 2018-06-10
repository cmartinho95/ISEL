package grades_v4;

public abstract class ComposedGrade extends Grade{
    protected int nrgrades;
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
        if (nrgrades >= grades.length) increaseCapacity();
        grades[nrgrades++] = g; // igual a:
        /*
        grades[nrGrades] = g;
        nrGrades++;
        */
    }
    private void increaseCapacity(){
        Grade[] aux = new Grade[2 * grades.length];
        System.arraycopy(grades, 0, aux, 0, nrgrades);
        grades = aux;
    }
    public void list(String prefix){
        super.list(prefix);
        for (int i = 0; i < nrgrades; i++){
            grades[i].list(prefix + prefix);
        }
    }

    public boolean equals(Object o){
        if (!(o instanceof ComposedGrade)) return false;
        ComposedGrade g = (ComposedGrade)o;

        if(!super.equals(g)) return false; // verifica description e getValue
        if(!(this.nrgrades == g.nrgrades)) return false;

        for (int i = 0; i < nrgrades; i++){
            if (grades[i].equals(g.grades[i])) return false;
        }
        return true;
    }
}
