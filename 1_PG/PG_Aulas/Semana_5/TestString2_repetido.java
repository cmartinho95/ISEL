import java.util.Scanner;

public class TestString2_repetido
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        String line, charsToCount;
        int i, j, count, countReps;

        i = 0;
        j = 1;
        count = 0;
        countReps = 0;

        System.out.println("Line? ");
        line = input.nextLine();
        System.out.println("Chars to Count? ");
        charsToCount = input.nextLine();


        while (j < charsToCount.length())
        {

            if (charsToCount.charAt(j) == charsToCount.charAt(j - 1))
            {
                ++countReps;
            }

            if (countReps == 0)
            {
                break;
            }

            else
            {
                System.out.println("Repeated chars not allowed. Chars to Count? ");
                charsToCount = input.nextLine();

                countReps = 0;
                j = 0;
            }

            ++j;
        }

        j = 0;

        while (i < line.length())
        {
            while (j < charsToCount.length())
            {
                if (charsToCount.charAt(j) == line.charAt(i))
                {
                    ++count;
                    break;
                }
                j++;
            }
            i++;
        }

        System.out.println(count);

    }
}
