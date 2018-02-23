import java.util.Scanner;

public class AreaCirculo
{
    public static void main(String[] args)
    {
        int raio;
        float resultado;
        Scanner teclado = new Scanner(System.in);
        System.out.prinln("Introduza raio: ");
        raio = teclado.nextInt();

        resultado = 3.14 * raio * raio;

        System.out.println(resultado);


        
    }
}
