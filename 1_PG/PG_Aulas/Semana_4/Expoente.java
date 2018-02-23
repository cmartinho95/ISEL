import java.util.Scanner;

public class Expoente
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int base, exp, result;

        System.out.print("Base? ");
        base = input.nextInt();

        System.out.print("Expoente? ");
        exp = input.nextInt();

        result = base;

        while (exp > 1)
        {
            result = result * base;
            exp--;
        }

        if (exp == 0)
        {
            result = 1;
        }

        System.out.println(result);
    }

}
