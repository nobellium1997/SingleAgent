//
// Created by nobel on 5/7/18.
//

#ifndef PROJECT3_VECTORLISTMAP_H
#define PROJECT3_VECTORLISTMAP_H


#include "FourWayMovement.h"

/*
 * same as normal vector list except for a struct
 * for the fourway class which just owns different values
 */

class VectorListMap {
public:
    VectorListMap();
    void add_element(const fourway_struct& fw);
    bool check_duplicates(const fourway_struct& fw);
    void update_cost(const fourway_struct& fw1, const fourway_struct& fw2);
    fourway_struct remove_best();
    std::vector<fourway_struct> list;
};


#endif //PROJECT3_VECTORLISTMAP_H
