//
// Created by nobel on 5/21/2018.
//

#include "MaxHeuristic.h"

MaxHeuristic::MaxHeuristic(std::vector<DifferentialHeuristic>& points) {
    this->dh = &points;
}

double MaxHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    double max_val = 0;
    for(auto i : *this->dh) {
        double temp = i.h(ew1, ew2);
        if(temp > max_val) {
            max_val = temp;
        }
    }

    double temp = this->eh.h(ew1, ew2);
    if(max_val < temp) {
        return temp;
    }

    return max_val;
}