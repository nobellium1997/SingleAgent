import java.util.ArrayList;
import java.util.Stack;

public class DFID {
    public static boolean is_found;

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
            if(is_found) {
                break;
            }
            if(start.equals(goal)) {
                System.out.println("SUCC");
                is_found = true;
            }
            if(start.getDepth() != depth) {
                SlideDir operator = operators.get(i);
                STPState new_start = STP.ApplyOperator(start, operator);
                new_start.setParent(start.getParent());
                new_start.setDirection(operator);
                new_start.setDepth(start.getDepth() + 1);
                System.out.println(new_start);
                depth_first(new_start, goal, depth);
            }
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
