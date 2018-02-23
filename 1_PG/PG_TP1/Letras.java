import java.util.Scanner;

public class Letras
{

    public static void main(String[] args)
    {
        char l1;

        Scanner input = new Scanner(System.in);
        System.out.print("Letra? ");
        l1 = input.next().charAt(0);

        System.out.println("Unicode = " + (int)l1);

        if (l1 >= 'A' && l1 <= 'Z')
        {
            System.out.println(l1 + " é Maiúscula");
            System.out.println((l1 - 'A' + 1) + ".ª letra do alfabeto");
        }
        else if (l1 >= 'a' && l1 <= 'z')
        {
            System.out.println((l1 - 'a' + 1) + ".ª letra do alfabeto");
            System.out.println("Corresponde ao caracter maiúsculo " + (char)(l1 - 'Z' - 1));
        }
    }
}
