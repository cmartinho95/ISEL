import java.util.Scanner;

public class TestString2
{
    public static void main (String[] args)
    {
        Scanner input = new Scanner(System.in);

        String line, charsToCount;
        int count, i, j;
        char charLine, charCount;

        System.out.println("Line? ");
        line = input.nextLine();
        System.out.println("Char to Count? ");
        charsToCount = input.nextLine();

        i = 0;
        count = 0;

//dar erro se houver mais q 1 letra de cada no charsToCount (e.g. aa)
// if count > 1  -- erro

        while (i < line.length())
        {
            charLine = line.charAt(i);

            j = 0;
            while (j < charsToCount.length())
            {
                charCount = charsToCount.charAt(j);

                if (charLine == charCount)
                {
                    ++count;
                    break;
                }
                ++j;
            }
            ++i;
        }
        System.out.println(count);
    }
}
