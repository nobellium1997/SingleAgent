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
        map.insert({s.state, queue.size()-1});
        heapify_up();
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
    STP stp;
    int index = map.at(state.state);
    int old_fcost = state.fcost;
    if(queue.at(index).gcost > state2.gcost + 1) {
        queue.at(index).gcost = state2.gcost + 1;
        queue.at(index).fcost = queue.at(index).gcost + queue.at(index).hcost;
        STPSlideDir temp = state2.direction;
        stp.InvertOperator(temp);
        queue.at(index).direction = temp;
        queue.at(index).parent = new state_struct;
        *queue.at(index).parent = state2;

        heapify_up(index);
    }
}

state_struct EfficientDataStructure::remove_best() {
    auto temp = queue.at(0);
    map.erase(temp.state);
    queue.at(0) = queue.at(queue.size()-1);
    queue.pop_back();
    heapify_down();
    return temp;
}

bool EfficientDataStructure::has_left_child(const int &x) {
    return ((x*2) + 1) < queue.size();
}

bool EfficientDataStructure::has_right_child(const int &x) {
    return ((x*2) + 2) < queue.size();
}

bool EfficientDataStructure::has_parent(const int &x) {
    return (x-1)/2 < queue.size();
}



int EfficientDataStructure::get_left_child_index(const int &x) {
    return (x*2) + 1;
}

int EfficientDataStructure::get_right_child_index(const int &x) {
    return (x*2) + 2;
}

int EfficientDataStructure::get_parent_index(const int &x) {
    return (x-1)/2;
}


state_struct EfficientDataStructure::get_left_child(const int &x) {
    return queue.at(get_left_child_index(x));
}

state_struct EfficientDataStructure::get_right_child(const int &x) {
    return queue.at(get_right_child_index(x));
}

state_struct EfficientDataStructure::get_parent(const int &x) {
    return queue.at(get_parent_index(x));
}



void EfficientDataStructure::swap(const int &first_state_index, const int &second_state_index) {
    auto temp = queue.at(first_state_index);

    map.at(queue.at(first_state_index).state) = second_state_index;
    map.at(queue.at(second_state_index).state) = first_state_index;

    queue.at(first_state_index) = queue.at(second_state_index);
    queue.at(second_state_index) = temp;
}

void EfficientDataStructure::heapify_down() {
    int index = 0;
    while(has_left_child(index)) {
        int smaller_child = get_left_child_index(index);
        if(has_right_child(index) && get_right_child(index).fcost < get_left_child(index).fcost) {
            smaller_child = get_right_child_index(index);
        }

        if(queue.at(index).fcost < queue.at(smaller_child).fcost) {
            break;
        } else {
            swap(index, smaller_child);
        }
        index = smaller_child;
    }
}

void EfficientDataStructure::heapify_up() {
    int index = queue.size()-1;
    // TODO add condition that tie breaks
    while(has_parent(index) && get_parent(index).fcost > queue.at(index).fcost) {
        swap(get_parent_index(index), index);
        index = get_parent_index(index);
    }
}

void EfficientDataStructure::heapify_up(const int &index) {
    int temp_index = index;
    while(has_parent(index) && get_parent(index).fcost > queue.at(index).fcost) {
        swap(get_parent_index(index), index);
        temp_index = get_parent_index(index);
    }
}