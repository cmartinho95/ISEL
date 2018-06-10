package poo.util;

public class LinkedList<E> extends AbstractList<E>{
    static class Node<E>{
        E element;
        Node<E> next;
    }
    private Node<E> head;
    public void addFirst(E e){
        Node<E> novo = new Node<E>;
        novo.next = head;
        head = novo;
        novo.element = e;
        size++;
    }

    public boolean contains(Object o){
        Node<E> aux = head;
        while(aux != null){
            if(aux.element.equals(o)) return true;
            aux = aux.next;
        }
        return false;
    }
    public void addLast(E e){
        Node<E> aux = head;
        Node<E> previous = null;
        /*{
            previous = aux;
            aux = aux.next;
        }*/ // que' isto?? 20/3 pag 1

        if (previous == null){
            addFirst(e);
        }
        else{
            Node<E> novo = new Node<E>();
            novo.element = e;
            previous.next = novo;
            size++;
        }
    }
    public int size() return size;
    public E get(int index){
        if (index < 0 || index >= size){throw new IndexOutOfBoundsException();}
        int i = 0;
        Node<E> aux = head;
        while(aux != null && i < index){
            aux = aux.next;
            i++;
        }
        return aux.element;
    }
    public Iterator<E> iterator(){
        return new Itr();
    }
    public class Itr implements Iterator<E>{
        private Node<E> current = head;
        private Node<E> previous = null;
        private Node<E> lastprevious = null;

        public boolean hasNext(){ return current != null;}
        public E next(){
            if (!hasNext()) throw new NoSuchElementException();
            lastprevious = previous;
            previous = current;
            E aux = current.element;
            current = current.next;
            return aux;
        }
        public void remove(){
            if (previous == null) throw new IllegalStateException();
            else if(lastprevious == null) head = null;
            else{
                lastprevious.next = current;
                size--;
            }
        }
    }
}
