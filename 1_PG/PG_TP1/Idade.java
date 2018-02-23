import java.util.Scanner;
import java.time.LocalDate;

public class Idade
{
    public static void main(String[] args)
    {
        int day, month, year, daynow, monthnow, yearnow, age;
        // daynow, monthnow e yearnow: dia, mes e ano hoje

        Scanner input = new Scanner(System.in);

        LocalDate today = LocalDate.now();
        yearnow = today.getYear();
        monthnow = today.getMonthValue();
        daynow = today.getDayOfMonth();

        System.out.println("Nascimento? ");
        day = input.nextInt();
        month = input.nextInt();
        year = input.nextInt();

        // ja fez anos
        if ((month < monthnow) || (month == monthnow && day < daynow))
        {
            age = yearnow - year;
            System.out.println("Tem " + age + " anos.");
        }
        // ainda vai fazer anos
        else if ((month > monthnow) || (month == monthnow && day > daynow))
        {
            age = yearnow - 1 - year;
            System.out.println("Tem " + age + " anos.");
        }
        // faz anos hoje
        else
        {
            age = yearnow - year;
            System.out.println("Parabéns, faz " + age + " anos.");
        }
    }
}
