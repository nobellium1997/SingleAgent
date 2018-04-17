import java.awt.*;
import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        STP stp = new STP();

//        s = new STPState(DoRandomWalk_Operator(stp, s, 100));
//        System.out.println(s);
        // ONLY HAD TIME TO DO A COUPLE TESTS
        // sorry I couldn't include them all, super super busy and just absolutely miserable
        System.out.println("input state: ");
        int[][] arr = new int[5][3];
        arr[0][0] = 3;
        arr[0][1] = 4;
        arr[0][2] = 1;
        arr[1][0] = 6;
        arr[1][1] = 0;
        arr[1][2] = 2;
        arr[2][0] = 7;
        arr[2][1] = 8;
        arr[2][2] = 5;
        arr[3][0] = 9;
        arr[3][1] = 10;
        arr[3][2] = 11;
        arr[4][0] = 12;
        arr[4][1] = 13;
        arr[4][2] = 14;
        s = new STPState(arr);
        System.out.println(s);
        STPState goal = new STPState();

        Heuristic h = new ManhattanDistance();
        long start = System.currentTimeMillis();
        ArrayList<SlideDir> path = IDAStar.GetPath(s, goal, h);
        for(int i = 0; i < path.size(); i++)
        {
            System.out.print((path.get(path.size()-1-i)) + " ");
        }
        System.out.println();
        System.out.println("IDA* nodes expanded " + IDAStar.GetNodesExpanded());
        long stop = System.currentTimeMillis();
        System.out.println("IDA* time " + (stop-start) + " milliseconds");
        System.out.println();

        Heuristic h2 = new ManhattanDistance();
        start = System.currentTimeMillis();
        DFID.GetPath(s, goal);
        System.out.println("DFID nodes expanded " + DFID.GetNodesExpanded());
        stop = System.currentTimeMillis();
        System.out.println("DFID time " + (stop-start) + " milliseconds");
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
