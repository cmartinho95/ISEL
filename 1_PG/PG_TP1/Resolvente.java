import java.util.Scanner;
import java.lang.Math;

public class Resolvente
{
    public static void main(String[] args)
    {
        float a, b, c, r1, r2, raiz, den, radicand;

        Scanner input = new Scanner(System.in);

        System.out.print("a b c ? ");
        a = input.nextFloat();
        b = input.nextFloat();
        c = input.nextFloat();

        if (a == 0)
        {
            System.out.println("Sem solução.");
        }

        else
        {
            radicand = b * b - 4f * a * c;

            if (radicand < 0)
            {
                System.out.println("Sem solução.");
            }

            else
            {
                raiz = (float)Math.sqrt(radicand);
                den = 2f * a;

                r1 = (-b + raiz) / den; // zero positivo
                r2 = (-b - raiz) / den; // zero negativo

                if (r1 == r2) // apenas 1 zero
                {
                    System.out.println("x = " + r1);
                }
                else
                {
                    System.out.println("x = " + r1);
                    System.out.println("x = " + r2);
                }
            }
        }
    }

}
