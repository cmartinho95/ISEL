package poo.util;

public class ArrayList<E> extends AbstractList<E>{
    private E[] elements;
    private int size;
    public ArrayList(int initialCapacity){
        this.elements = new Object[initialCapacity];
    }
    public ArrayList(){
        this(10);
    }
    public int size(){return size;}
    public E get(int i){
        if(i < 0 || i >= size){throw new ArrayIndexOutofBoundsException();}
        return elements[i];
    }

    public Iterator<E> iterator(){
        return new Itr();
    }

    private class Itr implements Iterator<E>{
        private int idx = 0;
        public boolean b = false;
        public E next(){
            if(!hasNext()) throw new NoSuchElementException();
            b = true;
            return elements[idx++];
        }
        public boolean hasNext(){ return idx < size;}
        public void remove(){
            if(!b) throw new IllegalStateException();
            System.arraycopy(elements, idx + 1, elements, idx, size - idx + 1);
            elements[--size] = null;
            b = false;
        }
        public void add(int index, E e){
            if (index < 0 || index > size) throw new ArrayIndexOutofBoundException();
            if (size >= elements.length) increaseCapacity();
            System.arraycopy(elements, index, elements, index + 1, size - index);
            elements[index] = e;
            size++;
        }
    }
}
