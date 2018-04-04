import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;

public class BFS {

    // TODO make sure the return type is correct
    public static boolean breadthFirst(STPState start, STPState goal) {
        LinkedBlockingQueue<STPState> queue = new LinkedBlockingQueue<>();
        queue.add(start);
        // this line is just for our janky implementation
        // need to initialize parent to a state that's impossible to reach from the
        // first iteration
        int[][] arr = new int[5][3];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                arr[i][j] = 1;
            }
        }
        STPState parent = new STPState(arr);
        while(!queue.isEmpty()) {
            STPState examineState = queue.remove();
            System.out.println(examineState);
            if(examineState.equals(goal)) {
                return true;
            }
            ArrayList<STPState> states = STP.GetSuccessors(examineState);
            for(int i = 0; i < states.size(); i++) {
                if(states.get(i).equals(parent)) {
                    states.remove(i);
                }
            }
            queue.addAll(states);
            parent = examineState;
        }
        return false;
    }
}
