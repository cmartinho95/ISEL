import java.util.Scanner;

public class Calculadora2
{

    public static void main(String[] args)
    {

        int op1,op2,resultado,total;
        //declarar variavel Scanner do tipo teclado e a defini-la
        Scanner teclado = new Scanner(System.in);
        // atribuis-se funcao teclado e ficas a aguardar Int no input a op1 e op2

        System.out.print("Operando 1? ");
        op1 = teclado.nextInt();
        System.out.print("Operando 2? ");
        op2 = teclado.nextInt();

        resultado = op1 + op2;
        total = resultado;
        System.out.println(op1 + " + " + op2 + " = " +resultado);

        resultado = op1 - op2;
        total = total + resultado;
        System.out.println(op1 + " - " + op2 + " = " +resultado);

        resultado = op1 * op2;
        total += resultado; //igual a total = total + resultado
        System.out.println(op1 + " * " + op2 + " = " +resultado);

        resultado = op1 / op2;
        total += resultado;
        System.out.println(op1 + " / " + op2 + " = " +resultado);

        System.out.println("Total = " +total);
    }
}
