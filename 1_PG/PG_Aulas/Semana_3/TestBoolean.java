import java.util.Scanner;

public class TestBoolean
{
    public static void main(String[] args)
    {
        /* boolean b1 = true;
        boolean b2 = false;
*/
        Scanner input = new Scanner(System.in);


        int n = input.nextInt();

        int k = input.nextInt();

        boolean r = n < k;

        System.out.println(r);
    }

}
