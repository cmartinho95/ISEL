import java.util.Scanner;

public class AreaCirculo_repetido
{
    public static void main(String[] args)
    {
        int raio;
        double resultado;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduza raio: ");
        raio = teclado.nextInt();

        resultado = 3.14 * raio * raio;

        System.out.println(resultado);

    }
}
