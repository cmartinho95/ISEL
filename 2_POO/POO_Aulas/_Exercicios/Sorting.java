public class Sorting{

    public static void main(String[] args){
        int[] numbers = {2,5,3,1,4};

        int[] newArray = sortUp(numbers);

        for (int h = 0; h < newArray.length; h++){
            System.out.println(newArray[h]);
        }
    }

    public static int[] sortUp(int[] numbers){ // ordem crescente
        int[] sorted = new int[numbers.length];
        int minvalue = 0;
        int maxvalue = 0;
        int j = 0;

        for (int i = 0; i < numbers.length - 1; i++){
            if (numbers[i] < minvalue){
                minvalue = numbers[i];
                for (j = 0; j < numbers.length - 1; j++){
                    sorted[j + 1] = sorted[j];
                }
                sorted[0] = minvalue;
            }

            if (numbers[i] > maxvalue){
                maxvalue = numbers[i];
                for (j = numbers.length - 1; j > 0; j--){
                    sorted[j - 1] = sorted[j];
                }
                sorted[numbers.length - 1] = maxvalue;
            }
            else {
                if (numbers[i] > numbers[i + 1]){
                    sorted[i] = numbers[i + 1];
                    sorted[i + 1] = numbers[i];
                }
            }
        }
        return sorted;
    }
}
