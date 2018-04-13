import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        STP stp = new STP();

        s = new STPState(DoRandomWalk_Operator(stp, s, 10));
        System.out.println(s);
        STPState goal = new STPState();

        long start = System.currentTimeMillis();
        DFID.GetPath(s, goal);
        System.out.println("Depth first nodes expanded " + DFID.GetNodesExpanded());
        long stop = System.currentTimeMillis();
        System.out.println("Depth first time " + (stop-start) + " milliseconds");
        System.out.println();

        start = System.currentTimeMillis();
        BFS.GetPath(s, goal);
        System.out.println("Breadth first nodes expanded " + BFS.GetNodesExpanded());
        stop = System.currentTimeMillis();
        System.out.println("Breadth first time " + (stop-start) + " milliseconds");
        System.out.println("asiodfiowejf");
        System.out.println("goss SUX");
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
