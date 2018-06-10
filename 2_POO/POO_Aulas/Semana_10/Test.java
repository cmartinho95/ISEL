import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

/**
 * Created by cvaz on 19/05/15.
 */
public class Test {
    public static void main(String[] args) throws Exception {
        testInstances();
    }

    private static void testInstances() throws Exception{
            A o1 = new A(10);
            inspectFields(o1);
            String name = "A";
            Class<?> cls = Class.forName(name);

            Constructor<?> ctor = cls.getConstructor(int.class);
            Object o2 = ctor.newInstance(30);
            Object o3 = cls.newInstance();
            System.out.println(o3);

            inspectFields(o2);
            inspectFields(o3);

            B o5 = new B("abc");
            System.out.println("***********");
            inspectFields(o5);
            System.out.println("***********");
            inspectFields(new Object());

            System.out.println("METHODS");
            inspectMethods(o1);
            System.out.println("***********");
            inspectMethods(o5);
            System.out.println("***********");
            inspectMethods(new Object());
    }




    public static void inspectMethods(Object o){
        String className = null;
        Class<?> cls = o.getClass();

        className = cls.getName();
        System.out.println("class = " + className);
        try {

            for (Method m : cls.getDeclaredMethods()) {
                System.out.print(" Method: " + m.getName());
                System.out.println("-> Modifiers: " + Modifier.toString(m.getModifiers()));
                System.out.println(m.invoke(o, new Object[0]));
            }


        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void inspectFields(Object obj) throws Exception {
        String className = null;
        Class<?> cls = obj.getClass();
        className = cls.getName();
        System.out.println("class = " + className);
        for (Field f : cls.getDeclaredFields()) {
            System.out.print(" Field: " + f.getName());
            System.out.println("-> Modifiers: " + Modifier.toString(f.getModifiers()));
            try {
                f.get(obj);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
