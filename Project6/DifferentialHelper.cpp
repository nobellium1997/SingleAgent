//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHelper.h"

DifferentialHelper::DifferentialHelper(const int &x, const int &y) {
    EightWayMovement ew;
    EightWayMovement goal;
    AStar<EWM, EightWayMovement, EWMoves> astar;
    std::vector<EightWayMovement> path;
    std::vector<EWMoves> operators;
    EWM environment;
    EightWayHeuristic h;

    ew.posx = x;
    ew.posy = y;

    environment.GetOperators(ew, operators);

    for(auto i : operators) {
        if(i == up) {
            goal.posy = y - 1;
        } else if(i == down) {
            goal.posy = y + 1;
        } else if(i == right) {
            goal.posx = x + 1;
        } else {
            goal.posx = x - 1;
        }
    }

    operators.clear();

    astar.GetPath(&environment, ew, goal, &h, path, true);

    points = astar.get_state_gcost();
}
