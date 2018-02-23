import java.util.Scanner;

public class Calculadora2
{

    public static void main(String[] args)
    {
        int h,m,s,total;
        Scanner input = new Scanner(System.in);

        System.out.print(Horas ?);
        h=input.nextInt();
        System.out.print(Minutos ?);
        m=input.nextInt();
        System.out.print(Segundos ?);
        s=input.nextInt();

        total = h*3600 + m*60 + s;

        System.out.println("Totl em segundos " + total);
    }
}
