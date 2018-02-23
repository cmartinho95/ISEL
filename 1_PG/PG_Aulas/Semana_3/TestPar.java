import java.util.Scanner;

public class TestPar
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        boolean r = n%2 == 0;

        if (r)
        {
            System.out.println("Par");
        }
        else
        {
            System.out.println("Ímpar");

        }



    }

}
