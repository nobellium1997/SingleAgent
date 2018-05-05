//
// Created by Nobel on 5/5/2018.
//

#ifndef PROJECT3_INEFFICIENTASTAR_H
#define PROJECT3_INEFFICIENTASTAR_H


#include "STP.h"

class InefficientAStar {
public:
    void GetPath(STP* stp, STPState start, STPState& goal);
    uint64_t GetNodesExpanded();
private:

};


#endif //PROJECT3_INEFFICIENTASTAR_H
