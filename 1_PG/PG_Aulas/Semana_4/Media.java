import java.util.Scanner;

public class Media
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        float n, i, total, inserido;

        System.out.print("N? ");
        n = input.nextInt();

        i = 0;
        total = 0;

        while (i < n)
        {
            i++;
            inserido = input.nextInt();
            total += inserido;
        }
        System.out.println("A soma é: " + (int)total);
        System.out.println("A média é: " + total / n);
    }
}
