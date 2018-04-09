import java.util.ArrayList;

public class DFID {
    public static boolean is_found = false;
    public static int nodes_expanded = 0;

    public static boolean GetPath(STPState start, STPState goal) {
        int index = 0;
        while(!is_found) {
            nodes_expanded = 0;
            depth_first(start, goal, index);
            index++;
        }
        return is_found;
    }

    public static STPState depth_first(STPState start, STPState goal, int depth) {
        nodes_expanded++;
        ArrayList<SlideDir> operators = STP.GetOperators(start);
        if(!start.getParent().equals(start)) {
            for(int i = 0; i < operators.size(); i++) {
                if (operators.get(i) == undo_operator(start.getDirection())) {
                    operators.remove(i);
                }
            }
        }

        for(int i = 0; i < operators.size(); i++) {
            if(is_found) {
                break;
            }
            if(start.equals(goal)) {
                System.out.println("STATE FOUND");
                System.out.print(start);
                is_found = true;
            }
            if(start.getDepth() != depth) {
                SlideDir operator = operators.get(i);
                STPState new_start = STP.ApplyOperator(start, operator);
                new_start.setParent(start.getParent());
                new_start.setDirection(operator);
                new_start.setDepth(start.getDepth() + 1);
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

    public static int GetNodesExpanded() {
        return nodes_expanded;
    }
}
