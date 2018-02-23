import java.util.Scanner;

public class Algarismos2
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n, i, imprimido;

        System.out.println("N? ");
        n = input.nextInt();

        i = 0;

        while (n > 0)
        {
            imprimido = n % 10;
            System.out.println(imprimido);
            n = n / 10;
        }

    }
}
