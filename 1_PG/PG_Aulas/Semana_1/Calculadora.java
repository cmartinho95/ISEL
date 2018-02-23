import java.util.Scanner;

public class Calculadora
{

    public static void main(String[] args)
    {
//declarar funcao Scanner com nome teclado e a defini-la
        Scanner teclado = new Scanner(System.in);
        // chamas funcao teclado e ficas a aguardar Int no input
        int op1 = teclado.nextInt();
        int op2 = teclado.nextInt();

        int resultado = op1 / op2;
        System.out.println(op1 + " / " + op2 + " = " +resultado);

    }
}
