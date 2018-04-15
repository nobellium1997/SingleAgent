import java.util.ArrayList;

public class IDAStar {
    public static boolean is_found = false;
    public static int nodes_expanded = 0;
    public static STPState final_state;

    public static boolean GetPath(STPState start, STPState goal, Heuristic h) {
        start.setParent(start);
        start.sethCost(h.manhattan_distance(start, goal));
        start.setgCost(0);
        start.setfCost(start.getgCost()+ start.gethCost());
        int index = start.getfCost();
        while(!is_found) {
            nodes_expanded = 0;
            ida_star(start, goal, index, h);
            index++;
        }
        return is_found;
    }

    public static STPState ida_star(STPState start, STPState goal, int fCost, Heuristic h) {
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
                final_state = new STPState(start);
                break;
            }
            if(start.getfCost() < fCost) {
                SlideDir operator = operators.get(i);
                STPState new_start = STP.ApplyOperator(start, operator);
                new_start.setParent(start);
                new_start.setDirection(operator);
                new_start.setgCost(start.getgCost() + 1);
                new_start.sethCost(h.manhattan_distance(new_start, goal));
                new_start.setfCost(new_start.getgCost()+new_start.gethCost());
                System.out.println(new_start);
                ida_star(new_start, goal, fCost, h);
            }
        }

        return start;
    }

    public static int GetNodesExpanded() {
        return nodes_expanded;
    }
}
