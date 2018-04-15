import java.util.ArrayList;

public class IDAStar {
    public static boolean is_found = false;
    public static int nodes_expanded = 0;

    public static boolean GetPath(STPState start, STPState goal) {
        start.setParent(start);
        int index = 0;
        while(!is_found) {
            nodes_expanded = 0;
            ida_star(start, goal, index);
            index++;
        }
        return is_found;
    }

    public static STPState ida_star(STPState start, STPState goal, int depth) {
        nodes_expanded++;
        ArrayList<SlideDir> operators = STP.GetOperators(start);
        if(!start.getParent().equals(start)) {
            for(int i = 0; i < operators.size(); i++) {
                if (operators.get(i) == DFID.undo_operator(start.getDirection())) {
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
                new_start.setParent(start);
                new_start.setDirection(operator);
                new_start.setDepth(start.getDepth() + 1);
                ida_star(new_start, goal, depth);
            }
        }

        return start;
    }

    public static int GetNodesExpanded() {
        return nodes_expanded;
    }
}
