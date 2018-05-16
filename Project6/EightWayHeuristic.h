//
// Created by nobel on 5/16/2018.
//

#ifndef PROJECT6_EIGHTWAYHEURISTIC_H
#define PROJECT6_EIGHTWAYHEURISTIC_H


#include "Heuristic.h"
#include "EightWayMovement.h"

class EightWayHeuristic : public Heuristic{
public:
    double h(const EightWayMovement& ew1, const EightWayMovement& ew2);
};


#endif //PROJECT6_EIGHTWAYHEURISTIC_H
