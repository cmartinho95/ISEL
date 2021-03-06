package grades_v3;

public abstract class Grade{ // exactamente igual a Grade v1
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
