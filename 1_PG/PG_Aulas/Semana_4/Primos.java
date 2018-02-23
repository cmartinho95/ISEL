import java.util.Scanner;

public class Primos
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n, i;
        boolean primo;

        System.out.print("Número? ");
        n = input.nextInt();

        i = 2;
        primo = true;

        while (i < n)
        {
            if (n % i == 0)
            {
                primo = false;
                break;
            }

            ++i;
        }

        if (primo == true)
        {
            System.out.println("É primo.");
        }
        else
        {
            System.out.println("Não é primo.");
        }


    }
}
