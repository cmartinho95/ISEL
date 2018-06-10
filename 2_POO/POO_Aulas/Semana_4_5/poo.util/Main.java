package poo.util;

public class Main{
    public static void main(String[] args){
        LinkedList<Integer> lista = new LinkedList<Integer>();
        lista.addFirst(1);
        lista.addFirst(2);
        lista.addFirst(3);
        lista.addLast(4);

        //mt ineficiente em linked list
        for (int i = 0; i < lista.size(); i++){
            System.out.println(lista.get(i));
        }
        //ou iterator ou for each
    }
}
