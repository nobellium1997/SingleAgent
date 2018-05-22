//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHeuristic.h"

DifferentialHeuristic::DifferentialHeuristic(const int& x, const int& y) {
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