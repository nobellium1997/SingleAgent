//
//  STP.cpp
//  HW1
//

#include "STP.h"
#include <random>

std::ostream& operator<<(std::ostream& out, const STPState& s)
{
	for (int y = 0; y < kMaxHeight; y++)
	{
		for (int x = 0; x < kMaxWidth; x++)
		{
			if (s.tiles[x][y] < 10)
				out << s.tiles[x][y] << "  ";
			else
				out << s.tiles[x][y] << " ";
		}
		out << "\n";
	}
	return out;
}

bool operator==(const STPState &s1, const STPState &s2)
{
	for (int y = 0; y < kMaxHeight; y++)
	{
		for (int x = 0; x < kMaxWidth; x++)
		{
			if (s1.tiles[x][y] != s2.tiles[x][y])
				return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const STPSlideDir& s)
{
	switch (s)
	{
		case kUp:
			out << "Up"; break;
		case kDown:
			out << "Down"; break;
		case kRight:
			out << "Right"; break;
		case kLeft:
			out << "Left"; break;
		case kNone:
			out << "-"; break;
	}
	return out;
}

STPState::STPState()
{
	Reset();
}
void STPState::Reset()
{
	blankx = blanky = 0;
	int count = 0;
	for (int y = 0; y < kMaxHeight; y++)
	{
		for (int x = 0; x < kMaxWidth; x++)
		{
			tiles[x][y] = count++;
		}
	}
}

void STP::GetSuccessors(STPState &s, std::vector<STPState> &states)
{
	states.clear();
	if (s.blankx > 0)
	{
		states.push_back(s);
		ApplyOperator(states.back(), kLeft);
	}
	if (s.blankx < kMaxWidth-1)
	{
		states.push_back(s);
		ApplyOperator(states.back(), kRight);
	}
	if (s.blanky > 0)
	{
		states.push_back(s);
		ApplyOperator(states.back(), kUp);
	}
	if (s.blanky < kMaxHeight-1)
	{
		states.push_back(s);
		ApplyOperator(states.back(), kDown);
	}
}

void STP::GetOperators(STPState &s, std::vector<STPSlideDir> &operators)
{
	operators.clear();
	if (s.blankx > 0)
		operators.push_back(kLeft);
	if (s.blankx < kMaxWidth-1)
		operators.push_back(kRight);
	if (s.blanky > 0)
		operators.push_back(kUp);
	if (s.blanky < kMaxHeight-1)
		operators.push_back(kDown);
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void STP::ApplyOperator(STPState &s, STPSlideDir o)
{
	switch (o)
	{
		case kUp:
			swap(s.tiles[s.blankx][s.blanky], s.tiles[s.blankx][s.blanky-1]);
			s.blanky--;
			break;
		case kDown:
			swap(s.tiles[s.blankx][s.blanky], s.tiles[s.blankx][s.blanky+1]);
			s.blanky++;
			break;
		case kLeft:
			swap(s.tiles[s.blankx][s.blanky], s.tiles[s.blankx-1][s.blanky]);
			s.blankx--;
			break;
		case kRight:
			swap(s.tiles[s.blankx][s.blanky], s.tiles[s.blankx+1][s.blanky]);
			s.blankx++;
			break;
		case kNone:
			break;
	}
}

void STP::UndoOperator(STPState &s, STPSlideDir o)
{
	switch (o)
	{
		case kUp: ApplyOperator(s, kDown);
			break;
		case kDown: ApplyOperator(s, kUp);
			break;
		case kLeft: ApplyOperator(s, kRight);
			break;
		case kRight: ApplyOperator(s, kLeft);
			break;
		case kNone:
			break;
	}
}

void STP::InvertOperator(STPSlideDir &o)
{
	switch (o)
	{
		case kUp: o = kDown;
			break;
		case kDown: o = kUp;
			break;
		case kLeft: o = kRight;
			break;
		case kRight: o = kLeft;
			break;
		case kNone:
			break;
	}
}

void DoRandomWalkSuccessors(STP &puzzle, STPState &s, int length)
{
	std::mt19937 engine{20180404};

	std::vector<STPState> succ;
	s.Reset();
	for (int x = 0; x < length; x++)
	{
		puzzle.GetSuccessors(s, succ);
		std::uniform_int_distribution<int> dist(0, (int)succ.size()-1);
		s = succ[dist(engine)];
	}
}

void DoRandomWalkOperators(STP &puzzle, STPState &s, int length)
{
	std::mt19937 engine{20180404};
	
	std::vector<STPSlideDir> actions;
	s.Reset();
	for (int x = 0; x < length; x++)
	{
		puzzle.GetOperators(s, actions);
		std::uniform_int_distribution<int> dist(0, (int)actions.size()-1);
		puzzle.ApplyOperator(s, actions[dist(engine)]);
	}
}

