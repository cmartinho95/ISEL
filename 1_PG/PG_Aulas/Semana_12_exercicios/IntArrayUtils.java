import java.util.Scanner;

public class IntArrayUtils{
    public static int i, j, maxlen, alen, blen;
    public static short under, over, equal;
    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args){
        i = 0; maxlen = 0; under = 0; over = 0; equal = 0;

        for (j = 0; alen <= 0; j++){
            System.out.print("Tamanho do array A? ");
            alen = input.nextInt();
        }
        for (j = 0; blen <= 0; j++){
            System.out.print("Tamanho do array B? ");
            blen = input.nextInt();
        }

        int[] a = new int[alen];
        int[] b = new int[blen];

        for (j = 0; j < alen; j++){
            System.out.print("Array A no índice " + j + ": ");
            a[j] = input.nextInt();
        }
        for (j = 0; j < blen; j++){
            System.out.print("Array B no índice " + j + ": ");
            b[j] = input.nextInt();
        }
        compare(a,b);
        short[] lol = {under, equal, over};

        System.out.println("Número de valores de A inferiores aos valores de B no mesmo índice: " + lol[0]);
        System.out.println("Número de valores de A iguais aos valores de B no mesmo índice: " + lol[1]);
        System.out.println("Número de valores de A superiores aos valores de B no mesmo índice: " + lol[2]);

    }

    public static short[] compare(int[] a, int[] b){

        if (a.length < b.length){
            maxlen = a.length;
        }
        else {maxlen = b.length;}

        for (i = 0; i < maxlen; i++){
            if (a[i] < b[i]){
                under++;
            }
            else if (a[i] > b[i]){
                over++;
            }
            else equal++;
        }
        short[] res = {under, equal, over};

        return res;
    }
}
