package util;
import java.util.Scanner;
public class Date {

    /*--------------------------------------------------------------------------
    STATIC FIELDS
    --------------------------------------------------------------------------*/
    private static final int[] DAYS_OF_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*--------------------------------------------------------------------------
    STATIC FUNCTIONS
    --------------------------------------------------------------------------*/
    private static Date currentDate() {
        java.util.Calendar cal = java.util.Calendar.getInstance();
        return new Date(cal.get(cal.YEAR), cal.get(cal.MONTH) + 1, cal.get(cal.DAY_OF_MONTH));
    }
    private static int daysOfMonth (int m, int y) {
        // Gregorian calendar was defined in 15-10-1582
        if (m < 1 || m > 12 || y < 1582) return -1;
        int daysOfMonth = DAYS_OF_MONTH[m - 1];
        if (m == 2 && Date.isLeapYear(y)) ++daysOfMonth;
        return daysOfMonth;
    }
    private static boolean isGood(int a, int m, int d) {
        int daysOfMonth = Date.daysOfMonth(m, a);
        return daysOfMonth != -1 && d >= 1 && d <= daysOfMonth;
    }
    private static boolean isLeapYear(int ano){
        return ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0;
    }
    public static Date valueOf(String s){
        int p1 = s.indexOf('-');
        int p2 = s.indexOf('-', p1 + 1);
        if (p1 == -1 || p2 == -1) return null;
        int a = Integer.parseInt(s.substring(0, p1));
        int m = Integer.parseInt(s.substring(p1 + 1, p2));
        int d = Integer.parseInt(s.substring(p2 + 1));
        return Date.isGood(a, m, d) ? new Date(a, m, d) : null;
    }

    /*--------------------------------------------------------------------------
    INSTANCE ATTRIBUTES
    --------------------------------------------------------------------------*/
    private int year, month, day;
    /*--------------------------------------------------------------------------
    CONSTRUCTOR
    --------------------------------------------------------------------------*/
    public Date(int a, int m, int d) {
        year = a;
        month = m;
        day = d;
    }
    /*--------------------------------------------------------------------------
    INSTANCE METHODS
    --------------------------------------------------------------------------*/
    public int getYear() { return year;}
    public int getMonth() { return month;}
    public int getDay() { return day;}

    public void inc(Date dt) {
        int m = dt.getMonth();
        int d = dt.getDay();

        if (d == DAYS_OF_MONTH[m - 1]){ //se ultimo dia do mes
            if (m == 12){ // e ultimo mes do ano
                this.year++; // ou this.year += 1
                this.month = 1;
                this.day = 1;
            }
            else {
                //year mantem-se
                this.month = m + 1;
                this.day = 1;
            }
        }
        else {
            //year mantem-se
            //month mantem-se
            this.day = d + 1;
        }
    }
    public void dec() {
        int m = this.getMonth();
        int d = this.getDay();

        if (d == 1){ // se primeiro dia do mes
            if (m == 1){ // e primeiro mes do ano
                this.year--; // ou this.year -= 1
                this.month = 12; // ou DAYS_OF_MONTH.length()
                this.day = 31; // ou DAYS_OF_MONTH[11]
            }
            else {
                //year mantem-se
                this.month = m - 1;
                this.day = d - 1;
            }
        }
        else {
            //year mantem-se
            //month mantem-se
            this.day = d - 1;
        }
    }
    // TODO: returns difference in days
    public int dif(Date dt) {
        return 0;
        //if ()
    }
    public int compareTo(Date dt){ return 0;}

    public String toString(){
        return this.year + "-" + this.month + "-" + this.day;
    }
    /*--------------------------------------------------------------------------
    MAIN FUNCTION
    --------------------------------------------------------------------------*/
    public static void main(String[] args){
        Date dt1 = null;
        while (dt1 == null) {
            System.out.println("Introduza uma data no formato aaaa-mm-dd: 2018-02-21");
            Scanner in = new Scanner(System.in);
            String str = in.next();
            if (str == null) System.exit(0);
            dt1 = Date.valueOf(str);
            if (dt1 == null)
                System.out.println("Data com formato inválido! \nERRO");
        }
        System.out.println("dt1: " + dt1);
        Date dt2 = currentDate();
        System.out.println("dt2: " + dt2);
        int nrDays = 0;
        nrDays = dt1.dif(dt2);
        System.out.println("dt1 - dt2 = " + nrDays + " dias");
        System.exit(0);
    }
}
