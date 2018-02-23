import java.util.Scanner;

public class PrimLiga
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int jogos, vitorias, derrotas, empates, pontos;
        String nome;

        System.out.print("Jogos realizados? ");
        jogos = input.nextInt();

        System.out.print("Vitórias e Derrotas? ");
        vitorias = input.nextInt();
        derrotas = input.nextInt();
        input.nextLine();

        System.out.print("Nome da equipa? ");
        nome = input.nextLine();

        empates = jogos - vitorias - derrotas;
        pontos = 3 * vitorias + empates;

        System.out.println(nome + " tem " + pontos + " pontos.");

    }
}
