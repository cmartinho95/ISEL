import java.util.Scanner;

public class Test3Par
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int i1, i2, i3, i4;

        i4 = 0;

        System.out.println("Número 1? ");
        i1 = input.nextInt();

        System.out.println("Número 2? ");
        i2 = input.nextInt();

        System.out.println("Número 3? ");
        i3 = input.nextInt();


        if (i1%2 == 0)
        {
            ++i4;
        }
        if (i2%2 == 0)
        {
            ++i4;
        }
        if (i3%2 == 0)
        {
            ++i4;
        }

        System.out.println("Existem " + i4 + " número(s) par(es).");

    }


}
