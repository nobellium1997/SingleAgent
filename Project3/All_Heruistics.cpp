//
// Created by Nobel on 4/22/2018.
//

#include "All_Heruistics.h"

All_Heruistics::All_Heruistics(const PDB &pdb1, const PDB& pdb2) {
    this->pdb1 = pdb1;
    this->pdb2 = pdb2;
}

int All_Heruistics::h(const STPState &s) {
    int val1 = pdb1.h(s);
    int val2 = pdb2.h(s);
    int val3 = mh.h(s);

//    std::cout << val1 << " " << val2 << " " << val3 << std::endl;

    return std::max(val1, std::max(val2, val3));
}