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

	EightWayMovement ew("lak9303d.map");
    ew.posy = 4;
	ew.posx = 100;
    EightWayMovement goal("lak303d.map");
	goal.posy = 7;
	goal.posx = 96;
	AStar<EWM, EightWayMovement, EWMoves> astar;
	std::vector<EightWayMovement> path;
	EWM environment;
	EightWayHeuristic h;
	astar.GetPath(&environment, ew, goal, &h, path);


	return 0;
}