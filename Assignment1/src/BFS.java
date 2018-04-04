import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;

public class BFS {

    // TODO make sure the return type is correct
    public static boolean breadthFirst(STPState start, STPState goal) {
        LinkedBlockingQueue<STPState> queue = new LinkedBlockingQueue<>();
        queue.add(start);
        STPState parent = new STPState();
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
