public class A{
    public int i;
    public static int n = 0;
    public A(){ //construtor
        this.i = 5;  // i do objecto
        A.n++; // igual a: n++; | n da classe (unico n)
    }
    public void m1(){
        ++i; // igual a this.i
    }
}

main:

A a1 = new A(5);
System.out.println(A.n); // 1
A a2 = new A(5);
System.out.println(a1.i); // 5
System.out.println(a2.i); // 5
a2.m1();
System.out.println(a1.i); // 5
System.out.println(a2.i); // 6
System.out.println(A.n); // 2