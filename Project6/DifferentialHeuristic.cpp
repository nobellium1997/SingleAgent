//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHeuristic.h"
#include "AStar.h"
#include "EightWayHeuristic.h"
#include <ctime>

std::pair<int, int> get_random_point(const EightWayMovement& ew);

DifferentialHeuristic::DifferentialHeuristic() {
//    EightWayMovement ew;
//    std::pair<int, int> point = get_random_point(ew);
//    DifferentialHelper dh(point.first, point.second);
//    points = dh.points;
    this->points.clear();
    EightWayMovement ew;
    EightWayMovement goal;
    AStar<EWM, EightWayMovement, EWMoves> astar;
    std::vector<EightWayMovement> path;
    std::vector<EWMoves> operators;
    EWM environment;
    EightWayHeuristic h;
    std::pair<int, int> point = get_random_point(ew);

    int x = point.first;
    int y = point.second;

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
    astar.GetPath(&environment, ew, goal, &h, path, true, this->points);
}

DifferentialHeuristic::DifferentialHeuristic(const int &x, const int &y) {
//    DifferentialHelper dh(x, y);
//    points = dh.points;

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
    astar.GetPath(&environment, ew, goal, &h, path, true, this->points);
}

double DifferentialHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    double ew1_gcost = get_state_gcost(ew1);
    double ew2_gcost = get_state_gcost(ew2);

    return fabs(ew1_gcost - ew2_gcost);
}

double DifferentialHeuristic::get_state_gcost(const EightWayMovement &ew1) {
    return points.at(ew1);
}

std::pair<int, int> get_random_point(const EightWayMovement& ew) {
    while(true) {
        std::pair<int, int> point;
        point.first = std::rand() % ew.map_width;
        point.second = std::rand() % ew.map_height;
        if(ew.map[point.second][point.first] == 1) {
            return point;
        }
    }
}