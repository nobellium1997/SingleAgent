//
// Created by nobel on 5/7/18.
//

#ifndef PROJECT3_EFFICIENTDATASTRUCTURE_H
#define PROJECT3_EFFICIENTDATASTRUCTURE_H

#include <vector>
#include <unordered_map>
#include "STP.h"

class EfficientDataStructure {
public:
    EfficientDataStructure();
    void add_element(const state_struct& s);
    bool check_duplicates(const state_struct& s);
    void update_cost (const state_struct& state, const state_struct& state2);
    state_struct remove_best();
    void heapify(const int& node_index);
    int get_right_child(const int& index);
    int get_left_child(const int& index);

private:
    std::vector<state_struct> queue;
//    std::unordered_map<STPState, int>  map;
};


#endif //PROJECT3_EFFICIENTDATASTRUCTURE_H
