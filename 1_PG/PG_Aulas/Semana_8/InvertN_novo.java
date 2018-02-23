import java.util.Scanner;

public class InvertN_novo
{
    public static void main(String[] args)
    {
        int i = 0;

        Scanner input = new Scanner(System.in);

        int[] numbers = new int[2];
        int counter = 0;

        int value;

        while ((value = input.nextInt()) >= 0)
        {
            if(counter == numbers.length)
            {
                int[] newArray = new int[numbers.length * 2];
                for(int i = 0; i < numbers.length; ++i) //copiar o q ta em numbers pra newArray
                {
                    newArray [i] = numbers[i];
                }
                numbers = newArray; // redirecionar numbers pro newArray
            }

            numbers[counter] = value;
            ++counter;
        }

        /*
        = a:

        while (value < numbers.length)
        {
        value = input.nextInt();
        if(value < 0) break;
        numbers[counter] = value;
        ++counter;
        }
        */


        while (i > 0)
        {
            System.out.println(numero[i - 1]);
            i--;
        }


        for (i = 0; i < len; ++i)
        {
            numero[i] = input.nextInt();
        }

        for (i = counter; i >= 0; --i)
        {
            System.out.println(numero[i - 1]);
        }
//        System.out.println(numero[]);

    }
}
