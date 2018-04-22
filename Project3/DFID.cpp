//
//  DFID.cpp
//  HW2
//

#include "DFID.h"

// start is passed by value so we don't modify the state in the calling function
void DFID::GetPath(STP &stp, STPState start, STPState &goal)
{
	uint64_t lastExpansions = 0;
	expansions = 0;
	int depth = 0;
	while (true)
	{
		depth++;
		if (BoundedSearch(stp, start, goal, depth, kNone))
			break;
		printf("Depth %d complete; %llu total expansions (%llu new)\n", depth, expansions, expansions-lastExpansions);
		lastExpansions = expansions;
	}
	printf("Goal found at depth %d; %llu total expansions\n", depth, expansions);
}

uint64_t DFID::GetNodesExpanded()
{
	return expansions;
}

bool DFID::BoundedSearch(STP &stp, STPState &curr, STPState &goal, int limit, STPSlideDir forbidden)
{
	if (limit == 0) // stop
	{
		if (curr == goal)
			return true;
		return false;
	}
	
	bool done = false;
	std::vector<STPSlideDir> acts;
	stp.GetOperators(curr, acts);
	expansions++;
	for (auto act : acts)
	{
		if (act == forbidden)
			continue;
		
		stp.ApplyOperator(curr, act);
		stp.InvertOperator(act);
		bool result = BoundedSearch(stp, curr, goal, limit-1, act);
		stp.ApplyOperator(curr, act);

		if (result == true)
		{
			done = true;
			break;
		}
	}
	return done;
}
