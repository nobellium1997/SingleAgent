//
// Created by nobel on 5/21/2018.
//

#include "MaxHeuristic.h"

MaxHeuristic::MaxHeuristic(std::vector<DifferentialHeuristic>& points) {
    this->dh = &points;
}

double MaxHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    double max_val = 0;
    for(int i = 0; i < this->dh->size(); i++/*auto i : *this->dh*/) {
        double temp = this->dh->at(i).h(ew1, ew2);
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