import java.awt.*;
import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
//        STPState s = new STPState();
//        STP stp = new STP();
//
//        s = new STPState(DoRandomWalk_Operator(stp, s, 10));
//        System.out.println(s);
//        STPState goal = new STPState();
//
//        long start = System.currentTimeMillis();
//        IDAStar.GetPath(s, goal);
//        System.out.println("Depth first nodes expanded " + DFID.GetNodesExpanded());
//        long stop = System.currentTimeMillis();
//        System.out.println("Depth first time " + (stop-start) + " milliseconds");
//        System.out.println();

//        STPState s1 = new STPState();
//        int[][] arr = new int[5][3];
//        int counter = 0;
//        for(int i = 0; i < 5; i ++) {
//            for (int j = 0; j < 3; j++) {
//                arr[i][j] = counter;
//                counter++;
//            }
//        }
//        arr[0][0] = 1;
//        arr[0][1] = 0;
//
//        STPState s2 = new STPState(arr);
//        Heuristic mh = new ManhattanDistance();
//        System.out.println(mh.manhattan_distance(s1, s2));

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
