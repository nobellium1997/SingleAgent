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

void HashmapList::update_cost(const STPState &state, const STPState& state2) {
    STP stp;
    if(list.at(state).gcost > state2.gcost + 1) {
        list.at(state).gcost = state2.gcost + 1;
        list.at(state).fcost = list.at(state).gcost + list.at(state).hcost;
        STPSlideDir temp = state2.direction;
        stp.InvertOperator(temp);
        list.at(state).direction = temp;
        list.at(state).parent_state = state2.parent_state;
    }
}

// TODO fix this
STPState HashmapList::remove_best() {
    STPState temp;
    int min_value = INT_MAX;
    for(auto it = list.begin(); it != list.end(); it++) {
        if(it->second.fcost < min_value) {
            min_value = it->second.fcost;
            temp = it->second;
        }
    }
    list.erase(temp);
    return temp;
}