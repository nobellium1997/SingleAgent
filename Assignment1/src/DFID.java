import java.util.ArrayList;
import java.util.Stack;

public class DFID {

//    public static int depth_first(STPState start, STPState goal, int depth) {
//        int node_expand = 0;
//        STPState temp1 = new STPState(start);
//        temp1.setParent(temp1);
//        ArrayList<SlideDir> operations;
//
//        Stack<SlideDir> stack = new Stack<>();
//        do {
//            System.out.println(temp1);
//            if(temp1.equals(goal)) {
//                return node_expand;
//            }
//
//            if (temp1.getDepth() != depth) {
//                operations = STP.GetOperators(temp1);
//                if(!temp1.getParent().equals(temp1)) {
//                    for(int i = 0; i < operations.size(); i++) {
//                        if(operations.get(i) == undo_opeartor(temp1.getDirection())) {
//                            operations.remove(i);
//                        }
//                    }
//                }
//                for (int i = 0; i < operations.size(); i++) {
//                    stack.push(operations.get(i));
//                }
//            } else {
//                System.out.println("Undo");
//                STPState temp2 = STP.UndoOperator(temp1, temp1.getDirection());
//                temp2.setParent(temp1.getParent().getParent());
//                temp2.setDepth(temp1.getParent().getDepth());
//                temp2.setDirection(temp1.getParent().getDirection());
//                temp1 = new STPState(temp2);
//                System.out.println(temp1);
//            }
//
//            SlideDir update_direction = stack.pop();
//            STPState next_state = new STPState(STP.ApplyOperator(temp1, update_direction));
//            next_state.setParent(temp1);
//            next_state.setDepth(next_state.getParent().getDepth()+1);
//            next_state.setDirection(update_direction);
//            temp1 = new STPState(next_state);
//            node_expand++;
//
//
//        } while(!stack.isEmpty());
//        return 0;
//    }

//    public static int index = 0;

    public static STPState depth_first(STPState start, STPState goal, int depth) {
        ArrayList<SlideDir> operators = STP.GetOperators(start);
        if(!start.getParent().equals(start)) {
            for(int i = 0; i < operators.size(); i++) {
                if (operators.get(i) == undo_operator(start.getDirection())) {
                    operators.remove(i);
                }
            }
        }

//        System.out.println(start);
        for(int i = 0; i < operators.size(); i++) {
            if(start.equals(goal)) {
                System.out.println("SUCC");
            }
            if(start.getDepth() != depth) {
                SlideDir operator = operators.get(i);
                STPState new_start = STP.ApplyOperator(start, operator);
                new_start.setParent(start.getParent());
                new_start.setDirection(operator);
                new_start.setDepth(start.getDepth() + 1);
                start = new STPState(new_start);
                System.out.println(start);
//                if (start.equals(goal)) {
//                    System.out.println("GOAL FOUND");
//                    return start;
//                }
                depth_first(start, goal, depth);
            }
//            } else if (start.getDepth() != depth) {
////            else if (start.getDepth() == depth) {
////                System.out.println(start);
////                new_start = new STPState(STP.UndoOperator(start, start.getDirection()));
////                new_start.setParent(start.getParent().getParent());
////                new_start.setDirection(start.getDirection());
////                new_start.setDepth(start.getParent().getDepth()+1);
////                start = new STPState(new_start);
////                System.out.println("Undo");
////                System.out.println(start);
//////                return start;
////
////                continue;
////            }
//                depth_first(start, goal, depth);
//            }
        }

        return start;
    }

    public static SlideDir undo_operator(SlideDir dir){
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
