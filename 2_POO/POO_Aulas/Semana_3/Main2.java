import java.util.*;

public class Main2{

    public static void main(String[] args){
        String[] a = {"olá", "joaquim", "calhau", "Bruno"};

        Comparator<String> cmp1 = new Comparator<String>(){
            public int compare(String s1, String s2){
                return s1.length() - s2.length();
            }
        };

        Comparator<String> cmp2 = new Comparator<String>(){
            public int compare(String s1, String s2){
                return s1.compareTo(s2);
            }
        };

        System.out.println(Arrays.toString(a));
        sort(a, cmp1);
        System.out.println(Arrays.toString(a));
        sort(a, cmp2);
        System.out.println(Arrays.toString(a));
    }

    public static void sort(String[] array, Comparator<String> cmp){
        for (int j = 0; j < array.length - 1; j++){
            int min = j;
            for (int i = j+1; i < array.length; i++){
                if (cmp.compare(array[min], array[i]) > 0){
                    min = i;
                }
            String aux = array[j];
            array[j] = array[min];
            array[min] = aux;
            }
        }
    }
}
