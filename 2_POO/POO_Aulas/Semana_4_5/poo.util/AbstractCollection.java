package poo.util;

public abstract class AbstractCollection<E> extends Object implements Collection{
    public boolean isEmpty(){
        return size() == 0;
    }
    public boolean contains(Object o){
        Iterator<E> it = this.iterator();
        while(it.hasNext()){
            if (it.next().equals(o)) return true;
        }
        return false;
    }
    public boolean remove(Object o){
        Iterator<E> it = this.iterator();

        while(it.hasNext()){
            if (it.next(o).equals(o)){
                it.remove();
                return true;
            }
            return false;
        }
    }
}
