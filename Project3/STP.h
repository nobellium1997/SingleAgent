//
//  STP.h
//  HW1
//

#ifndef STP_h
#define STP_h

#include <stdio.h>
#include <vector>
#include <iostream>

const int kMaxWidth = 3;
const int kMaxHeight = 5;

enum STPSlideDir  {
	kUp,
	kDown,
	kRight,
	kLeft,
	kNone
};

class STPState {
public:
	STPState();   // Init to goal state - default constructor will copy
	void Reset(); // Reset to goal state
	STPState& operator=(const STPState& s2);
	int tiles[kMaxWidth][kMaxHeight];
	int blankx, blanky;
	int gcost, hcost, fcost;
	STPSlideDir direction;
	STPState* parent_state;
};

std::ostream& operator<<(std::ostream& out, const STPState& s);
std::ostream& operator<<(std::ostream& out, const STPSlideDir& s);
bool operator==(const STPState &s1, const STPState &s2);


class STP {
public:
	void GetSuccessors(STPState &s, std::vector<STPState> &states);
	void GetOperators(STPState &s, std::vector<STPSlideDir> &operators);
	void ApplyOperator(STPState &s, STPSlideDir o);
	void UndoOperator(STPState &s, STPSlideDir o);
	void InvertOperator(STPSlideDir &o);
};

void DoRandomWalkSuccessors(STP &puzzle, STPState &s, int length);
void DoRandomWalkOperators(STP &puzzle, STPState &s, int length);


struct state_struct {
	STPState state;
	state_struct* parent;
	int gcost, hcost, fcost;
	STPSlideDir direction;
};

#endif /* STP_hpp */
