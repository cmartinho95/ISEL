import java.util.Scanner;

public class Histograma
{
    public static void main(String[] args)
    {
        String line;
        int counter, len, i, k, l, m, max, n;
        char j;

        Scanner input = new Scanner(System.in);

        int[] counters = new int['z' - 'a' + 1];

        System.out.print("String? ");
        line = input.nextLine();
        len = line.length();

        i = 0;
        l = 0;
        k = 0;
        m = 0;
        n = 0;
        j = 'a';
        counter = 0;

        for (i = 0; i < len; i++) //certo
        {
            char c =line.charAt(i);
            if(c >= 'a' && c<='z')
            {
                ++counters[c - 'a']; // c - 'a' : index no array. a: 0, b: 1 etc
            }

            /*while (j <= 'z')
            {
                if (line.charAt(i) == (char)j)
                {
                    counters[k] += 1;
                    break;
                }
                j++;
                k++;
            }
            i++;
            j = 'a';
            k = 0;*/
        }

        while (j <= 'z') // buscar max
        {
            if (counter < counters[k])
            {
                counter = counters[k];
            }
            k++;
            j++;
        }

        m = 0;
        max = counter;
        k = 0;
        j = 'a';

        while (m < max)
        {
            System.out.print(counter + " ");
            while (k < 26)
            {
                if (counters[k] == counter)
                {
                    System.out.print("# ");
                    counters[k]--;
                }
                else
                {
                    System.out.print("  ");
                }
                k++;
            }
            System.out.println();
            m++;
            counter--;
            k = 0;
        }

        System.out.print("  ");

        while (j < 'z')
        {
            System.out.print((char)j + " ");
            j++;
        }
        System.out.println();

/*
        while (j <= 'z')
        {
            System.out.print((char)j + ": ");

            while (l < counters[k])
            {
                System.out.print("*");
                l++;
            }
            System.out.println();

            l = 0;
            j++; k++;
        }*/
    }
}
