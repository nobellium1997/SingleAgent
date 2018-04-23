//
// Created by Nobel on 4/22/2018.
//

#ifndef PROJECT3_ALL_HERUISTICS_H
#define PROJECT3_ALL_HERUISTICS_H


#include "Heuristic.h"
#include "ManhattanDistance.h"
#include "PDB.h"

class All_Heruistics : public Heuristic {
public:
    All_Heruistics(const PDB& pdb1);
    int h(const STPState& s);

private:
    ManhattanDistance mh;
    PDB pdb1;
};


#endif //PROJECT3_ALL_HERUISTICS_H
