//
// Created by nobel on 5/20/2018.
//

#ifndef PROJECT6_DIFFERENTIALHELPER_H
#define PROJECT6_DIFFERENTIALHELPER_H


#include <vector>
#include "EightWayMovement.h"
#include "AStar.h"
#include "EightWayHeuristic.h"

class DifferentialHelper {
public:
    DifferentialHelper(const int& x, const int& y);
//    std::vector<std::pair<EightWayMovement, double>> points;
    std::unordered_map<EightWayMovement, double> points;
};


#endif //PROJECT6_DIFFERENTIALHELPER_H
