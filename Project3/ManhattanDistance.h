//
//  ManhattanDistance.h
//  HW #3
//

#ifndef ManhattanDistance_h
#define ManhattanDistance_h

#include <stdio.h>
#include "Heuristic.h"

class ManhattanDistance : public Heuristic {
public:
	int h(const STPState &s);
};


#endif /* ManhattanDistance_h */
