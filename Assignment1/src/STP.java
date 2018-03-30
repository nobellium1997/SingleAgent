import java.util.ArrayList;

public class STP {

    /*
    How are we gonna call these functions in driver?
    what kind of a constructor do we need?
    why tf do we have to have a separate class for this stuff?
    */

    public ArrayList<STPState> GetSuccessors (STPState stp)
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

    public ArrayList<SlideDir> GetOperators (STPState stp)
    {
        ArrayList<SlideDir> ops = new ArrayList<>();

        return ops;
    }


    public enum SlideDir
    {
        Up, Down, Left, Right;
    }

    //apply operator
    public STPState ApplyOperator(STPState stp, SlideDir o)
    {
        int[][] state = stp.getArr();
        int x = stp.getxBlank();
        int y = stp.getyBlank();

        //i is y (number of rows horizontal rows)
        //j is x (number of vertical columns)
        //remember that (0,0) is in top left corner
        switch (o){
            case Up:
                //shifting the tile above the blank down to the current blank position
                state[x][y] = state[x][y--];

                //making the new blank position above the previous one
                state[x][y--] = 0;

            case Down:
                //shifting the tile below the blank up to the current blank position
                state[x][y] = state[x][y++];

                //making the new blank position below the previous one
                state[x][y++] = 0;

            case Left:
                //shifting the tile left of the blank over to the current blank position
                state[x][y] = state[x--][y];

                //making the new blank position to the left the previous one
                state[x--][y] = 0;

            case Right:
                //shifting the tile right of the blank over to the current blank position
                state[x][y] = state[x++][y];

                //making the new blank position to the left the previous one
                state[x++][y] = 0;

        }
        STPState retState = new STPState(state);

        return retState;
    }

    //undo operator (same, but reversed)
    public STPState UndoOperator(STPState stp, SlideDir o)
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

