//
// Created by nobel on 5/21/2018.
//

#ifndef PROJECT6_MAXHEURISTIC_H
#define PROJECT6_MAXHEURISTIC_H


#include "Heuristic.h"
#include "EightWayHeuristic.h"
#include "DifferentialHeuristic.h"

class MaxHeuristic : public Heuristic {
public:
    MaxHeuristic(const std::vector<DifferentialHeuristic>& points);
    double h(const EightWayMovement& ew1, const EightWayMovement& ew2);
    EightWayHeuristic eh;
    std::vector<DifferentialHeuristic> dh;
};


#endif //PROJECT6_MAXHEURISTIC_H
