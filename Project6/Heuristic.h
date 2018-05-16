//
//  Heuristic.h
//  HW #3
//
//  Created by Nathan Sturtevant on 4/15/18.
//  Copyright © 2018 NS Software. All rights reserved.
//

#ifndef Heuristic_h
#define Heuristic_h

#include "STP.h"
#include "EightWayMovement.h"

class Heuristic {
public:
	virtual ~Heuristic() {}
	virtual double h(const EightWayMovement&, const EightWayMovement&) = 0;
};

#endif /* Heuristic_h */
