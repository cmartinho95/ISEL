import java.util.Scanner;

public class IntUtils{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int x;

        System.out.print("Número? ");
        x = input.nextInt();

        System.out.println(Digits(x));
    }

    public static int Digits(int number){
        int i, m, digits;
        i = 0; m = number; digits = 0;

        for (i = 0; number > 0; i++) {
        m = number % 10;
        number /= 10;
        digits++;
        }
        return digits;
    }
    
}
