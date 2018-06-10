package grades_v5;

public Sorting{
    public static void sort(E[] array, Comparator<E> cmp){
        for (int j = 0; j < array.length - 1; j++){
            int min = j;
            for (int i = j+1; i < array.length; i++){
                if (cmp.compare(array[min], array[i]) > 0){
                    min = i;
                }
            E aux = array[j];
            array[j] = array[min];
            array[min] = aux;    
            }
        }
    }
}
