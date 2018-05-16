//
//  STP.h
//  HW1
//

#ifndef STP_h
#define STP_h

#include <stdio.h>
#include <vector>
#include <ostream>

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
	int tiles[kMaxWidth][kMaxHeight];
	int blankx, blanky;
};

namespace std {
	template <>
	struct hash<STPState>
	{
		std::size_t operator()(const STPState& k) const
		{
			size_t hash = 0;
			for (int x = 0; x < kMaxWidth; x++)
				for (int y = 0; y < kMaxHeight; y++)
					hash = hash*(kMaxHeight*kMaxWidth)+k.tiles[x][y];
			return hash;
		}
	};
}

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

#endif /* STP_hpp */
