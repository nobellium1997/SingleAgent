//
//  main.cpp
//  HW1
//

#include <iostream>
#include "STP.h"
#include "Timer.h"
#include "DFID.h"
#include "BFS.h"
#include "AStar.h"
#include "EightWayMovement.h"
#include "EightWayHeuristic.h"

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators);

int main(int argc, const char * argv[]) {

	EightWayMovement ew;
    ew.posy = 1;
	ew.posx = 100;
    EightWayMovement goal;
	goal.posx = 96;
    goal.posy = 7;

    AStar<EWM, EightWayMovement, EWMoves> astar;
	std::vector<EightWayMovement> path;
	std::vector<EWMoves> operators;
	EWM environment;
	EightWayHeuristic h;
	astar.GetPath(&environment, ew, goal, &h, path);
    states_to_path(path, operators);
    for(auto op: operators) {
        std::cout << op << " ";
    }

	return 0;
}

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators) {
    EightWayMovement previous_state = states.at(states.size()-1);
    for(int i = states.size()-2; i > -1; i--) {
        EightWayMovement current_state = states.at(i);

        if(current_state.posy > previous_state.posy &&
                current_state.posx > previous_state.posx) {
            operators.push_back(down_right);
        } else if(previous_state.posy > current_state.posy &&
                previous_state.posx > current_state.posx) {
            operators.push_back(up_left);
        } else if (current_state.posy > previous_state.posy &&
                previous_state.posx > current_state.posx) {
            operators.push_back(down_left);
        } else if(previous_state.posy > current_state.posy &&
                current_state.posx > previous_state.posx){
            operators.push_back(up_right);
        } else if(current_state.posy > previous_state.posy) {
            operators.push_back(down);
        } else if(previous_state.posy > current_state.posy) {
            operators.push_back(up);
        } else if (current_state.posx > previous_state.posx) {
            operators.push_back(right);
        } else if(previous_state.posx > current_state.posx) {
            operators.push_back(left);
        }

        previous_state = current_state;
    }
}