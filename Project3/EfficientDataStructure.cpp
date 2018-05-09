//
// Created by nobel on 5/7/18.
//

#include "EfficientDataStructure.h"

EfficientDataStructure::EfficientDataStructure() {

}

void EfficientDataStructure::add_element(const state_struct &s) {
    if(queue.empty()) {
        queue.push_back(s);
        map.insert({s.state, 0});
    } else {
        queue.push_back(s);
        map.insert({s.state, 0});
        heapify();
    }
}

bool EfficientDataStructure::check_duplicates(const state_struct &s) {
    std::unordered_map<STPState, int>::const_iterator it = map.find(s.state);
    if(it == map.end()) {
        return false;
    } else {
        return true;
    }
}

void EfficientDataStructure::update_cost(const state_struct &state, const state_struct &state2) {
    int index = map.at(state.state);
    STP stp;
    if(queue.at(index).gcost > state2.gcost + 1) {
        queue.at(index).gcost = state2.gcost + 1;
        queue.at(index).fcost = queue.at(index).gcost + queue.at(index).hcost;
        STPSlideDir temp = state2.direction;
        stp.InvertOperator(temp);
        queue.at(index).direction = temp;
        queue.at(index).parent = new state_struct;
        *queue.at(index).parent = state2;
        heapify();
    }
}

state_struct EfficientDataStructure::remove_best() {
    state_struct ret = queue.front();
    queue.pop_front();
    map.erase(ret.state);
    heapify();
    return ret;
}


void EfficientDataStructure::heapify() {

}

void EfficientDataStructure::heapify_helper() {

}

int EfficientDataStructure::get_left_child(const int &x) {
    return (x*2) + 1;
}

int EfficientDataStructure::get_right_child(const int &x) {
    return (x*2) + 1;
}