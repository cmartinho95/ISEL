/**
 * Created by cvaz on 19/05/15.
 */
public class B {
    public B(String name) {
        super();
        this.name = name;
    }
    public B() { this("xpto"); }

    private String name;
    protected int anotherName;

    public void m() {
        System.out.println("name="+name);
    }
}
