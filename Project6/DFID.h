//
//  DFID.h
//  HW2
//

#ifndef DFID_hpp
#define DFID_hpp

#include <stdio.h>
#include "STP.h"

class DFID {
public:
	void GetPath(STP &stp, STPState start, STPState &goal);
	uint64_t GetNodesExpanded();
private:
	bool BoundedSearch(STP &stp, STPState &start, STPState &goal, int limit, STPSlideDir forbidden);
	uint64_t expansions;
};

#endif /* DFID_h */
