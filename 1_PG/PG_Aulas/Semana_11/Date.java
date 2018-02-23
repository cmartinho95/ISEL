public class Date{
    private int day;
    private int month;
    private int year;

    public Date(int d, int m, int y){
        this.day = d;
        this.month = m;
        this.year = y;
    }

    public String toString(){
        return "Day: " + this.day + " - Month: " + this.month + " - Year: " + this.year;
    }

    public int compareTo(Date d){
        int r = this.year - d.year;
        if (r != 0) return r;
        r = this.month - d.month;
        if (r != 0) return r;
        return this.day - d.day;
    }


    public static void main(String[] args){

        Date d1 = new Date(27,1,2016);

        //Day: 27 - Month: 1 - Year: 2016
        System.out.println(d1);

        Date d2 = new Date(25,1,1980);
        System.out.println(d2);


        int cmp = d1.compareTo(d2); // retorna valor > 0. se d1 for menor, retorna <0, se igual = 0
        System.out.println(cmp);

        if (cmp > 0) System.out.println("Maior");
        else if (cmp < 0) System.out.println("Menor");
        else System.out.println("Iguais");
    }
}