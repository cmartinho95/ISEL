import java.util.Scanner;

public class CharPosition
{
    public static void main(String[] args)
    {
        char c1,c2;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Letra minúscula? ");
        c1 = teclado.next().charAt(0);

        System.out.println("Posição no alfabeto: " + (int)(c1-'a'+1));
        System.out.println("Posição em Unicode: " + (int)(c1));

        System.out.println("Letra maiúscula? ");
        c2 = teclado.next().charAt(0);

        System.out.println("Posição no alfabeto: " + (int)(c2-'A'+1));
        System.out.println("Posição em Unicode: " + (int)(c2));

    }

}
