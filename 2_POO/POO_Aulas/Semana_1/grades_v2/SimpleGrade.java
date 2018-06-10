package grades_v2;

public class SimpleGrade extends Grade{
    private int value;

    public SimpleGrade(String description, int value){
        super(description);
        this.value = value;
    }
    public int getValue(){
        return value;
    }
}
