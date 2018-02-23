import java.util.Scanner;

public class ParesOrdenados
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int a, b;

        a = 0; b = 0;

        while (a < 4) // altura
        {
            while (b < 5) // largura
            {
                System.out.print(a + "," + b + " ");
                ++b;
            }
            System.out.println();
            ++a;
            b = 0;
        }

    }
}
