//
// Created by nobel on 5/7/2018.
//

#include <climits>
#include "HashmapListMap.h"

HashmapListMap::HashmapListMap() {

}

void HashmapListMap::add_element(const FourWayMovement &fw) {
    list.insert({fw, fw});
}

bool HashmapListMap::check_duplicates(const FourWayMovement &fw) {
    std::unordered_map<FourWayMovement, FourWayMovement>::const_iterator it = list.find(fw);
    if(it == list.end()) {
        return false;
    } else {
        return true;
    }
}

void HashmapListMap::update_cost(const FourWayMovement &fw, const FourWayMovement &fw2) {
    STP stp;
    if(list.at(fw).gcost > fw2.gcost + 1) {
        list.at(fw).gcost = fw2.gcost + 1;
        list.at(fw).fcost = list.at(fw).gcost + list.at(fw).hcost;
        STPSlideDir temp = fw2.direction;
        stp.InvertOperator(temp);
        list.at(fw).direction = temp;
        list.at(fw).parent_state = new FourWayMovement(fw2.map_height, fw2.map_width);
        *list.at(fw).parent_state = fw2;
    }
}

FourWayMovement HashmapListMap::remove_best() {
    int min_value = INT_MAX;
    auto it1 = list.begin();
    int width = it1->second.map_width;
    int height = it1->second.map_height;

    FourWayMovement temp(height, width);
    for(auto it = list.begin(); it != list.end(); it++) {
        if(it->second.fcost < min_value) {
            min_value = it->second.fcost;
            temp = it->second;
        }
    }

    list.erase(temp);
    return temp;
}