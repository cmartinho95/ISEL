public class Grid
{
    public static void main(String[] args)
    {
        int i, j, k, maxchars;
        char chartoprint;
        i = 0; j = 0; maxchars = 0; k = 0;
        chartoprint = ' ';

        maxchars = args[i].length();

        for (i = 1; i < args.length; i++){ // comprimento do arg mais comprido
            if (args[i].length() > maxchars){
                maxchars = args[i].length();
            }
        }

        for (i = 0; i < args.length; i++){
            System.out.print("+");
            for (j = 0; j < maxchars; j++){
                System.out.print("---+");
            }
            System.out.println();

            System.out.print("|");
            for (k = 0; k < args[i].length(); k++){
                if (args[i].charAt(k) == '_'){ // se underscore, imprimir espaço
                    chartoprint = ' ';
                }
                else {chartoprint = args[i].charAt(k);}

                System.out.print(" " + chartoprint + " |");
                }

            if (maxchars > args[i].length()){ // imprimir quadrados vazios
                for (; k < maxchars; k++){
                    System.out.print("   |");
                }
            }
            System.out.println();
        }
        
        System.out.print("+"); // ultimo risco
        for (j = 0; j < maxchars; j++){
            System.out.print("---+");
        }
        System.out.println();
    }
}
