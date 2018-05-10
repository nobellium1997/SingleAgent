//
// Created by nobel on 5/9/18.
//

#include "HashmapList.h"

HashmapList::HashmapList() {

}

void HashmapList::add_element(const state_struct &s) {
    map.insert({s.state, 0});
}

bool HashmapList::check_duplicates(const state_struct &s) {
    std::unordered_map<STPState, int> ::const_iterator it = map.find(s.state);
    if(it == map.end()) {
        return false;
    } else {
        return true;
    }
}