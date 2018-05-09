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
    // this just runs the a star algorithm with an open and closed list and adds to path via parent
    // I know there are a ton of memory leaks with the way I'm getting parent but time was sort of an issue
    // for me
    void GetPath(STP& stp, STPState start, STPState& goal, Heuristic* h, std::vector<STPSlideDir>& path);

    // returns number of nodes expanded and put on the closed list
    uint64_t GetNodesExpanded();

    // dumb helper method because I didn't realize there's already an invert method in Nathan's code
    STPSlideDir opposite_direction(const STPSlideDir& s);
private:
    uint64_t expansions;
};


#endif //PROJECT3_INEFFICIENTASTAR_H
