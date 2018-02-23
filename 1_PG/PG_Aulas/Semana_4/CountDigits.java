import java.util.Scanner;

public class CountDigits
{
    public static void main (String[] args)
    {
        Scanner input = new Scanner(System.in);

        String s1;
        int len, i, count, countl, countL;
        char c;

        System.out.println("String? ");
        s1 = input.nextLine();

        len = s1.length();
        i = 0;
        count = 0;
        countl = 0;
        countL = 0;

        while (i < len)
        {
            c = s1.charAt(i);

            if (c >= '0' && c <= '9')
            {
                ++count;
            }

            if (c >= 'A' && c <= 'Z')
            {
                ++countL;
            }

            if (c >= 'a' && c <= 'z')
            {
                ++countl;
                c = c + ('A' - 'a');
            }

            ++i;
        }

        System.out.println("Algarismos: " + count);
        System.out.println("Letras minúsculas: " + countl);
        System.out.println("Letras maiúsculas: " + countL);

    }
}
