//
// Created by nobel on 5/7/2018.
//

#ifndef PROJECT3_ASTAR_H
#define PROJECT3_ASTAR_H


#include "STP.h"
#include "Heuristic.h"

class AStar {
public:
    void GetPath(STP& stp, STPState start, STPState& goal, Heuristic* h, std::vector<STPSlideDir>& path);
    uint64_t GetNodesExpanded();
    STPSlideDir opposite_direction(const STPSlideDir& s);
private:
    uint64_t expansions;
};


#endif //PROJECT3_ASTAR_H
