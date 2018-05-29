//
// Created by nobel on 5/20/2018.
//

#ifndef PROJECT6_DIFFERENTIALHEURISTIC_H
#define PROJECT6_DIFFERENTIALHEURISTIC_H

#include <unordered_map>
#include "Heuristic.h"

class DifferentialHeuristic : public  Heuristic {
public:
    DifferentialHeuristic();
    DifferentialHeuristic(const int& x, const int& y);
    double h(const EightWayMovement& ew1, const EightWayMovement& ew2);
    double get_state_gcost(const EightWayMovement& ew1);
    std::unordered_map<EightWayMovement, double> points;
};


#endif //PROJECT6_DIFFERENTIALHEURISTIC_H
