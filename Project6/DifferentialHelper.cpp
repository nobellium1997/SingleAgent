//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHelper.h"

DifferentialHelper::DifferentialHelper(const int &x, const int &y) {
    this->points.clear();
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

    if(operators.size() != 0) {
        auto i = operators.at(0);
        if(i == up) {
            goal.posx = x;
            goal.posy = y - 1;
        } else if(i == down) {
            goal.posx = x;
            goal.posy = y + 1;
        } else if(i == right) {
            goal.posy = y;
            goal.posx = x + 1;
        } else {
            goal.posy = y;
            goal.posx = x - 1;
        }
    } else {
        std::cerr << "invalid point";
    }

    operators.clear();
    astar.GetPath(&environment, ew, goal, &h, path, true);

//    std::vector<std::pair<EightWayMovement, double>> vec = astar.get_state_gcost();
//    for(auto i : vec){
//        points.insert({i.first, i.second});
//    }
    points = astar.get_state_gcost();
}
