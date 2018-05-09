//
// Created by nobel on 5/7/18.
//

#include "AStarMap.h"
#include "VectorListMap.h"
#include "MDFourway.h"

STPSlideDir opposite_direction(const STPSlideDir& s) {
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

void AStarMap::GetPath(FWM& fwm, FourWayMovement fw, MDFourway& h, std::vector<STPSlideDir>& path) {
    VectorListMap open_list;
    VectorListMap closed_list;
    std::vector<STPSlideDir> directions;

    expansions = 0;

    fourway_struct s = {
            0,
            h.h(fw),
            0 + h.h(fw),
            fw,
            kNone,
            0
    };
    open_list.add_element(s);
    int goalX = fw.goalX;
    int goalY = fw.goalY;

    while(!open_list.list.empty()) {
        fourway_struct current_state = open_list.remove_best();
        std::cout << "CURRENT STATE X " << current_state.state.posX << " CURRENT STATE Y " << current_state.state.posY << std::endl;
        std::cout << "CURRENT STATE GCOST " << current_state.gcost << std::endl;
        std::cout << "CURRENT STATE HCOST " << current_state.hcost << std::endl;
        std::cout << "CURRENT STATE FCOST " << current_state.fcost << std::endl;

        if(current_state.state.posX == goalX && current_state.state.posY == goalY) {
            std::cout << "GOAL FOUND" << std::endl;
            std::cout << "x coord is " << current_state.state.posX << " y coord is " << current_state.state.posY << std::endl;

            direction_struct curr = current_state.dir;
            while(curr.direction != kNone) {
                path.push_back(opposite_direction(curr.direction));
                curr = *curr.parent;
            }

            break;
        }

        fwm.GetOperators(current_state.state, directions);
        expansions++;

        for(auto direction : directions) {
            fourway_struct state = current_state;
            fwm.ApplyOperator(state.state, direction);
            if(!open_list.check_duplicates(state) && !closed_list.check_duplicates(state)) {
                state.hcost = h.h(state.state);
                state.gcost = current_state.gcost + 1;
                state.fcost = state.hcost + state.gcost;
                state.dir.direction = opposite_direction(direction);
                state.dir.parent = new direction_struct;
                *state.dir.parent = current_state.dir;
                open_list.add_element(state);
            } else if(open_list.check_duplicates(state)) {
                open_list.update_cost(state, current_state);
            }
        }
    }
}

uint64_t AStarMap::GetNodesExpanded() {
    return expansions;
}