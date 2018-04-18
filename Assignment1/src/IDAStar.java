import java.util.ArrayList;
import java.util.Collections;

public class IDAStar {
    public static boolean is_found = false;
    public static int nodes_expanded = 0;
    public static int fCost_limit;
    public static boolean is_allocated;
    public static int maxVal;
    public static STPState final_state;


    public static ArrayList<SlideDir> GetPath(STPState start, STPState goal, Heuristic h) {
        is_found = false;
        fCost_limit = 0;
        is_allocated = false;
        nodes_expanded = 0;
        ArrayList<SlideDir> path = new ArrayList<>();
        start.setParent(start);
        start.sethCost(h.manhattan_distance(start, goal));
        start.setgCost(0);
        start.setfCost(start.getgCost()+ start.gethCost());
        maxVal = Integer.MAX_VALUE;
        fCost_limit = start.getfCost();
        while(!is_found) {
            if(is_allocated) {
                fCost_limit = maxVal;
                maxVal = Integer.MAX_VALUE;
                System.out.println("new limit " + fCost_limit);
                ida_star(start, goal, fCost_limit, h);
            } else {
                System.out.println("new limit " + fCost_limit);
                ida_star(start, goal, start.getfCost(), h);
            }

        }
        while(!final_state.equals(final_state.getParent())) {
            path.add(final_state.getDirection());
            final_state = final_state.getParent();
        }
        return path;
    }

    public static void ida_star(STPState start, STPState goal, int fCost, Heuristic h) {
        if(start.equals(goal)) {
            System.out.println("STATE FOUND");
//            System.out.print(start);
            is_found = true;
            final_state = new STPState(start);
            return;
        }

        if(start.getfCost() > fCost) {
            if (start.getfCost() < maxVal) {
                maxVal = start.getfCost();
                is_allocated = true;
            }
            return;
        }

        nodes_expanded++;
        ArrayList<SlideDir> operators = STP.GetOperators(start);
        if(!start.getParent().equals(start)) {
            for(int i = 0; i < operators.size(); i++) {
                if (operators.get(i) == DFID.undo_operator(start.getDirection())) {
                    operators.remove(i);
                }
            }
        }

        ArrayList<STPState> states = new ArrayList<>();
        for(int i = 0; i < operators.size(); i++) {
            if(is_found) {
                break;
            }
            if(start.getfCost() <= fCost) {
                SlideDir operator = operators.get(i);
                STPState new_start = STP.ApplyOperator(start, operator);
                new_start.setParent(start);
                new_start.setDirection(operator);
                new_start.setgCost(start.getgCost() + 1);
                new_start.sethCost(h.manhattan_distance(new_start, goal));
                new_start.setfCost(new_start.getgCost()+new_start.gethCost());
                states.add(new_start);
            }
        }

        // This is just so it can start the search with the lowest fcost. I KNOW IT'S JANKY OK
        // THIS WAS A MAJOR HIT TO THE EGO SO BE NICE
        Collections.sort(states, new JankSort());
        for(int i = 0; i < states.size(); i++) {
            if (is_found) {
                break;
            }
            if (start.getfCost() <= fCost) {
                STPState new_start = new STPState(states.get(i));
                ida_star(new_start, goal, fCost, h);
                if(is_found) {
                    break;
                }
            }
        }

    }

    public static int GetNodesExpanded() {
        return nodes_expanded;
    }
}
