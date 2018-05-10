//
// Created by nobel on 5/9/18.
//

#ifndef PROJECT3_HASHMAPLIST_H
#define PROJECT3_HASHMAPLIST_H

#include <unordered_map>
#include "STP.h"
#include "EfficientDataStructure.h"

/*
 * this whole class is just for the closed list in efficient
 * this way check_duplicates is o(1)
 */


class HashmapList {
public:
    HashmapList();
    void add_element(const state_struct& s);
    bool check_duplicates(const state_struct& s);

    // the key value here can be anything
    std::unordered_map<STPState, int> map;
};


#endif //PROJECT3_HASHMAPLIST_H
