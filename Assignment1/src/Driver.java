import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.ArrayList;
import java.util.Random;

public class Driver {
    public static void main(String[] args) {
        STPState s = new STPState();
        System.out.println(s);
        STP stp = new STP();
        System.out.println("Random walk : ");

        long start = System.currentTimeMillis();
        DoRandomWalk_Operator(stp, s, 100000000);
        long stop = System.currentTimeMillis();
        System.out.println(stop - start);

        start = System.currentTimeMillis();
        DoRandomWalk_Successor(stp, s, 100000000);
        stop = System.currentTimeMillis();
        System.out.println(stop - start);

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
        ArrayList<STP.SlideDir> all_operator;
        for(int i = 0; i < walkDistance; i++) {
            all_operator = stp.GetOperators(state);
            int op_num = rand.nextInt(all_operator.size());
            state = new STPState(stp.ApplyOperator(state, all_operator.get(op_num)));
        }
        return state;
    }

}