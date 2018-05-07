//
// Created by Nobel on 5/5/2018.
//

#include "InefficientAStar.h"

void InefficientAStar::GetPath(STP& stp, STPState start, STPState &goal, Heuristic* h, std::vector<STPSlideDir>& path) {
    VectorList open_list;
    VectorList closed_list;
    std::vector<STPSlideDir> directions;

    start.gcost = 0;
    start.hcost = h->h(start);
    start.fcost = start.gcost + start.hcost;
    start.direction = kNone;
    start.parent_state = 0;
    open_list.add_element(start);

    while(!open_list.list.empty()) {
        STPState current_state = open_list.remove_best();
        std::cout << "Current state is " << std::endl;
        std::cout << current_state;
        std::cout << "gcost is " << current_state.gcost << std::endl;
        std::cout << "hcost is " << current_state.hcost << std::endl;
        std::cout << "fcost is " << current_state.fcost << std::endl;

        if(current_state == goal) {
            std::cout << "goal found " << std::endl;
            std::cout << current_state;

            STPState curr = current_state;
            while(curr.direction != kNone) {
                path.push_back(opposite_direction(curr.direction));
                curr = *curr.parent_state;
            }

            break;
        }

        stp.GetOperators(current_state, directions);
        expansions++;

        for(auto direction : directions) {
            STPState state = current_state;
            stp.ApplyOperator(state, direction);
            if(!open_list.check_duplicates(state) && !closed_list.check_duplicates(state)) {
                state.hcost = h->h(state);
                state.gcost = current_state.gcost + 1;
                state.fcost = state.hcost + state.gcost;
                state.direction = opposite_direction(direction);
                state.parent_state = new STPState;
                *state.parent_state = current_state;
                open_list.add_element(state);
            } else if(open_list.check_duplicates(state)) {
                open_list.update_cost(state, current_state);
            }
        }

        closed_list.add_element(current_state);
    }
}

STPSlideDir InefficientAStar::opposite_direction(const STPSlideDir &s) {
    switch(s) {
        case kUp:
            return kDown;
        case kDown:
            return kUp;
        case kLeft:
            return kRight;
        case kRight:
            return kLeft;
    }
}