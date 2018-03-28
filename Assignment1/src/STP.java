import java.lang.reflect.Array;
import java.util.ArrayList;

public class STP {

    public ArrayList<STPState> GetSuccessors (STPState stp)
    {
        ArrayList<STPState> retval = new ArrayList<>();

        return retval;
    }


    public enum SlideDir
    {
        Up, Down, Left, Right;
    }

    //apply operator
    public STPState ApplyOperator(STPState stp, SlideDir o)
    {
        switch (o){
            case Up:


            case Down:

            case Left:

            case Right:
        }

        return stp;
    }

    //undo operator
    public STPState UndoOperator(STPState stp, SlideDir o)
    {
        switch(o){
            case Up:

            case Down:

            case Left:

            case Right:

        }

        return stp;
    }


}

