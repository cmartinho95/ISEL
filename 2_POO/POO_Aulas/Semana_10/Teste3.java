import java.lang.reflect.*;

/**
 * Created by cvaz on 08/06/16.
 */
public class Teste3 {

    public static void main(String[] args) throws Exception {
          //      executeMForA(3);
    }

    public static void inspectFields(Object o ) {
        Class<?> cls = o.getClass();

        for (Field f : cls.getDeclaredFields()) {
            System.out.print(" Field: " + f.getName());
        }
    }



   /public static void executeMForA(int y) {// throws Exception {
        Class<?> c = Class.forName("com.company.A");
        Constructor<?> cons = c.getConstructor( new Class[]{int.class});
        Object o = cons.newInstance( new Object[]{y});
        Method m = c.getMethod("m", new Class[]{});
        Object result= m.invoke(o, new Object[]{});
    }
