import java.util.Scanner;

public class TestChar_repetido
{

    public static void main(String[] args)
    {
        char i1;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Caracter? ");
        i1 = teclado.next().charAt(0);

        System.out.println("Unicode = " + (int)i1);
        //System.out.println("Unicode seguinte " + (int)(i1 + 1));

    }
}
