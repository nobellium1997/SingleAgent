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
#include "AStarOpenList.h"
#include "Heuristic.h"

template <class environment, class state, class action>
class AStar {
public:
	void GetPath(environment *env, state start, state goal, Heuristic *h, std::vector<state> &path);
private:
	AStarOpenList<state> q;
	std::vector<action> acts;
};


template <class environment, class state, class action>
void AStar<environment, state, action>::GetPath(environment *env, state start, state goal,
											   Heuristic *h, std::vector<state> &path)
{
	path.resize(0);
	q.Reset();
	q.Add(start, 0, h->h(start, goal));
	while (!q.Empty())
	{
		AStarData<state> next = q.GetNext();
		if (next.state == goal)
		{
			q.GetPath(next.state, path);
			return;
		}
		env->GetOperators(next.state, acts);
		
		for (auto op : acts)
		{
			state tmp = next.state;
			env->ApplyOperator(tmp, op);
			q.Add(tmp, next.g+1, h->h(next.state, goal), next.state);
		}
	}
}


#endif /* AStar_h */
