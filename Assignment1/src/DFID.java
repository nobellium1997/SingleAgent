import java.util.ArrayList;
import java.util.Stack;

public class DFID {

    public static int depth_first(STPState start, STPState goal, int depth) {
        int node_expand = 0;
        STPState temp1 = new STPState(start);
        temp1.setParent(temp1);
        ArrayList<SlideDir> operations;

        Stack<SlideDir> stack = new Stack<>();
        do {
            System.out.println(temp1);
            if(temp1.equals(goal)) {
                return node_expand;
            }

            if (temp1.getDepth() != depth) {
                operations = STP.GetOperators(temp1);
                if(!temp1.getParent().equals(temp1)) {
                    for(int i = 0; i < operations.size(); i++) {
                        if(operations.get(i) == undo_opeartor(temp1.getDirection())) {
                            operations.remove(i);
                        }
                    }
                }
                for (int i = 0; i < operations.size(); i++) {
                    stack.push(operations.get(i));
                }
            } else {
                System.out.println("Undo");
                STPState temp2 = STP.UndoOperator(temp1, temp1.getDirection());
                temp2.setParent(temp1.getParent().getParent());
                temp2.setDepth(temp1.getParent().getDepth());
                temp2.setDirection(temp1.getParent().getDirection());
                temp1 = new STPState(temp2);
                System.out.println(temp1);
            }

            SlideDir update_direction = stack.pop();
            STPState next_state = new STPState(STP.ApplyOperator(temp1, update_direction));
            next_state.setParent(temp1);
            next_state.setDepth(next_state.getParent().getDepth()+1);
            next_state.setDirection(update_direction);
            temp1 = new STPState(next_state);
            node_expand++;


        } while(!stack.isEmpty());
        return 0;
    }

    public static SlideDir undo_opeartor(SlideDir dir){
        switch (dir) {
            case Left:
                return SlideDir.Right;
            case Right:
                return SlideDir.Left;
            case Up:
                return SlideDir.Down;
            case Down:
                return SlideDir.Up;
        }
        return null;
    }
}
