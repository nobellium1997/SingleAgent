//
// Created by Nobel on 5/5/2018.
//

#include "InefficientAStar.h"

void InefficientAStar::GetPath(STP& stp, STPState start, STPState &goal, Heuristic* h) {
    VectorList open_list;
    VectorList closed_list;
    std::vector<STPState> states;

    start.gcost = 0;
    start.hcost = h->h(start);
    start.fcost = start.gcost + start.hcost;
    open_list.add_element(start);

    while(!open_list.list.empty()) {
        STPState current_state = open_list.remove_best();
        std::cout << "Current state is " << std::endl;
        std::cout << current_state;
        std::cout << "Fcost is " << current_state.fcost << std::endl;

        if(current_state == goal) {
            std::cout << "goal found " << std::endl;
            std::cout << current_state;
            break;
        }

        stp.GetSuccessors(current_state, states);
        expansions++;

        for(auto state : states) {
            if(!open_list.check_duplicates(state) && !closed_list.check_duplicates(state)) {
                open_list.add_element(state);
            } else if(open_list.check_duplicates(state)) {
                // TODO fix the update method to find the state instead of taking an index
            }
        }

        closed_list.add_element(current_state);
    }
}