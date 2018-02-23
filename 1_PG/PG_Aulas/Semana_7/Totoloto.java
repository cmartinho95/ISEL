public class Totoloto
{
    public static void main(String[] args)
    {
        int[] numbers = new int[49];
        boolean[] exists = new boolean[49];

        for (int i = 0; i < numbers.length;)
        {
            int v = (int)(Math.random() * 49); // double entre 0 (inc) e 1 (exc)
            boolean exist = false;

            /*for (int j = 0; j < i; ++j)
            {
                if (numbers[j] == v)
                {
                    exist = true;
                    break;
                }
            }*/

            /*if (!exist)
            {
                numbers[i] = v;
                ++i;
            }*/

            if (!exists[v])
            {
                exists[v] = true;
                numbers[i] = v;
                ++i;
            }
        }

        for (int i = 0; i < numbers.length; ++i)
        {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();

    }
}
