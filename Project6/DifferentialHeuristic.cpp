//
// Created by nobel on 5/20/2018.
//

#include "DifferentialHeuristic.h"

DifferentialHeuristic::DifferentialHeuristic() {
    DifferentialHelper dh(13, 89);
    points = dh.points;
}

double DifferentialHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    double ew1_gcost = get_state_gcost(ew1);
    double ew2_gcost = get_state_gcost(ew2);

    return fabs(ew1_gcost - ew2_gcost);
}

double DifferentialHeuristic::get_state_gcost(const EightWayMovement &ew1) {
    for(auto i : points) {
        if(i.first.posx == ew1.posx && i.first.posy == ew1.posy) {
            return i.second;
        }
    }
}