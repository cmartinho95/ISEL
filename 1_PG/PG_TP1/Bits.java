import java.util.Scanner;

public class Bits
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int bits, x, y;
        String unit;

        unit = "\0";
        x = 0;

        System.out.print("Bits (1..40)? ");
        bits = input.nextInt();


        if (bits <= 10) // bits
        {
            x = 1 << bits;
        }
        else if (bits <= 20) // kilos
        {
            x = 1 << (bits - 10);
            unit = "K";
        }
        else if (bits <= 30) // megas
        {
            x = 1 << (bits - 20);
            unit = "M";
        }
        else // gigas
        {
            x = 1 << (bits - 30);
            unit = "G";
        }

        System.out.println(x + unit + " valores diferentes");
    }
}
