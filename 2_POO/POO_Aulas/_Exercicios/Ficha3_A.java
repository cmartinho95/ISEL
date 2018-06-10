public class Ficha3_A{

    public int x;
    public String name;

    public Ficha3_A(int val) {
        x = val;
    }

    public int getX(){
        return x;
    }

    public void m() {
        System.out.println("x = " + x);
    }

    public void setX(int v){
        x = v;
    }

    public class B{
        public int y;
        public String surname;

        public B(int i, String s){
            y = i;
            surname = s;
        }

        public String getSurname(){
            return surname;
        }
    }
}
