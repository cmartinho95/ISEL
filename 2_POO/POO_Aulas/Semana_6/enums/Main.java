package enums;

/**
 * Created by cvaz on 27/03/2018.
 */
public class Main {

    public static void main(String[] args) {
        Direction d = Direction.UP;
        System.out.println(d);
        for(Direction x : Direction.values())
            System.out.println(x + " - " + x.change());
        System.out.println(d.name());
        switch (d) {
            case UP: System.out.println("UP!");
            case DOWN: System.out.println("DOWN!");
            default: System.out.println("Nothing");
        }
        int px = 1;
        int py = 1;
        System.out.println("-----------------");
        for(Direction x : Direction.values()) {
            int newLine = d.deltaLin + px;
            int newCol = d.deltaCol + py;
            System.out.println("Direction" + x.toString());
            System.out.println("new Line" + newLine);
            System.out.println("new Col" + newCol);
            System.out.println("*****************");
        }
        print("ola");
        print("a", "b", "c");
    }

    public static void print(String ... strs){
        for(int i = 0; i < strs.length; i++){
            System.out.println(strs[i]);
        }
    }
}
