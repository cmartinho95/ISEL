import java.util.Scanner;

public class TestNumbers
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();
        int b = input.nextInt();

        if (a>b)
        {
            System.out.println("A maior que B");
        }
        else
        {
            if (a<b)
            System.out.println("A menor que B");

            else
            {
            System.out.println("A igual a B");
            }
        }
    }
}
