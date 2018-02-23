package grade_v1;

public abstract class Grade{
    private String description;

    protected Grade (String description){
        this.description = description;
    }
    public abstract int getValue();

    public String toString(){
        return description + " > " + getValue();
    }
    public void list(String prefix){
        System.out.println(prefix + toString()); //ou:
        //System.out.println(prefix + this); - mesmo efeito
    }
}
