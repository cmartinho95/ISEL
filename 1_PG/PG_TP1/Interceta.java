import java.util.Scanner;

public class Interceta
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int a1, a2, b1, b2;

        System.out.print("Intervalo A? ");
        a1 = input.nextInt();
        a2 = input.nextInt();

        System.out.print("Intervalo B? ");
        b1 = input.nextInt();
        b2 = input.nextInt();

        if ((b1 > a2) || (a1 > b2)) //nao se intercetam
        {
            System.out.println("Não se intercetam.");
        }

        // intercetam-se
        // um contido no outro
        else if (b1 >= a1 && b2 <= a2) // B contido em A
        {
            System.out.println("AxB = [" + b1 + "," + b2 + "]");
            System.out.println("B contido em A");
        }
        else if (a1 >= b1 && a2 <= b2) // A contido em B
        {
            System.out.println("AxB = [" + a1 + "," + a2 + "]");
            System.out.println("A contido em B");
        }

        // intercetam num ponto
        else if (b1 == a2) // ponto (a2,a2) ou (b1,b1)
        {
            System.out.println("AxB = [" + a2 + "," + a2 + "]");
        }
        else if (a1 == b2) // ponto (a1,a1) ou (b2,b2)
        {
            System.out.println("AxB = [" + a1 + "," + a1 + "]");
        }

        // intercetam mas nao num ponto nem um contem o outro
        else if (b2 > a2 && b1 > a1) // intercecao começa em b1 e acaba em a2
        {
            System.out.println("AxB = [" + b1 + "," + a2 + "]");
        }
        else //if (b2 < a2 && b1 < a1) // intercecao comeca em a1 e acaba em b2
        {
            System.out.println("AxB = [" + a1 + "," + b2 + "]");
        }


    }
}
