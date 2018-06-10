import java.lang.reflect.*;

public class Ficha3_Main{
    public static void main(String[] args){
        try{
            Object o = new Ficha3_A(1);
            Ficha3_A a = new Ficha3_A(1);

            Class<?> c = o.getClass();

            System.out.println(c);
            System.out.println(boolean.class);
            System.out.println(Integer.TYPE);

            Class<?> c0 = Class.forName("Ficha3_A");
            Class<?> c1 = Ficha3_A.class.getSuperclass();
            System.out.println(c0);
            System.out.println(c1);

            Class<?>[] classes0 = Ficha3_A.class.getClasses();
            Class<?> c2 = Ficha3_A.class.getDeclaringClass();
            System.out.println(classes0);
            System.out.println(c2);

            Field f1 = c.getField("name");
            System.out.println(f1.getName());
            System.out.println(f1.getModifiers());

            Method[] methods = c.getDeclaredMethods();
            Type[] pTypes = methods[0].getGenericParameterTypes();

            for(Type t : pTypes){
                System.out.print(t + ",");
            }
            System.out.println();

            pTypes = methods[2].getGenericParameterTypes();

            for(Type t : pTypes){
                System.out.print(t + ",");
            }
            System.out.println();

            System.out.println(a.getX());

            Object o2 = c.newInstance();

            methods[2].invoke(2);
            methods[1].invoke(1);


        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }

    }
}
