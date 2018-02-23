import java.util.Scanner;

public class Abs
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        if (n < 0)
        {
            n=-n;
        }

        System.out.println(n);

    }

}
