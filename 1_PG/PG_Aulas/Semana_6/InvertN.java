import java.util.Scanner;

public class InvertN
{
    public static void main(String[] args)
    {
        int i = 0;

        Scanner input = new Scanner(System.in);

        System.out.print("N? ");
        int len = input.nextInt();

        int[] numero = new int[len];

/*        while (i < len)
        {
            numero[i] = input.nextInt();
            i++;
        }


        while (i > 0)
        {
            System.out.println(numero[i - 1]);
            i--;
        }

    */

        for (i = 0; i < len; ++i)
        {
            numero[i] = input.nextInt();
        }

        for (i = len; i > 0; --i)
        {
            System.out.println(numero[i - 1]);
        }
//        System.out.println(numero[]);

    }
}
