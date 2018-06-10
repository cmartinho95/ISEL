package grades_v4;

public class SimpleGrade extends Grade{
    private int value;
    //private int weight;

    public SimpleGrade(String description, int value){
        super(description);
        this.value = value;
        //this.weight = weight;
    }
    public int getValue(){
        return value; // * weight;
    }
}
