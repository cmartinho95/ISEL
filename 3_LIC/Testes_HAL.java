import java.util.Scanner;

public class Testes{
    Scanner input = new Scanner(System.in);
    int current;

    public static int readBits(int mask){
        int x = ~input.nextInt();
        current = x & mask;

        return (current);
    }

    public static void writeBits(int mask, int value){
        current = ((mask & value) | (~mask & current));

        System.out.println(current);
    }

    public static void setBits(int mask){
        current = mask | current;
        System.out.println(current);
    }

    public static void clrBits(int mask){
        current = ~mask & current;
        System.out.println(current);
    }

    public static void main(String[] args){
        
    }
}
