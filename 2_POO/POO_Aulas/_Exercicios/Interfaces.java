public class Interfaces{

    public interface I{
        String toString();
    }

    private static class C implements I{
        int number;
        String name;

        public C(int n, String s){
            this.number = n;
            this.name = s;
        }

        public String toString(){
            return number + ", " + name;
        }
    }

    public static void main(String[] args){
        I c = new C(44809, "Carlota");

        System.out.println(c);
    }
}
