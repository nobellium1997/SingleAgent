//
// Created by nobel on 4/21/2018.
//

#ifndef PROJECT3_PDB_H
#define PROJECT3_PDB_H


#include "Heuristic.h"

class PDB : public  Heuristic{
public:
    PDB();
    PDB(const std::vector<uint8_t>& pattern);
    int h(const STPState &s);
    std::vector<uint8_t> dual(const STPState& s);
    void mixed_radix(std::vector<uint8_t>& dual);
    int rank(const STPState& s);
    void BFS(STP &stp, STPState start);
    void distribution();
private:
    struct BFSNode {
        STPState s;
        STPSlideDir forbidden;
        int depth;
    };
    std::vector<int8_t> pdb;
    std::vector<uint8_t> pattern;
    long counter;
};


#endif //PROJECT3_PDB_H
