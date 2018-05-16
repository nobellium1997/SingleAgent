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

int main(int argc, const char * argv[]) {

	EightWayMovement ew;
    ew.posy = 4;
	ew.posx = 100;
    EightWayMovement goal;
	goal.posx = 96;
    goal.posy = 7;
    AStar<EWM, EightWayMovement, EWMoves> astar;
	std::vector<EightWayMovement> path;
	EWM environment;
	EightWayHeuristic h;
	astar.GetPath(&environment, ew, goal, &h, path);
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(i).posx << " " << path.at(i).posy << std::endl;
    }

	return 0;
}