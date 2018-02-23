public class TestPoint {
  public static void main(String[] args) {
    Point p1 = new Point(1,3);
    System.out.println("("+p1.line+","+p1.col+")");
    Point p2 = new Point(2,4);
    System.out.println("p2="+p2);

    p2.add(p1);
    System.out.println(p2);

    Point p3 = p2.sum(p1);
    System.out.println(p3);
    Point p4 = Point.sum(p1,p2);
    System.out.println(p4);
    System.out.println(p3.eq(p4));
  }
}
