import java.util.Scanner;
public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Indique 4 valores inteiros? ");
        int biggest;

        biggest = 0;

        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();

        if (a < b) {biggest = b;}
        if (b < c) {biggest = c;}
        if (c < d) {biggest = d;}
        if (d < a) {biggest = a;}

        System.out.println(biggest);
    }
}
