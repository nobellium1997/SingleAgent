//
// Created by nobel on 5/7/18.
//

#include <climits>
#include "VectorListMap.h"

VectorListMap::VectorListMap() {

}

void VectorListMap::add_element(const fourway_struct &fw) {
    list.push_back(fw);
}

bool VectorListMap::check_duplicates(const fourway_struct &fw) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i).state == fw.state) {
            return true;
        }
    }
    return false;
}

void VectorListMap::update_cost(const fourway_struct &fw1, const fourway_struct &fw2) {
    STP stp;
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i).state == fw1.state) {
            if(list.at(i).gcost > fw2.gcost + 1) {
                list.at(i).gcost = fw2.gcost + 1;
                list.at(i).fcost = list.at(i).gcost + list.at(i).hcost;
                STPSlideDir temp = fw2.direction;
                stp.InvertOperator(temp);
                list.at(i).direction = temp;

                // TODO FIX THE PARENT
//                list.at(i).parent = new fourway_struct;
//                *list.at(i).parent = fw2;
            }
        }
    }
}

fourway_struct VectorListMap::remove_best() {
    int index = 0;
    int min_value = INT_MAX;
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i).fcost < min_value) {
            min_value = list.at(i).fcost;
            index = i;
        }
    }
    fourway_struct temp = list.at(index);
    list.erase(list.begin()+index);
    return temp;
}