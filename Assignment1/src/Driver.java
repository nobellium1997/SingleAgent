import java.awt.*;
import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        STP stp = new STP();

        s = new STPState(DoRandomWalk_Operator(stp, s, 50));
        System.out.println("input state: ");
        System.out.println(s);
        STPState goal = new STPState();

        Heuristic h = new ManhattanDistance();
        long start = System.currentTimeMillis();
        ArrayList<STPState> path = IDAStar.GetPath(s, goal, h);
        System.out.println(path);
        System.out.println("IDA* nodes expanded " + IDAStar.GetNodesExpanded());
        long stop = System.currentTimeMillis();
        System.out.println("IDA* time " + (stop-start) + " milliseconds");
        System.out.println();

    }


    public static STPState DoRandomWalk_Successor(STP stp, STPState state, int walkDistance) {
        state = new STPState();
        Random rand = new Random();
        ArrayList<STPState> all_states;
        for (int i = 0; i < walkDistance; i++) {
            all_states = stp.GetSuccessors(state);
            int state_num = rand.nextInt(all_states.size());
            state = new STPState(all_states.get(state_num));
        }
        return state;
    }

    public static STPState DoRandomWalk_Operator(STP stp, STPState state, int walkDistance) {
        state = new STPState();
        Random rand = new Random();
        ArrayList<SlideDir> all_operator;
        for(int i = 0; i < walkDistance; i++) {
            all_operator = stp.GetOperators(state);
            int op_num = rand.nextInt(all_operator.size());
            state = new STPState(stp.ApplyOperator(state, all_operator.get(op_num)));
        }
        return state;
    }

}
