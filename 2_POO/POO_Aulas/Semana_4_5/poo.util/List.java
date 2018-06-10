package poo.util;

public interface List<E> extends Collection{
    void add(int index, E element);
    E set(int index, E element);
    E get(int index);
    E remove(int index);
}
