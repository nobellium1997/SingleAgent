//
// Created by nobel on 5/7/18.
//

#ifndef PROJECT3_EFFICIENTDATASTRUCTURE_H
#define PROJECT3_EFFICIENTDATASTRUCTURE_H

#include <vector>
#include <unordered_map>
#include <queue>
#include "STP.h"

// using the documentation from http://en.cppreference.com/w/cpp/utility/hash
// to create a custom hash function since ranking would have had a ton of overhead to it.
// this simply ranks based on the 2-d array, using the built in hash for ints
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

// uses both hashmap and priority queue to make lookups O(1) and add and deletes O(ln)
class EfficientDataStructure {
public:
    EfficientDataStructure();

    // inserts to both hashmap and queue where the queue sorts by fcost, or if fcost is the same, lower hcost
    void add_element(const state_struct& s);

    // checks for duplicates only in hashmap so that this only takes o(1)
    bool check_duplicates(const state_struct& s);

    // gets the index of where it is in the queue and updates it. after updating we heapify up from the index
    // since this is a min heap we only need to do this once which makes this run time o(ln)
    void update_cost (const state_struct& state, const state_struct& state2);
    state_struct remove_best();

    // All these methods are for maintaining the heap after insertions and deletions
    // this way inserts and deletes remain o(lgn) while lookup in the hashmap remains
    // o(1)
    bool has_left_child(const int& x);
    bool has_right_child(const int& x);
    bool has_parent(const int& x);

    int get_left_child_index(const int& x);
    int get_right_child_index(const int& x);
    int get_parent_index(const int& x);

    state_struct get_left_child(const int& x);
    state_struct get_right_child(const int& x);
    state_struct get_parent(const int& x);

    void swap(const int& first_state_index, const int& second_state_index);
    void heapify_down();
    void heapify_up();
    void heapify_up(const int& index);

    std::deque<state_struct> queue;
    std::unordered_map<STPState, int>  map;
};


#endif //PROJECT3_EFFICIENTDATASTRUCTURE_H
