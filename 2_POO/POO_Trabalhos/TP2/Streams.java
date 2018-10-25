public class Streams{

    public static void main(String[] args){

    }

    public void loadModel(Scanner in){
        String line = null;

        while(in.hasNextLine()) {
            line = in.nextLine();

            Figure f;
            char figureLetter = line.charAt(0);
            f = Figure.newInstance(figureLetter);
            f.load(in);



            String start = lineElements[1];
            int v = start.indexOf(",");

            int x = Integer.parseInt(start.substring(1, v));
            int y = Integer.parseInt(start.substring(v + 1, start.length() - 1));
            f.setStart(x,y);
}
