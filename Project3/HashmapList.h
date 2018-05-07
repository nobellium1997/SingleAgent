//
// Created by nobel on 5/5/18.
//

#ifndef PROJECT3_HASHMAPLIST_H
#define PROJECT3_HASHMAPLIST_H

#include <unordered_map>
#include "STP.h"

// using the documentation from http://en.cppreference.com/w/cpp/utility/hash
// to create a custom hash function.
namespace std {
    template<> struct hash<STPState> {
        std::size_t operator()(STPState const& s) const noexcept {
            std::vector<std::size_t> vec;

            for(int y = 0; y < kMaxHeight; y++) {
                for(int x = 0; x < kMaxWidth; x++) {
                    vec.push_back(std::hash<int>{}(s.tiles[x][y]));
                }
            }

            std::size_t ret = vec[0];
            for(int i = 1; i < vec.size(); i++) {
                ret ^= (vec[i] << i);
            }
            return ret;
        }
    };
}

class HashmapList {
public:
    HashmapList();

    // all same methods from vector list
    void add_element(const STPState& s);
    bool check_duplicates(const STPState& s);
    void update_cost(const STPState& state, const STPState& state2);
    STPState remove_best();
    std::unordered_map<STPState, STPState> list;
};


#endif //PROJECT3_HASHMAPLIST_H
