import isel.leic.pg.Console;

public class Star {
  public Point pos;
  public int color;

  public Star() {
    color = (int) ((Math.random() * Console.MAX_COLORS-1)+1);
  }
  public Star(Point p) {
    this();
    pos = p;
  }

  public void show() {
    pos.cursor();
    Console.setForeground(color);
    Console.print('*');
  }

  public void hide() {
    pos.cursor();
    Console.print(' ');
  }
}
