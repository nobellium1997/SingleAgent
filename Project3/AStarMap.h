//
// Created by nobel on 5/7/18.
//

#ifndef PROJECT3_ASTARMAP_H
#define PROJECT3_ASTARMAP_H


#include "FourWayMovement.h"
#include "Heuristic.h"
#include "MDFourway.h"

class AStarMap {
public:
    void GetPath(FWM& fwm, FourWayMovement fw, MDFourway& h);
    uint64_t GetNodesExpanded();

private:
    uint64_t expansions;

};


#endif //PROJECT3_ASTARMAP_H
