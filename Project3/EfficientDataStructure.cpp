//
// Created by nobel on 5/7/18.
//

#include "EfficientDataStructure.h"

EfficientDataStructure::EfficientDataStructure() {

}

void EfficientDataStructure::add_element(const state_struct &s) {

}

bool EfficientDataStructure::check_duplicates(const state_struct &s) {

}

void EfficientDataStructure::update_cost(const state_struct &state, const state_struct &state2) {

}

state_struct EfficientDataStructure::remove_best() {

}

bool EfficientDataStructure::has_left_child(const int &x) {
    return ((x*2) + 1) < queue.size();
}

bool EfficientDataStructure::has_right_child(const int &x) {
    return ((x*2) + 2) < queue.size();
}

bool EfficientDataStructure::has_parent(const int &x) {

}

int EfficientDataStructure::get_left_child_index(const int &x) {
    return (x*2) + 1;
}

int EfficientDataStructure::get_right_child_index(const int &x) {
    return (x*2) + 2;
}

int EfficientDataStructure::get_parent_index(const int &x) {

}