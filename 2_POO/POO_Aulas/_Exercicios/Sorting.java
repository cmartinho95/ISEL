import java.util.Arrays;

public class Sorting{

    public static void main(String[] args){
        int[] numbers1 = {2,5,3,1,4,0};
        int[] numbers2 = {10,12,8,6,16,0};

        System.out.println(Arrays.toString(numbers1));
        insert(numbers1, 6, 5);
        sortUp(numbers1);
        System.out.println("Sorted:" + Arrays.toString(numbers1));

        System.out.println(Arrays.toString(numbers2));
        insert(numbers2, 14, 5);
        sortDown(numbers2);
        System.out.println("Sorted:" + Arrays.toString(numbers2));


    }

    public static void sortDown(int[] array){

        for (int i = 0; i < array.length; ++i){
            int idxMax = i;
            int max = array[i];

            for(int j = i + 1; j < array.length; ++j){
                if (array[j] > max){
                    idxMax = j;
                    max = array[j];
                }
            }
            array[idxMax] = array[i];
            array[i] = max;
        }
    }

    public static void sortUp(int[] array){

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

    public static void insert(int[] array, int n, int nElems){ //nElems difs de 0, actual
        int pos = 0;
        while(pos < nElems && array[pos] < n) ++pos;
        for(int i = nElems; i > pos; --i){
            array[i] = array[i - 1];
        }
        array[pos] = n;
    }
}
