//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHelper.h"

DifferentialHelper::DifferentialHelper(const int &x, const int &y) {
    EightWayMovement ew;
    EightWayMovement goal;
    AStar<EWM, EightWayMovement, EWMoves> astar;
    std::vector<EightWayMovement> path;
    std::vector<EWMoves > operators;
    EWM environment;
    EightWayHeuristic h;

    ew.posx = x;
    ew.posy = y;

    // TODO change this
    goal.posx = x + 1;
    goal.posy = y + 1;

    astar.GetPath(&environment, ew, goal, &h, path);

    points = astar.get_state_gcost();
}
