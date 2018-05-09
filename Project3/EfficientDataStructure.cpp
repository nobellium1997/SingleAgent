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
        heapify();
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
    int index = map.at(state.state);
    STP stp;
    if(queue.at(index).gcost > state2.gcost + 1) {
        queue.at(index).gcost = state2.gcost + 1;
        queue.at(index).fcost = queue.at(index).gcost + queue.at(index).hcost;
        STPSlideDir temp = state2.direction;
        stp.InvertOperator(temp);
        queue.at(index).direction = temp;
        queue.at(index).parent = new state_struct;
        *queue.at(index).parent = state2;
        heapify();
    }
}

state_struct EfficientDataStructure::remove_best() {
    state_struct ret = queue.front();
    queue.pop_front();
    map.erase(ret.state);
    heapify();
    return ret;
}


void EfficientDataStructure::heapify() {
    for(int i = queue.size()/2; i != 0; i--) {
        heapify_helper(i-1);
    }
}

// WARNING this is the jankiest heapify I've ever written please don't judge,
// I know I could have written a swap function but I'm so paranoid of things breaking at this point
// I just left the stupid manual swaps in. Also I know I could have shortened the logic too but whatever it theoretically
// works in O(lgn).
void EfficientDataStructure::heapify_helper(const int& node) {
    int left_child = get_left_child(node);
    int right_child = get_right_child(node);

    if(node > queue.size()/2 - 1) {
        return;
    }

    if(left_child < queue.size() && right_child < queue.size()) {
        if (queue.at(node).fcost > queue.at(left_child).fcost && queue.at(node).fcost > queue.at(right_child).fcost) {
            if (queue.at(left_child).fcost < queue.at(right_child).fcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(left_child);
                queue.at(left_child) = temp;

                map.at(queue.at(node).state) = left_child;
                map.at(queue.at(left_child).state) = node;

                heapify_helper(left_child);
            } else if (queue.at(left_child).fcost >= queue.at(right_child).fcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(right_child);
                queue.at(right_child) = temp;

                map.at(queue.at(node).state) = right_child;
                map.at(queue.at(right_child).state) = node;

                heapify_helper(right_child);
            } else if (queue.at(left_child).hcost < queue.at(right_child).hcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(left_child);
                queue.at(left_child) = temp;

                map.at(queue.at(node).state) = left_child;
                map.at(queue.at(left_child).state) = node;

                heapify_helper(left_child);
            } else if (queue.at(left_child).hcost >= queue.at(right_child).hcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(right_child);
                queue.at(right_child) = temp;

                map.at(queue.at(node).state) = right_child;
                map.at(queue.at(right_child).state) = node;

                heapify_helper(right_child);
            }
        } else if (queue.at(node).fcost > queue.at(left_child).fcost) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(left_child);
            queue.at(left_child) = temp;

            map.at(queue.at(node).state) = left_child;
            map.at(queue.at(left_child).state) = node;

            heapify_helper(left_child);
        } else if (queue.at(node).fcost > queue.at(right_child).fcost) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(right_child);
            queue.at(right_child) = temp;

            map.at(queue.at(node).state) = right_child;
            map.at(queue.at(right_child).state) = node;

            heapify_helper(right_child);
        } else if (queue.at(node).fcost == queue.at(left_child).fcost && queue.at(node).fcost == queue.at(right_child).fcost) {
            if(queue.at(node).hcost > queue.at(left_child).hcost && queue.at(node).hcost > queue.at(right_child).hcost) {
                if(queue.at(left_child).hcost < queue.at(right_child).hcost) {
                    auto temp = queue.at(node);
                    queue.at(node) = queue.at(left_child);
                    queue.at(left_child) = temp;

                    map.at(queue.at(node).state) = left_child;
                    map.at(queue.at(left_child).state) = node;

                    heapify_helper(left_child);
                } else if(queue.at(left_child).hcost >= queue.at(right_child).hcost) {
                    auto temp = queue.at(node);
                    queue.at(node) = queue.at(right_child);
                    queue.at(right_child) = temp;

                    map.at(queue.at(node).state) = right_child;
                    map.at(queue.at(right_child).state) = node;

                    heapify_helper(right_child);
                }
            } else if (queue.at(node).hcost > queue.at(left_child).hcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(left_child);
                queue.at(left_child) = temp;

                map.at(queue.at(node).state) = left_child;
                map.at(queue.at(left_child).state) = node;

                heapify_helper(left_child);
            } else if (queue.at(node).hcost > queue.at(right_child).hcost) {
                auto temp = queue.at(node);
                queue.at(node) = queue.at(right_child);
                queue.at(right_child) = temp;

                map.at(queue.at(node).state) = right_child;
                map.at(queue.at(right_child).state) = node;

                heapify_helper(right_child);
            }
        } else if (queue.at(node).fcost == queue.at(left_child).fcost && queue.at(node).hcost > queue.at(left_child).hcost) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(left_child);
            queue.at(left_child) = temp;

            map.at(queue.at(node).state) = left_child;
            map.at(queue.at(left_child).state) = node;

            heapify_helper(left_child);
        } else if (queue.at(node).fcost == queue.at(right_child).fcost && queue.at(node).hcost > queue.at(right_child).hcost) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(right_child);
            queue.at(right_child) = temp;

            map.at(queue.at(node).state) = right_child;
            map.at(queue.at(right_child).state) = node;

            heapify_helper(right_child);
        }
    } else if (left_child < queue.size()) {
        if(queue.at(node).fcost > queue.at(left_child).fcost || (queue.at(node).fcost == queue.at(left_child).fcost && queue.at(node).hcost > queue.at(left_child).hcost)) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(left_child);
            queue.at(left_child) = temp;

            map.at(queue.at(node).state) = left_child;
            map.at(queue.at(left_child).state) = node;

            heapify_helper(left_child);
        }
    } else if (right_child < queue.size()) {
        if(queue.at(node).fcost > queue.at(right_child).fcost || (queue.at(node).fcost == queue.at(right_child).fcost && queue.at(node).hcost > queue.at(right_child).hcost)) {
            auto temp = queue.at(node);
            queue.at(node) = queue.at(right_child);
            queue.at(right_child) = temp;

            map.at(queue.at(node).state) = right_child;
            map.at(queue.at(right_child).state) = node;

            heapify_helper(right_child);
        }
    }

}

int EfficientDataStructure::get_left_child(const int &x) {
    return (x*2) + 1;
}

int EfficientDataStructure::get_right_child(const int &x) {
    return (x*2) + 2;
}