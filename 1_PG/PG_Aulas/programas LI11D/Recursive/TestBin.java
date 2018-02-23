public class TestBin {
  public static void main(String[] args) {
    printBin(15);
  }

  /*
  public static void printBin(int n) {
    if (n>1) printBin(n/2);
    System.out.print(n%2);
  }
  */
  public static void printBin(int n) {
    boolean[] bits = new boolean[32];
    int i;
    for (i = 0; n>0 ; i++) {
      bits[i] = n%2 > 0;
      n /= 2;
    }
    for (; i >=0 ; i--)
      System.out.print(bits[i]?1:0);
  }
}
