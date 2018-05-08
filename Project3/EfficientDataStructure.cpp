//
// Created by nobel on 5/7/18.
//

#include "EfficientDataStructure.h"

EfficientDataStructure::EfficientDataStructure() {

}

void EfficientDataStructure::add_element(const state_struct &s) {
    map.insert({s.state,s});
    heap.push_back(s);
    std::make_heap(heap.begin(), heap.end(), std::greater<state_struct>());
}

bool EfficientDataStructure::check_duplicates(const state_struct &s) {
    std::unordered_map<STPState, state_struct>::const_iterator it = map.find(s.state);
    if(it == map.end()) {
        return false;
    } else {
        return true;
    }
}

state_struct EfficientDataStructure::remove_best() {
    state_struct temp = heap.front();
    std::pop_heap(heap.begin(), heap.end(), std::greater<state_struct>());
    heap.pop_back();
    map.erase(temp.state);
    return temp;
}