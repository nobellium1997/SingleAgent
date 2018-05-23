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
    std::unordered_map<state, double> get_state_gcost();
    double get_state_gcost(state s);
    int get_nodes_expanded();
    double get_final_gcost();
private:
	AStarOpenList<state> q;
	std::vector<action> acts;
	std::unordered_map<state, double> closed_list;
	int nodes_expanded;
	double final_gcost;
};


template <class environment, class state, class action>
void AStar<environment, state, action>::GetPath(environment *env, state start, state goal,
											   Heuristic *h, std::vector<state> &path, const bool& keep_going)
{
    closed_list.clear();
	path.resize(0);
	q.Reset();
	q.Add(start, 0, h->h(start, goal));
	nodes_expanded = 0;
	while (!q.Empty())
	{
		AStarData<state> next = q.GetNext();
		if (next.state == goal)
		{
			final_gcost = next.g;
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
				q.Add(tmp, next.g+1, h->h(tmp, goal), next.state);
			} else {
				q.Add(tmp, next.g+std::sqrt(2), h->h(tmp, goal), next.state);
			}
		}

		closed_list.insert({next.state, next.g});
		nodes_expanded++;
	}
}

template <class environment, class state, class action>
std::unordered_map<state, double> AStar<environment, state, action>::get_state_gcost() {
    return closed_list;
}

template <class environment, class state, class action>
double AStar<environment, state, action>::get_state_gcost(state s) {
//	std::unordered_map<state, double>::const_iterator it = closed_list.find(s);
//	if(it == closed_list.end()) {
//		return 0;
//	} else {
//		return it->second;
//	}
	return 0;
}

template <class environment, class state, class action>
int AStar<environment, state, action>::get_nodes_expanded() {
	return nodes_expanded;
}

template <class environment, class state, class action>
double AStar<environment, state, action>::get_final_gcost() {
	return final_gcost;
}

#endif /* AStar_h */
