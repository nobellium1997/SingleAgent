//
// Created by Nobel on 5/5/2018.
//

#ifndef PROJECT3_INEFFICIENTASTAR_H
#define PROJECT3_INEFFICIENTASTAR_H


#include "STP.h"
#include "VectorList.h"
#include "Heuristic.h"

class InefficientAStar {
public:
    void GetPath(STP& stp, STPState start, STPState& goal, Heuristic* h);
    uint64_t GetNodesExpanded();
private:
//    VectorList open_list;
//    VectorList closed_list;
    uint64_t expansions;
};


#endif //PROJECT3_INEFFICIENTASTAR_H
