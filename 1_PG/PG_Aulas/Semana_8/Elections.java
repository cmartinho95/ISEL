import java.util.Scanner;

public class Elections
{
    public static void main(String [] args)
    {
        //Obter candidatos
        String[] candidates = {"Sara","Filipe","Ana"};

        //votacao
        for(;;)
        {
            //menu
            for (int i = 0; i < candidates.length; ++i)
            {
                System.out.println(i + " - " + candidates[i]);
            }
            System.out.println("-1 - Sair");

            int option = input.nextInt();
            if (option == -1) break;
            else if (option <= -2 || option >= counters.length)
            {
                System.out.println("Inválida");
                continue;
            }
            ++counters[option];
         }

         // apresentacao
         for (int i = 0; i < candidates.length; ++i)
         {
             System.out.println(candidates[i] + " - " + counters[i]);
         }
    }
}
