//
// Created by nobel on 5/7/2018.
//

#include "AStar.h"
#include "EfficientDataStructure.h"
#include "HashmapList.h"

void AStar::GetPath(STP &stp, STPState start, STPState &goal, Heuristic *h, std::vector<STPSlideDir> &path) {
    EfficientDataStructure open_list;
    HashmapList closed_list;
    std::vector<STPSlideDir> directions;

    expansions = 0;
    state_struct s;
    s.state = start;
    s.gcost = 0;
    s.hcost = h->h(start);
    s.fcost = s.hcost + s.gcost;
    s.direction = kNone;
    s.parent = 0;

    open_list.add_element(s);

    while(!open_list.queue.empty()) {
        state_struct current_state = open_list.remove_best();
//        std::cout << "Current state is " << std::endl;
//        std::cout << current_state.state;
//        std::cout << "gcost is " << current_state.gcost << std::endl;
//        std::cout << "hcost is " << current_state.hcost << std::endl;
//        std::cout << "fcost is " << current_state.fcost << std::endl;

        if(current_state.state == goal) {
            std::cout << "goal found " << std::endl;
//            std::cout << current_state.state;

            state_struct curr = current_state;
            while(curr.direction != kNone) {
                path.push_back(opposite_direction(curr.direction));
                curr = *curr.parent;
            }

            break;
        }

        stp.GetOperators(current_state.state, directions);
        expansions++;

        for(auto direction : directions) {
            state_struct state = current_state;
            stp.ApplyOperator(state.state, direction);
            if(!open_list.check_duplicates(state) && !closed_list.check_duplicates(state)) {
                state.hcost = h->h(state.state);
                state.gcost = current_state.gcost + 1;
                state.fcost = state.hcost + state.gcost;
                state.direction = opposite_direction(direction);
                state.parent = new state_struct;
                *state.parent= current_state;
                open_list.add_element(state);
            } else if(open_list.check_duplicates(state)) {
                open_list.update_cost(state, current_state);
            }
        }

        closed_list.add_element(current_state);
    }
}

STPSlideDir AStar::opposite_direction(const STPSlideDir &s) {
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

uint64_t AStar::GetNodesExpanded() {
    return expansions;
}