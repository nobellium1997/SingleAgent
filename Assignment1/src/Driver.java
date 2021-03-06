

import java.awt.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;


public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        STP stp = new STP();

//        s = new STPState(DoRandomWalk_Operator(stp, s, 100));
//        System.out.println("input state: ");
//        System.out.println(s);
        STPState goal = new STPState();
        Heuristic h = new ManhattanDistance();
        int[][] arr = new int[5][3];

        //Test1
        arr[0][0] = 3;
        arr[0][1] = 1;
        arr[0][2] = 2;

        arr[1][0] = 6;
        arr[1][1] = 4;
        arr[1][2] = 5;

        arr[2][0] = 7;
        arr[2][1] = 8;
        arr[2][2] = 0;

        arr[3][0] = 9;
        arr[3][1] = 10;
        arr[3][2] = 11;

        arr[4][0] = 12;
        arr[4][1] = 13;
        arr[4][2] = 14;

        s = new STPState(arr);
        System.out.println(s);
        long start = System.currentTimeMillis();
        ArrayList<SlideDir> path = IDAStar.GetPath(s, goal, h);
        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test1 nodes expanded " + IDAStar.GetNodesExpanded());
        long stop = System.currentTimeMillis();
        System.out.println("Test1 time " + (stop-start) + " milliseconds");
        System.out.println();
//
        //Test 2
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
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test2 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test2 time " + (stop-start) + " milliseconds");
        System.out.println();
//
//            Test3
        arr[0][0] = 3;
        arr[0][1] = 4;
        arr[0][2] = 1;

        arr[1][0] = 6;
        arr[1][1] = 8;
        arr[1][2] = 2;

        arr[2][0] = 9;
        arr[2][1] = 7;
        arr[2][2] = 5;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 11;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 0;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test3 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test3 time " + (stop-start) + " milliseconds");
        System.out.println();


        //Test4
        arr[0][0] = 0;
        arr[0][1] = 3;
        arr[0][2] = 1;

        arr[1][0] = 6;
        arr[1][1] = 4;
        arr[1][2] = 8;

        arr[2][0] = 9;
        arr[2][1] = 7;
        arr[2][2] = 2;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test4 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test4 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test5
        arr[0][0] = 6;
        arr[0][1] = 3;
        arr[0][2] = 1;

        arr[1][0] = 4;
        arr[1][1] = 0;
        arr[1][2] = 8;

        arr[2][0] = 9;
        arr[2][1] = 7;
        arr[2][2] = 2;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test5 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test5 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test6
        arr[0][0] = 6;
        arr[0][1] = 3;
        arr[0][2] = 0;

        arr[1][0] = 9;
        arr[1][1] = 8;
        arr[1][2] = 1;

        arr[2][0] = 7;
        arr[2][1] = 4;
        arr[2][2] = 2;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test6 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test6 time " + (stop-start) + " milliseconds");
        System.out.println();

