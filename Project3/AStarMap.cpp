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

void AStarMap::GetPath(FWM& fwm, FourWayMovement fw, MDFourway& h) {
    VectorListMap open_list;
    VectorListMap closed_list;
    std::vector<STPSlideDir> directions;

    fourway_struct s = {
            0,
            h.h(fw),
            0 + h.h(fw),
            fw,
            0,
            kNone
    };
//    s.state = fw;
//    s.gcost = 0;
//    s.hcost = h.h(fw);
//    s.fcost = s.gcost + s.hcost;
//    s.direction = kNone;
//    s.parent = 0;

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
                state.direction = opposite_direction(direction);
                open_list.add_element(state);
            } else if(open_list.check_duplicates(state)) {
                open_list.update_cost(state, current_state);
            }
        }
    }
}
