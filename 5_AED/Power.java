public class Power{
    public static int power(int a, int n){
        int p = a;
        for (int i = 2; i <= n;){
            p *= a;
            if (i * i <= n){
                i *= i;
                p *= p;
                continue;
            }
            i++;
        }
        return p;
    }

    public static int power2(int a, int n){
        if (n == 0) return 1;
        int p = power(a, n/2);
        if (n % 2 == 0) return p * p;
        return a * p * p;
    }

    public static int[] findElementsThatSumTo(int[] a, int l, int r, int s){
        while (l < r){
            int sum = a[l] + a[r];
            if (sum == s){
                return sum;
            }
            else {
                if (sum > s){
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return null;
    }

    public static void main(String[] args){
        System.out.println(power(2,3));
        System.out.println(power(3,3));
        System.out.println(power(2,4));
    }
}
