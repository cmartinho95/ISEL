import java.util.Scanner;

public class Retangulo
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

        while (i < h)
        {
            while (j < l)
            {
                System.out.print("#");
                ++j;
            }
            System.out.println();
            ++i;
            j = 0;
        }
    }
}
