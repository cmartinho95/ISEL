import java.util.Scanner;

public class TestPrintf
{
    public static void main(String[] args)
    {
        int i = 12;
        String s = "ola";
        float f = 12.3f;

        System.out.printf("XPTO %8d, s%, f%", i, s, f)
        // %xd -- impressao vai ter 8 chars, o q nao for preenchido pela var
        // atribuida a d e' preenchida com espacos

    }
}
