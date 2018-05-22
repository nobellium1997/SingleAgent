//
// Created by nobel on 5/21/2018.
//

#include "MaxHeuristic.h"

MaxHeuristic::MaxHeuristic(const std::vector<DifferentialHeuristic>& points) {
    for(auto i : points) {
        this->dh.push_back(i);
    }
}

double MaxHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    double max_val = 0;
    for(auto i : this->dh) {
        if(i.h(ew1, ew2) > max_val) {
            max_val = i.h(ew1, ew2);
        }
    }

    if(max_val < this->eh.h(ew1, ew2)) {
        return this->eh.h(ew1, ew2);
    }

    return max_val;
}