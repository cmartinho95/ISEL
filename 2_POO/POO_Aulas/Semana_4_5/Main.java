public class Main{
    public static void main(String[] args){
        ArrayList<Integer> listInt = new ArrayList<Integer>();
        LinkedList<String> listStr = new LiskedList<String>();
        for(int i = 0; i < 2: i++){
            listInt.add(i);
        }
        System.out.println(listInt.get(0));
        for(int i = 0; i < listInt.size(); i++){
            System.out.println(listInt.get(i));
        }
        //mesmo resultado de:
        /*
        Iterator<Integer> it = listInt.iterator();
        while (it.hasNext()){
        System.out.println(it.next());
        }
        */
        //que e' sinonimo de: (for each)
        /*
        for(Integer i : listInt){
        System.out.println(i);
        }
        */
    }
}