//            Test7
        arr[0][0] = 6;
        arr[0][1] = 3;
        arr[0][2] = 1;

        arr[1][0] = 9;
        arr[1][1] = 0;
        arr[1][2] = 8;

        arr[2][0] = 7;
        arr[2][1] = 4;
        arr[2][2] = 2;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test7 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test7 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test8
        arr[0][0] = 0;
        arr[0][1] = 6;
        arr[0][2] = 1;

        arr[1][0] = 9;
        arr[1][1] = 3;
        arr[1][2] = 8;

        arr[2][0] = 7;
        arr[2][1] = 4;
        arr[2][2] = 02;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test8 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test8 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test9
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 0;

        arr[1][0] = 9;
        arr[1][1] = 3;
        arr[1][2] = 8;

        arr[2][0] = 7;
        arr[2][1] = 4;
        arr[2][2] = 2;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test9 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test9 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test10
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 2;
        arr[1][2] = 4;

        arr[2][0] = 7;
        arr[2][1] = 3;
        arr[2][2] = 0;

        arr[3][0] = 10;
        arr[3][1] = 13;
        arr[3][2] = 5;

        arr[4][0] = 12;
        arr[4][1] = 14;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test10 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test10 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test11
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 2;
        arr[1][2] = 4;

        arr[2][0] = 7;
        arr[2][1] = 5;
        arr[2][2] = 13;

        arr[3][0] = 10;
        arr[3][1] = 14;
        arr[3][2] = 3;

        arr[4][0] = 0;
        arr[4][1] = 12;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test11 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test11 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test12
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 0;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 5;
        arr[2][2] = 4;

        arr[3][0] = 14;
        arr[3][1] = 12;
        arr[3][2] = 13;

        arr[4][0] = 10;
        arr[4][1] = 11;
        arr[4][2] = 3;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test12 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test12 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test13
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 14;
        arr[3][1] = 13;
        arr[3][2] = 3;

        arr[4][0] = 10;
        arr[4][1] = 11;
        arr[4][2] = 0;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test13 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test13 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test14
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 14;
        arr[3][1] = 0;
        arr[3][2] = 13;

        arr[4][0] = 10;
        arr[4][1] = 11;
        arr[4][2] = 3;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test14 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test14 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test15
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 14;
        arr[3][1] = 0;
        arr[3][2] = 11;

        arr[4][0] = 10;
        arr[4][1] = 3;
        arr[4][2] = 13;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test15 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test15 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test16
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 14;
        arr[3][1] = 0;
        arr[3][2] = 11;

        arr[4][0] = 10;
        arr[4][1] = 3;
        arr[4][2] = 13;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test16 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test16 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test17
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 10;
        arr[3][1] = 14;
        arr[3][2] = 11;

        arr[4][0] = 3;
        arr[4][1] = 13;
        arr[4][2] = 0;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test17 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test17 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test18
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 7;
        arr[2][1] = 12;
        arr[2][2] = 4;

        arr[3][0] = 10;
        arr[3][1] = 0;
        arr[3][2] = 14;

        arr[4][0] = 3;
        arr[4][1] = 13;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test18 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test18 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test19
        arr[0][0] = 6;
        arr[0][1] = 1;
        arr[0][2] = 8;

        arr[1][0] = 9;
        arr[1][1] = 5;
        arr[1][2] = 2;

        arr[2][0] = 10;
        arr[2][1] = 7;
        arr[2][2] = 4;

        arr[3][0] = 12;
        arr[3][1] = 0;
        arr[3][2] = 14;

        arr[4][0] = 3;
        arr[4][1] = 13;
        arr[4][2] = 11;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test19 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test19 time " + (stop-start) + " milliseconds");
        System.out.println();

        //Test20
        arr[0][0] = 5;
        arr[0][1] = 13;
        arr[0][2] = 14;

        arr[1][0] = 2;
        arr[1][1] = 4;
        arr[1][2] = 12;

        arr[2][0] = 0;
        arr[2][1] = 6;
        arr[2][2] = 8;

        arr[3][0] = 3;
        arr[3][1] = 1;
        arr[3][2] = 9;

        arr[4][0] = 11;
        arr[4][1] = 7;
        arr[4][2] = 10;

        s = new STPState(arr);
        System.out.println(s);
        start = System.currentTimeMillis();

        path = IDAStar.GetPath(s, goal, h);
        stop = System.currentTimeMillis();

        for(int i = 0; i < path.size(); i++) {
            System.out.print(path.get(path.size()-1-i) + " ");
        }
        System.out.println();
        System.out.println("Test20 nodes expanded " + IDAStar.GetNodesExpanded());
        System.out.println("Test20 time " + (stop-start) + " milliseconds");
        System.out.println();

//            start = System.currentTimeMillis();
//            DFID.GetPath(s, goal);
//            System.out.println("DFID nodes expanded (test20): " + DFID.GetNodesExpanded());
//            stop = System.currentTimeMillis();
//            System.out.println("DFID time (test20): " + (stop-start) + " milliseconds");
//            System.out.println();


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
