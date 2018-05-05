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

void VectorList::update_cost(const int& index, const int& gcost, const int& hcost, const int& fcost) {
    if(list[index].fcost > fcost || (list[index].fcost == fcost && list[index].hcost < hcost)) {
        list[index].gcost = gcost;
        list[index].hcost = hcost;
        list[index].fcost = fcost;
    }
}

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