import java.util.Arrays;

/**
 * Created by ffreitas on 13-Dec-17.
 */
public class ArrayUtils {

    public static void sort(int[] array){

        for(int i = 0; i < array.length; ++i){

            int idxMin = i;
            int min = array[i];
            for(int j = i + 1; j < array.length; ++j){
                if(array[j] < min){
                    idxMin = j;
                    min = array[j];
                }
            }
            array[idxMin] = array[i];
            array[i] = min;
        }
    }

    public static int indexOfBinary(int[]array, int n){
        int min = 0;
        int max = array.length - 1;
        while(max >= min){
            int middle = (min + max) / 2; //alterar em casa
            if(array[middle] > n) max = middle - 1;
            else if(array[middle] < n) min = middle + 1;
            else return middle;
        }
        return -1;
    }

    public static void insert(int[] array, int n, int nElems){ //nElems difs de 0, actual
        int pos = 0;
        while(pos < nElems && array[pos] < n) ++pos;
        for(int i = nElems; i > pos; --i){
            array[i] = array[i - 1];
        }
        array[pos] = n;
    }



    public static void main(String[]args){
        int[] array = {25,20,10,15,5,0};
        sort(array);
        System.out.println(Arrays.toString(array));
        System.out.println(indexOfBinary(array,5));
        System.out.println(indexOfBinary(array,25));
        System.out.println(indexOfBinary(array,8));
        int[] array2 = {10,20,25,30,0,0,0};
        insert(array2, 23, 4);
        System.out.println(Arrays.toString(array2));
        insert(array2, 5, 5);
        System.out.println(Arrays.toString(array2));
        insert(array2, 35, 6);
        System.out.println(Arrays.toString(array2));
    }

}
