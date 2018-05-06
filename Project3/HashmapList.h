//
// Created by nobel on 5/5/18.
//

#ifndef PROJECT3_HASHMAPLIST_H
#define PROJECT3_HASHMAPLIST_H

#include <unordered_map>
#include "STP.h"

class HashmapList {
public:
    HashmapList();

    // all same methods from vector list
    void add_element(const STPState& s);
    bool check_duplicates(const STPState& s);
    void update_cost(const STPState& state, const int& gcost, const int& hcost, const int& fcost);
    STPState remove_best();
//    std::unordered_map<STPState, STPState> list;

};


#endif //PROJECT3_HASHMAPLIST_H
