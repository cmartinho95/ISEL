import java.util.Scanner;

public class Tabuada
{
    /*public static void main(String[] args)
    {
        int i = -1;
        while (i < 4)
        {
            System.out.println(i);
            ++i;
        }
    }
    */
    public static void main(String[] args)
    {

        Scanner input = new Scanner(System.in);

        System.out.print("Tabuada? ");
        int n = input.nextInt();

        int i = 0;
        while (i < 10)
        {
            ++i;
            System.out.println(i + " x " + n + " = " + n * i);
        }


    }
}
