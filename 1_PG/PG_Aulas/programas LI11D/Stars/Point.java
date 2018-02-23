import isel.leic.pg.Console;

public class Point {
  public int line;
  public int col;

  public Point() {}
  public Point(int l, int c) {
    line=l; col=c;
  }

  public boolean eq(Point other) {
    return line == other.line && col == other.col ;
  }

  public void cursor() {
    Console.cursor(line,col);
  }

  public String toString() {
    return "Point("+line+","+col+")";
  }

  public void add(Point p) {
    line += p.line;
    col += p.col;
  }

  public Point sum(Point b) {
    //return new Point(line+b.line, col+b.col);
    return sum(this,b);
  }

  public static Point sum(Point a, Point b) {
    return new Point(a.line + b.line, a.col+b.col);
  }
}
