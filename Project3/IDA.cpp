//
//  IDA.cpp
//  HW #3
//

#include <climits>
#include "IDA.h"


// start is passed by value so we don't modify the state in the calling function
void IDA::GetPath(STP &stp, STPState start, STPState &goal, Heuristic *heuristic, std::vector<STPSlideDir> &solution)
{
	uint64_t lastExpansions = 0;
	h = heuristic;
	expansions = 0;
	currentBound = h->h(start);
	path.clear();
	while (true)
	{
		nextBound = INT_MAX;
		if (BoundedSearch(stp, start, goal, 0, kNone))
			break;
		printf("Bound %d complete; %llu total expansions (%llu new)\n", currentBound, expansions, expansions-lastExpansions);
		lastExpansions = expansions;
		currentBound = nextBound;
	}
	printf("Goal found at cost %d; %llu total expansions\n", (int)path.size(), expansions);
	solution = path;
}

uint64_t IDA::GetNodesExpanded()
{
	return expansions;
}

bool IDA::BoundedSearch(STP &stp, STPState &curr, STPState &goal, int gcost, STPSlideDir forbidden)
{
	int currentF = gcost + h->h(curr);
	if (currentF > currentBound) // stop
	{
		nextBound = std::min(gcost + h->h(curr), nextBound);
		return false;
	}
	
	if (curr == goal)
		return true;

	bool done = false;
	std::vector<STPSlideDir> acts;
	stp.GetOperators(curr, acts);
	expansions++;
	for (auto act : acts)
	{
		if (act == forbidden)
			continue;
		path.push_back(act);
		stp.ApplyOperator(curr, act);
		stp.InvertOperator(act);
		bool result = BoundedSearch(stp, curr, goal, gcost+1, act);
		stp.ApplyOperator(curr, act);
		
		if (result == true)
		{
			done = true;
			break;
		}

		path.pop_back();
	}
	return done;
}
