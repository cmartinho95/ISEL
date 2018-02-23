import java.util.Scanner;

public class TestString
{
    public static void main (String[] args)
    {
        Scanner input = new Scanner(System.in);

        String s1;
        int len, i;

        System.out.println("String? ");
        s1 = input.nextLine();

        len = s1.length();
        i = 0;

        while (i < len)
        {
            System.out.println(s1.charAt(i));
            ++i;
        }

    }
}
