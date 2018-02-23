import java.util.Scanner;
import java.lang.Math;

public class NotaFinal
{

    public static void main (String[] args)
    {

        float f1, f2, f3, f4, fmin, media, teste, discussao;
        int notafinal;
        Scanner input = new Scanner(System.in);

        System.out.println("Nota do teste? ");
        teste = input.nextInt();

        System.out.println("Nota da discussão? ");
        discussao = input.nextInt();

        System.out.println("Nota da ficha 1? ");
        f1 = input.nextInt();

        System.out.println("Nota da ficha 2? ");
        f2 = input.nextInt();

        System.out.println("Nota da ficha 3? ");
        f3 = input.nextInt();

        System.out.println("Nota da ficha 4? ");
        f4 = input.nextInt();

        fmin = Math.min(f1,f2);
        fmin = Math.min(fmin, f3);
        fmin = Math.min(fmin,f4);

        media = (f1+f2+f3+f4-fmin)/ 3;

        notafinal = (int)(0.2f * media + 0.4f * teste + 0.4f * discussao + 0.5f);
        System.out.println("Nota final: " + notafinal);

    }
}
