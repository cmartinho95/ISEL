import java.util.Scanner;

public class Morse{
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        int iline, iword, k, l, n, ialfabeto;
        String enteredline;
        boolean ismorse;
        long start;

        k = 0;
        iline = 0;
        iword = 0;
        ismorse = false;
        enteredline = "\n";

        String[] morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        String[] alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

        enteredline = input.nextLine();

        for (iline = 0; ; iline++){

            if (enteredline.equals("*")){break;}

            else if (enteredline.equals("")){
                System.out.println();
                enteredline = input.nextLine();
            }

            else {
                String[] line = enteredline.split("\\s");

                for (k = 0; k < line.length; k++){ //substitui strings vazios por espaco
                    if (line[k].equals("")){
                        line[k] = " ";
                    }
                }

                for (iword = 0; iword < line.length; iword++){

                    if (line[iword].equals(" ")){
                        System.out.print(" ");
                    }

                    else if (line[iword].charAt(0) == '-' || line[iword].charAt(0) == '.'){
                        ismorse = false;

                        for (l = 0; l < 26; l++){
                            if (line[iword].equals(morse[l])){
                                System.out.print(alphabet[l]);
                                ismorse = true;
                                break;
                            }
                        }
                        if (!ismorse){
                            System.out.print("? ");
                        }
                    }

                    else {
                        for (k = 0; k < line[iword].length(); k++){ //ABC para Morse
                            if (line[iword].charAt(k) >= 'a' && line[iword].charAt(k) <= 'z'){
                                ialfabeto = line[iword].charAt(k) - 'a';
                                System.out.print(morse[ialfabeto] + " ");
                            }
                            else if (line[iword].charAt(k) >= 'A' && line[iword].charAt(k) <= 'Z'){
                                ialfabeto = line[iword].charAt(k) - 'A';
                                System.out.print(morse[ialfabeto] + " ");
                            }
                            else{
                                System.out.print("? ");
                            }
                        }
                        System.out.print(" ");
                    }
                }
                System.out.println();
                enteredline = input.nextLine();
            }
        }
    }
}
