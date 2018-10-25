public class Unique{
    public static int unique(int[] a, int n){
        int i;
        for (i = 1, int j = 1; j < n; j++){
            if (a[j] != a[j - 1]){
                a[i] = a[j];
                i++;
            }
        }
        return i;
    }

    public static void main(String[] args){
        
    }
}
