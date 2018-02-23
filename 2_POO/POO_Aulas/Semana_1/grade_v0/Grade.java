package grade_v0;

public class Grade{
    private String description;
    private int value;
    public Grade (String description){
        this.description = description;
    }
    public int getValue(){
        return value;
    }
    public void setValue(int value){
        this.value = value;
    }
    public String toString(){
        return description + " > " + getValue();
    }
    public void list(String prefix){
        System.out.println(prefix + toString());
    }
}
