import java.util.Scanner;

public class Algarismos
{

    public static void main(String[] args)
    {

        int numero,milhares,centenas,dezenas,unidades;
        Scanner input = new Scanner(System.in);

        System.out.print("Insira número entre 1000 e 9999: ");
        numero = input.nextInt();

        unidades = numero % 10;
        numero = numero / 10;

        dezenas = numero % 10;
        numero = numero / 10;

        centenas = numero % 10;
        numero = numero / 10;

        milhares = numero % 10;
        

        System.out.println(unidades);
        System.out.println(dezenas);
        System.out.println(centenas);
        System.out.println(milhares);

    }
}
