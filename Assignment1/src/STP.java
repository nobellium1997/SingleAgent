import java.util.ArrayList;

public class STP {

    /*
    bro no constructor
    and just make the functions static to access them
    static method eg: STP.<your method name>
     */

    public STP() {

    }

    // this method has been tested and is working
    public static ArrayList<STPState> GetSuccessors (STPState stp)
    {
        ArrayList<STPState> succs = new ArrayList<>();

        ArrayList<SlideDir> operators = GetOperators(stp);
        for(int i = 0; i < operators.size(); i++) {
            succs.add(ApplyOperator(stp, operators.get(i)));
        }

        return succs;
    }

    // This method has been tested and should be working
    public static ArrayList<SlideDir> GetOperators (STPState stp)
    {
        ArrayList<SlideDir> ops = new ArrayList<>();

        // For this method to work we need the coordinates of the 0 square
        // This should be given by xblank and yblank
        SlideDir tempDir;
        if(stp.getxBlank() - 1 >= 0) {
            tempDir = SlideDir.Up;
            ops.add(tempDir);
        }
        if(stp.getxBlank() + 1 < 5) {
            tempDir = SlideDir.Down;
            ops.add(tempDir);
        }
        if(stp.getyBlank() - 1 >= 0) {
            tempDir = SlideDir.Left;
            ops.add(tempDir);
        }
        if(stp.getyBlank() + 1 < 3) {
            tempDir = SlideDir.Right;
            ops.add(tempDir);
        }

        return ops;
    }

    // This method has been tested and is working
    public static STPState ApplyOperator(STPState stp, SlideDir o)
    {
        int[][] state = new int[5][3];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                state[i][j] = stp.getArr()[i][j];
            }
        }
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        //i is y (number of rows horizontal rows)
        //j is x (number of vertical columns)
        //remember that (0,0) is in top left corner

        // depending on the operation, switch the blank tile
        //  with another tile in a particular direction
        switch (o){
            case Left:
                state[x][y] = state[x][y-1];
                state[x][y-1] = 0;
                break;
            case Right:
                state[x][y] = state[x][y+1];
                state[x][y+1] = 0;
                break;
            case Up:
                state[x][y] = state[x-1][y];
                state[x-1][y] = 0;
                break;
            case Down:
                state[x][y] = state[x+1][y];
                state[x+1][y] = 0;
                break;
        }
        STPState retState = new STPState(state);
        return retState;
    }

    // NEEDS TESTING
    public static STPState UndoOperator(STPState stp, SlideDir o)
    {
        int[][] state = new int[5][3];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                state[i][j] = stp.getArr()[i][j];
            }
        }
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        switch(o) {
            case Left:
                state[x][y] = state[x][y+1];
                state[x][y+1] = 0;
                break;
            case Right:
                state[x][y] = state[x][y-1];
                state[x][y-1] = 0;
                break;
            case Up:
                state[x][y] = state[x+1][y];
                state[x+1][y] = 0;
                break;
            case Down:
                state[x][y] = state[x-1][y];
                state[x-1][y] = 0;
                break;
        }
        STPState new_state = new STPState(state);
        return new_state;
    }
}

