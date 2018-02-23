import java.util.Scanner;

public class Troco
{
    public static void main (String[] args)

    {
        int preco, pago, demasia, cinquenta, dez, um;

        Scanner input = new Scanner(System.in);

        System.out.println("Introduza preço em cêntimos: ");
        preco = input.nextInt();

        System.out.println("Introduza valor pago em cêntimos: ");
        pago = input.nextInt();

        demasia = pago - preco;
        System.out.println("Demasia = " + demasia);

        cinquenta = demasia / 50;
        demasia = demasia % 50;
        dez = demasia / 10;
        demasia = demasia % 10;
        um = demasia;

        System.out.println("Troco:");

        System.out.println("Moedas 50c = " + cinquenta);

        System.out.println("Moedas 10c = " + dez);

        System.out.println("Moedas 1c = " + um);

    }
}
