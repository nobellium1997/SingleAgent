//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHeuristic.h"

std::pair<int, int> get_random_point(const EightWayMovement& ew);

DifferentialHeuristic::DifferentialHeuristic() {
    EightWayMovement ew;
    std::pair<int, int> point = get_random_point(ew);
    DifferentialHelper dh(point.first, point.second);
    points = dh.points;
}

DifferentialHeuristic::DifferentialHeuristic(const int &x, const int &y) {
    DifferentialHelper dh(x, y);
    points = dh.points;
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
        point.first = rand() % ew.map_width;
        point.second = rand() % ew.map_height;
        if(ew.map[point.second][point.first] == 1) {
            return point;
        }
    }
}