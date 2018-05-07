//
// Created by nobel on 5/5/18.
//

#include <climits>
#include "HashmapList.h"

HashmapList::HashmapList() {

}

void HashmapList::add_element(const STPState &s) {
    list.insert({s, s});
}

bool HashmapList::check_duplicates(const STPState &s) {
    std::unordered_map<STPState, STPState>::const_iterator it = list.find(s);
    if(it == list.end()) {
        return false;
    } else {
        return true;
    }
}

void HashmapList::update_cost(const STPState &state, const int &gcost, const int &hcost, const int &fcost) {
    if(list.at(state).gcost < gcost + 1) {
        list.at(state).gcost = gcost + 1;
        list.at(state).fcost = list.at(state).gcost + list.at(state).hcost;
    }
}

STPState HashmapList::remove_best() {
//    STPState temp;
//    int min_value = INT_MAX;
//    for(auto it = list.begin(); it < list.end(); it++) {
//
//    }
}