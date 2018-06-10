package poo.util;

public interface Collection<E> extends Iterable<E>{
    boolean add(E e);
    boolean contains(Object o);
    boolean remove(Object o);
    boolean isEmpty();
    int size();
}
