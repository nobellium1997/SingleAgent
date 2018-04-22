//
//  IDA.h
//  HW #3
//

#ifndef IDA_h
#define IDA_h

#include <stdio.h>
#include "STP.h"
#include "Heuristic.h"

class IDA {
public:
	void GetPath(STP &stp, STPState start, STPState &goal, Heuristic *h, std::vector<STPSlideDir> &solution);
	uint64_t GetNodesExpanded();
private:
	bool BoundedSearch(STP &stp, STPState &start, STPState &goal, int gcost, STPSlideDir forbidden);
	std::vector<STPSlideDir> path;
	uint64_t expansions;
	int nextBound;
	int currentBound;
	Heuristic *h;
};


#endif /* IDA_h */
