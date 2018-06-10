package poo.util;

public abstract class AbstractList<E> extends AbstractCollection implements List<E>{
    public boolean add(E e){
        add(size(), e);
        return true;
    }
}
