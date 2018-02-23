import java.util.Scanner;

public class Mult
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int m1, m2, m, i, j, k, l;
        int lenm1, lenm2, imax, jmax, result, width, spaces, lenparcial, lenresult;
        String auxiliar;

        m1 = 0; m2 = 0; m = 0; i = 0; j = 0; k = 0; l = 0; spaces = 0; lenparcial = 0; lenresult = 0;

        while (m1 <= 0){
            System.out.print("Multiplicando? ");
            m1 = input.nextInt();
        }
        auxiliar = m1 + "";
        lenm1 = auxiliar.length();
        imax = lenm1 - 1;

        while (m2 <= 0){
            System.out.print("Multiplicador? ");
            m2 = input.nextInt();
        }
        auxiliar = m2 + "";
        lenm2 = auxiliar.length();
        jmax = lenm2 - 1;

        int[] M1 = new int[lenm1];

        m = m1;

        for (i = imax; i >= 0; i--) { // algarismos m1
            M1[i] = m % 10; //algarismo
            m /= 10; //numero pra calcular algarismo seguinte
        }

        int[] M2 = new int[lenm2];

        m = m2;

        for (j = jmax; j >= 0; j--) { // algarismos m2
            M2[j] = m % 10;
            m /= 10;
        }
        j = jmax;

        int[] Rparciais = new int[lenm2];

        for (k = 0; k <= jmax; k++) { // resultados parciais
            Rparciais[k] = M2[j] * m1;
            j--;
        }
        result = m1 * m2;
        width = lenm1 + lenm2 + 1;

        for (k = 0; k < width - lenm1; k++){ // espaços antes de m1
            System.out.print(" ");
        }
        System.out.println(m1);

        System.out.print("x");
        for (k = 0; k < width - lenm2 - 1; k++){ // espaços antes de m2
            System.out.print(" ");
        }
        System.out.println(m2);

        for (k = 0; k < width; k++){
            System.out.print("-");
        }
        System.out.println();

        for (k = 0; k < lenm2; k++){ //calcular espacos antes dos res parciais e imprimir

            m = Rparciais[k];
            lenparcial = 0;

            if (Rparciais[k] == 0){
                lenparcial = 1;
            }
            else{
                for (i = 0; m > 0; i++) { // algarismos do res parcial
                l = m % 10;
                m /= 10;
                lenparcial++;
                }
            }

            if (k == lenm2 - 1){ // se ultimo res parcial
                System.out.print("+");
                spaces = width - lenparcial - k - 1;
            }
            else{
                spaces = width - lenparcial - k;
            }

            for (l = 0; l < spaces; l++){
                System.out.print(" ");
            }

            System.out.print(Rparciais[k]);
            System.out.println();
        }

        for (k = 0; k < width; k++){
            System.out.print("=");
        }
        System.out.println();

        m = result;

        for (k = 0; m > 0; k++) { // algarismos do resultado
            l = m % 10;
            m /= 10;
            lenresult++;
        }

        for (l = 0; l < width - lenresult; l++){ //espacos antes do resultado
            System.out.print(" ");
        }
        System.out.println(result);
    }
}
