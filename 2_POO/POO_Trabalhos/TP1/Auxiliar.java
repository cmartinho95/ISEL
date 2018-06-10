public class Auxiliar{

    public boolean isConnected(int lin, int col){
        char dir = getDirection();

        //TODO... LinkedList??

        switch(dir){
            case 'E':
                Cell next = model.getCell(lin, col);
                char nextDir = next.getDirection();

                if (next instanceof CurveCell){
                    if (nextDir == 'W' || nextDir == 'S'){
                        return true;
                    }
                }
                else if (next instanceof LineCell){
                    if (nextDir == 'E' || nextDir == 'W'){
                        return true;
                    }
                }
                else if (next instanceof HouseCell || next instanceof PowerCell){
                    if (nextDir == 'W'){
                        return true;
                    }
                }
                else if (next instanceof BranchCell){
                    if (nextDir == 'W' || nextDir == 'N' || nextDir == 'S'){
                        return true;
                    }
                }
        }

        return true;
    }
}


public char previousDirection(){
    if (d == 0) return directions[4];
    else return directions[d - 1];
}
