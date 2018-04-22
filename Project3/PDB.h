//
// Created by nobel on 4/21/2018.
//

#ifndef PROJECT3_PDB_H
#define PROJECT3_PDB_H


#include "Heuristic.h"

class PDB : public  Heuristic{
public:
    PDB(uint64_t size);
    int h(const STPState &s);
private:
    uint8_t* pdbA;
};


#endif //PROJECT3_PDB_H
