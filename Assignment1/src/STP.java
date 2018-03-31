import java.util.ArrayList;

public class STP {

    /*
    bro no constructor
    and just make the functions static to access them
    static method eg: STP.<your method name>
     */

    public static ArrayList<STPState> GetSuccessors (STPState stp)
    {
        int[][] arr = stp.getArr();
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        ArrayList<STPState> succs = new ArrayList<>();

        // if the blank tile isn't on the upper edge...
        if(stp.getyBlank() != 0)
        {
            // make a copy of the tile state
            STPState succ = new STPState(stp);

            // switch blank tile with tile above it
            succ.getArr()[x][y] = arr[x][y--];
            succ.getArr()[x][y--] = 0;

            // add successor state to return list
            succs.add(succ);
        }

        // if the blank tile isn't on the lower edge...
        if(stp.getyBlank() < 5)
        {
            // make a copy of the tile state
            STPState succ = new STPState(stp);

            // switch blank tile with tile below it
            succ.getArr()[x][y] = arr[x][y++];
            succ.getArr()[x][y++] = 0;

            // add successor state to return list
            succs.add(succ);
        }

        // if the blank tile isn't on the left edge...
        if(stp.getxBlank() != 0)
        {
            // make a copy of the tile state
            STPState succ = new STPState(stp);

            // switch blank tile with tile left of it
            succ.getArr()[x][y] = arr[x--][y];
            succ.getArr()[x--][y] = 0;

            // add successor state to return list
            succs.add(succ);
        }

        // if the blank tile isn't on the right edge...
        if(stp.getyBlank() < 3)
        {
            // make a copy of the tile state
            STPState succ = new STPState(stp);

            // switch blank tile with tile right of it
            succ.getArr()[x][y] = arr[x++][y];
            succ.getArr()[x++][y] = 0;

            // add successor state to return list
            succs.add(succ);

        }

        return succs;
    }

    public static ArrayList<SlideDir> GetOperators (STPState stp)
    {
        ArrayList<SlideDir> ops = new ArrayList<>();

        // For this method to work we need the coordinates of the 0 square
        // This should be given by xblank and yblank
        SlideDir tempDir;
        if(stp.getyBlank() - 1 >= 0) {
            tempDir = SlideDir.Up;
            ops.add(tempDir);
        }
        if(stp.getyBlank() + 1 < 5) {
            tempDir = SlideDir.Down;
            ops.add(tempDir);
        }
        if(stp.getxBlank() - 1 >= 0) {
            tempDir = SlideDir.Left;
            ops.add(tempDir);
        }
        if(stp.getxBlank() + 1 < 3) {
            tempDir = SlideDir.Right;
            ops.add(tempDir);
        }

        return ops;
    }


    public enum SlideDir
    {
        Up, Down, Left, Right;
    }

    //apply operator
    public static STPState ApplyOperator(STPState stp, SlideDir o)
    {
        int[][] state = stp.getArr();
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        //i is y (number of rows horizontal rows)
        //j is x (number of vertical columns)
        //remember that (0,0) is in top left corner

        // depending on the operation, switch the blank tile
        //  with another tile in a particular direction
        switch (o){
            case Up:
                state[x][y] = state[x][y--];
                state[x][y--] = 0;

            case Down:
                state[x][y] = state[x][y++];
                state[x][y++] = 0;

            case Left:
                state[x][y] = state[x--][y];
                state[x--][y] = 0;

            case Right:
                state[x][y] = state[x++][y];
                state[x++][y] = 0;

        }
        STPState retState = new STPState(state);

        return retState;
    }

    //undo operator (same, but reversed)
    public static STPState UndoOperator(STPState stp, SlideDir o)
    {
        int[][] state = stp.getArr();
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        switch(o){
            case Up:
                state[x][y] = state[x][y++];
                state[x][y++] = 0;

            case Down:
                state[x][y] = state[x][y--];
                state[x][y--] = 0;

            case Left:
                state[x][y] = state[x++][y];
                state[x++][y] = 0;

            case Right:
                state[x][y] = state[x--][y];
                state[x--][y] = 0;
        }

        return stp;
    }


}

