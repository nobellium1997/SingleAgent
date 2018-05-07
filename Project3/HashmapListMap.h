//
// Created by nobel on 5/7/2018.
//

#ifndef PROJECT3_HASHMAPLISTMAP_H
#define PROJECT3_HASHMAPLISTMAP_H

#include <unordered_map>
#include "FourWayMovement.h"

namespace std {
    template<> struct hash<FourWayMovement> {
        std::size_t operator()(FourWayMovement const& fw) const noexcept  {
            std::size_t val1 = std::hash<int>{}(fw.posX);
            std::size_t val2 = std::hash<int>{}(fw.posY);
            return val1 ^ (val2 << 1);
        }
    };
}

class HashmapListMap {
public:
    HashmapListMap();
    void add_element(const FourWayMovement& fw);
    bool check_duplicates(const FourWayMovement& fw);
    void update_cost(const FourWayMovement& fw, const FourWayMovement& fw2);
    FourWayMovement remove_best();
    std::unordered_map<FourWayMovement, FourWayMovement> list;
};


#endif //PROJECT3_HASHMAPLISTMAP_H
