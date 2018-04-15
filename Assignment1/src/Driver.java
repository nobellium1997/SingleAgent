import java.awt.*;
import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        STP stp = new STP();

        s = new STPState(DoRandomWalk_Operator(stp, s, 50));
        System.out.println(s);
        STPState goal = new STPState();

        Heuristic h = new ManhattanDistance();
        long start = System.currentTimeMillis();
        IDAStar.GetPath(s, goal, h);
        STPState state = new STPState(IDAStar.final_state);
        System.out.println();
        System.out.println("PATH");
        while(!state.equals(state.getParent())) {
            System.out.println(state);
            state = new STPState(state.getParent());
        }
//        System.out.println("Depth first nodes expanded " + IDAStar.GetNodesExpanded());
//        long stop = System.currentTimeMillis();
//        System.out.println("Depth first time " + (stop-start) + " milliseconds");
//        System.out.println();

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
