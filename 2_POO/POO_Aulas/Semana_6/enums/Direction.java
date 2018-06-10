package enums;

public enum Direction {
    UP(-1,0), RIGHT(0,+1), DOWN(+1,0), LEFT(0,-1);

    final int deltaLin, deltaCol;

    Direction(int dl, int dc) { deltaLin=dl; deltaCol=dc; }

    public Direction change() {
        return values()[(this.ordinal()+2) % values().length];
    }
}
