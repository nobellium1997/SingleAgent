import java.util.ArrayList;

public class STP {

    // How are we gonna call these functions in driver?

    public ArrayList<STPState> GetSuccessors (STPState stp)
    {
        ArrayList<STPState> succs = new ArrayList<>();

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

