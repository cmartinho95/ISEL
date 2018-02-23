public class TestFactorial {

  public static void main(String[] args) {
    System.out.println( fact(5) );
  }

  /*
  public static int fact(int n) {
    if (n==0) return 1;
    return n * fact(n-1);
  }
  */
  public static int fact(int n) {
    int res = 1;
    for( ; n>1 ; --n )
      res *= n;
    return res;
  }
}
