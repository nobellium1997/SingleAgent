//
// Created by Nobel on 5/4/2018.
//

#ifndef PROJECT3_VECTORLIST_H
#define PROJECT3_VECTORLIST_H

#include "STP.h"

class VectorList {
public:
    VectorList();

    // adds element to the list
    void add_element(const state_struct& s);

    // checks for any duplicate states in the list
    // if one is found it returns true otherwise false
    bool check_duplicates(const state_struct& s);

    // updates the cost of a state if the state at index has an fcost less than or equal to the fcost put in
    // as a parameter
    void update_cost(const state_struct& state, const state_struct& state2);

    // returns the state with the lowest fcost
    state_struct remove_best();
    std::vector<state_struct> list;
};


#endif //PROJECT3_VECTORLIST_H
