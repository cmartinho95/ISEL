import java.util.Scanner;

public class TestDigit
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        char c = input.next().charAt(0);

        if (c >= '0' && c<= '9')
        {
            System.out.println("Dígito");
        }
        else if(c >= 'A' && c <= 'Z')
            System.out.println("Letra maiúscula");
        else if(c >= 'a' && c <= 'z')
            System.out.println("Letra minúscula");
        else
        {
            System.out.println("Não é dígito nem letra");
        }
    }
}
