public class TestInteger
{
    public static void main(String[] args)
    {
    short s1 = 12;
    int i2 = 2;
    long l3 = s1 + i2;

/* ver Aula 2 - inserir (short) antes faz conversao especifica do numero para
tipo de numero adequado, apesar de a' partida nao serem compativeis
e.g. passar de 32 bits para 16.
S/ short da' erro:
*/
    s1 = (l3 + i2);
    System.out.println(s1);

    }
}
