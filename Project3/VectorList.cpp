//
// Created by Nobel on 5/4/2018.
//

#include <climits>
#include "VectorList.h"

VectorList::VectorList() {

}

void VectorList::add_element(const STPState& s) {
    list.push_back(s);
}

bool VectorList::check_duplicates(const STPState& s) {
    for(int i = 0; i < list.size(); i++) {
        if(list[i] == s) {
            return true;
        }
    }
    return false;
}

void VectorList::update_cost(const STPState& state, const STPState& state2) {
    STP stp;
    for(int i = 0; i < list.size(); i++) {
        if(list[i] == state) {
            if(list[i].gcost < state2.gcost + 1) {
                list[i].gcost = state2.gcost + 1;
                list[i].fcost = list[i].gcost + list[i].hcost;
                STPSlideDir temp = state2.direction;
                stp.InvertOperator(temp);
                list[i].direction = temp;
                list[i].parent_state = new STPState;
                *list[i].parent_state = state2;
            }
            break;
        }
    }

}

// TODO fix tie break so that it goes to lower h cost
STPState VectorList::remove_best() {
    STPState temp;
    int index = 0;
    int min_value = INT_MAX;
    for(int i = 0; i < list.size(); i++) {
        if(list[i].fcost < min_value) {
            min_value = list[i].fcost;
            index = i;
        }
    }
    temp = list[index];
    list.erase(list.begin() + index);
    return temp;
}