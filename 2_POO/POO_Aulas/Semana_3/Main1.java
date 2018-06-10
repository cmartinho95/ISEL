public class Main1{

    public static void main(String[] args){
        Box<String> b1 = new Box<String>();
        Box<Grade> b2 = new Box<Grade>();

        b1.set("xpto");
        SimpleGrade s = new SimpleGrade("T1", 12);
        b2.set(s);
        Grade x = b2.get();
        x.getValue();
    }
}
