//
//  ManhattanDistance.cpp
//  HW #3
//

#include "ManhattanDistance.h"

int ManhattanDistance::h(const STPState &s)
{
	// goal is 0 1 2, 3 4 5, 6 7 8, 9 10 11, 12 13 14
	const int targetX[15] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
	const int targetY[15] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
	
	int h = 0;
	for (int x = 0; x < kMaxWidth; x++)
	{
		for (int y = 0; y < kMaxHeight; y++)
		{
			if (s.tiles[x][y] != 0)
				h += abs(targetX[s.tiles[x][y]]-x) + abs(targetY[s.tiles[x][y]]-y);
		}
	}
	return h;
}
