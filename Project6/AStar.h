//
//  AStar.h
//  HW5
//
//  Created by Nathan Sturtevant on 5/11/18.
//  Copyright © 2018 NS Software. All rights reserved.
//

#ifndef AStar_h
#define AStar_h

#include <vector>
#include <cmath>
#include <iostream>
#include "AStarOpenList.h"
#include "Heuristic.h"

template <class environment, class state, class action>
class AStar {
public:
	void GetPath(environment *env, state start, state goal, Heuristic *h, std::vector<state> &path,
                 const bool& keep_going);
    std::vector<std::pair<state, double>> get_state_gcost();
    double get_state_gcost(state s);
private:
    struct state_gcost {
        state s;
        double gcost;
    };
	AStarOpenList<state> q;
	std::vector<action> acts;
	std::vector<state_gcost> closed_list;
};


template <class environment, class state, class action>
void AStar<environment, state, action>::GetPath(environment *env, state start, state goal,
											   Heuristic *h, std::vector<state> &path, const bool& keep_going)
{
    closed_list.clear();
	path.resize(0);
	q.Reset();
	q.Add(start, 0, h->h(start, goal));
//	int counter = 0;
	while (!q.Empty())
	{
		AStarData<state> next = q.GetNext();
//		std::cout << "Nodes Expanded " << counter << std::endl;
//		counter++;

		if (next.state == goal)
		{
            std::cout << "Final gcost is " << next.g << std::endl;
                      q.GetPath(next.state, path);
			if(!keep_going) {
			    return;
			}
		}
		env->GetOperators(next.state, acts);
		
		for (auto op : acts)
		{
			state tmp = next.state;
			env->ApplyOperator(tmp, op);
			if(op == up || op == down || op == left || op == right) {
				q.Add(tmp, next.g+1, h->h(next.state, goal), next.state);
			} else {
				q.Add(tmp, next.g+std::sqrt(2), h->h(next.state, goal), next.state);
			}
		}

		state_gcost s = {next.state, next.g};
		closed_list.push_back(s);
	}
}

template <class environment, class state, class action>
std::vector<std::pair<state, double>> AStar<environment, state, action>::get_state_gcost() {
    std::vector<std::pair<state, double>> vec;
    std::pair<state, double> this_state;
    for(int i = 0; i < this->closed_list.size(); i++) {
        this_state.first = this->closed_list.at(i).s;
        this_state.second = this->closed_list.at(i).gcost;
        vec.push_back(this_state);
    }
    return vec;
}

template <class environment, class state, class action>
double AStar<environment, state, action>::get_state_gcost(state s) {
    for(int i = 0; i < this->closed_list.size(); i++) {
        if(s == this->closed_list.at(i).s) {
            return this->closed_list.at(i).gcost;
        }
    }
    return 0;
}

#endif /* AStar_h */
