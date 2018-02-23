import isel.leic.pg.Console;
import java.awt.event.KeyEvent;

public class Stars {
  private static final int LINES = 10;
  private static final int COLS = 20;
  private static final int STARS = (LINES*COLS) / 2;

  private static Star[] stars = new Star[STARS];
  private static boolean[][] exist = new boolean[LINES][COLS];

  private static int numOfStars = 0;

  public static void main(String[] args) {
    //for (int l = 0; l < LINES; l++) exist[l] = new boolean[COLS]
    Console.fontSize(40);
    Console.open("Stars", LINES, COLS);
    printStars();
    int key;
    int idx = 0;
    do {
      Star s = stars[idx];
      s.hide();
      key =Console.waitKeyPressed(50);
      s.show();
      if (++idx==numOfStars) idx=0;
    } while( key != KeyEvent.VK_Q );
    System.out.println("key="+key);
    Console.close();
  }

  private static void printStars() {
    for (int i = 0; i < STARS; i++) {
      Point p = new Point();
      do {
        p.line = (int) (Math.random() * LINES);
        p.col = (int) (Math.random() * COLS);
      }while( existStar(p) );

      Star s = new Star(p);
      s.show();
      stars[numOfStars++] = s;
      exist[p.line][p.col] = true;
    }
  }

  private static boolean existStar(Point pt) {
    return exist[pt.line][pt.col];
    //for (int i = 0; i < numOfStars; i++)
    //  if (stars[i].pos.eq(pt)) return true;
    //return false;
  }
}
