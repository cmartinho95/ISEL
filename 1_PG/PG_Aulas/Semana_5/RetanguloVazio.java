import java.util.Scanner;

public class RetanguloVazio
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int l, h, i, j; // l - largura, h - altura

        i = 0;
        j = 0;

        System.out.print("Largura? ");
        l = input.nextInt();
        System.out.print("Altura? ");
        h = input.nextInt();

        while (j < l)
        {
            System.out.print("#");
            ++j;
        }

        System.out.println();
        j = 0;

        while (i < (h - 1))
        {
            while (j < l)
            {
                if (j == 0 || j == (l - 1))
                {
                    System.out.print("#");
                }
                else
                {
                    System.out.print(" ");
                }
                ++j;
            }
            j = 0;
            System.out.println();
            ++i;
        }

        j = 0;

        while (j < l)
        {
            System.out.print("#");
            ++j;
        }
        System.out.println();

    }
}
