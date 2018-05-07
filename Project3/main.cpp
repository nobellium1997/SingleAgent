//
//  main.cpp
//  HW1
//

#include <iostream>
#include <unordered_map>
#include "STP.h"
#include "Timer.h"
#include "DFID.h"
#include "BFS.h"
#include "IDA.h"
#include "ManhattanDistance.h"
#include "PDB.h"
#include "All_Heruistics.h"
#include "VectorList.h"
#include "InefficientAStar.h"
#include "FourWayMovement.h"

// using the documentation from http://en.cppreference.com/w/cpp/utility/hash
// to create a custom hash function.
namespace std {
	template<> struct hash<STPState> {
		std::size_t operator()(STPState const& s) const noexcept {
			std::vector<std::size_t> vec;

			for(int y = 0; y < kMaxHeight; y++) {
				for(int x = 0; x < kMaxWidth; x++) {
					vec.push_back(std::hash<int>{}(s.tiles[x][y]));
				}
			}

			std::size_t ret = vec[0];
			for(int i = 1; i < vec.size(); i++) {
				ret ^= (vec[i] << i);
			}
			return ret;
		}
	};
}

void GenerateInstance(int walkDepth)
{
	STPState start, goal;
	STP stp;
	IDA ida;
	ManhattanDistance md;
	DoRandomWalkOperators(stp, start, walkDepth);
	Timer t;
	std::vector<STPSlideDir> path;

	std::cout << start << "\n";

	printf("Starting IDA (MD):\n");
	t.StartTimer();
	ida.GetPath(stp, start, goal, &md, path);
	t.EndTimer();
	printf("%1.2fs elapsed\n", t.GetElapsedTime());

	for (auto i : path)
		std::cout << i << " ";
	std::cout << "\n";
}

void Analyze(int walkDepth)
{
	STPState start, goal;
	STP stp;
	Timer t;
	DFID dfid;
	BFS bfs;
	IDA ida;
	ManhattanDistance md;
	std::vector<STPSlideDir> path;

	printf("<--- Starting new problem with random walk depth %d --->\n", walkDepth);
	DoRandomWalkOperators(stp, start, walkDepth);
	std::cout << "Initial state:\n";
	std::cout << start;

	printf("Starting DFID:\n");
	t.StartTimer();
	dfid.GetPath(stp, start, goal);
	t.EndTimer();
	printf("%1.2fs elapsed\n", t.GetElapsedTime());

	printf("Starting BFS:\n");
	t.StartTimer();
	bfs.GetPath(stp, start, goal);
	t.EndTimer();
	printf("%1.2fs elapsed\n", t.GetElapsedTime());

	printf("Starting IDA (MD):\n");
	t.StartTimer();
	ida.GetPath(stp, start, goal, &md, path);
	t.EndTimer();
	printf("%1.2fs elapsed\n", t.GetElapsedTime());

	for (auto i : path)
		std::cout << i << " ";
	std::cout << "\n";
}

int main(int argc, const char * argv[]) {
    // These might take a while to finish but shouldn't take more than
    // 10 minutes to build the pdb give or take
    // the tests should also not take too long

//    // pattern 1 generation
//    std::vector<uint8_t> ptrn1;
//    for(int i = 0; i < 6; i++) {
//        ptrn1.push_back(i);
//    }
//    PDB pdb1(ptrn1);
//    pdb1.distribution();
//    std::cout << std::endl;
//
//	// pattern 2 generation
//    std::vector<uint8_t> ptrn2;
//    ptrn2.push_back(0);
//    for(int i = 0; i < 6; i++) {
//        ptrn2.push_back(9+i);
//    }
//    PDB pdb2(ptrn2);
//    pdb2.distribution();
//    std::cout << std::endl;
//
//    std::cout << " PDB DONE " << std:: endl;

//    Timer t;
//	STPState goal;
//	std::vector<STPSlideDir> sol;
//
//	STPState state;
//	state.tiles[0][0] = 3;
//	state.tiles[1][0] = 1;
//	state.tiles[2][0] = 2;
//
//	state.tiles[0][1] = 6;
//	state.tiles[1][1] = 4;
//	state.tiles[2][1] = 5;
//
//	state.tiles[0][2] = 7;
//	state.tiles[1][2] = 8;
//	state.tiles[2][2] = 0;
//
//	state.tiles[0][3] = 9;
//	state.tiles[1][3] = 10;
//	state.tiles[2][3] = 11;
//
//	state.tiles[0][4] = 12;
//	state.tiles[1][4] = 13;
//	state.tiles[2][4] = 14;
//
//	state.blankx = 2;
//	state.blanky = 2;
//
////	IDA ida;
//    InefficientAStar a;
//	STP stp;
//
//    std::cout << state << std::endl;
//
////    All_Heruistics ah(pdb1, pdb2);
//    ManhattanDistance m;
//    t.StartTimer();
//    std::vector<STPSlideDir> path;
//	a.GetPath(stp, state, goal, &m, path);
//	t.EndTimer();
//	for(int i = 0; i < path.size(); i++) {
//		std::cout << path[i] << " ";
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << "Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//	std::cout << std::endl;



//    state.tiles[0][0] = 3;
//    state.tiles[1][0] = 4;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 6;
//    state.tiles[1][1] = 0;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 8;
//    state.tiles[2][2] = 5;
//
//    state.tiles[0][3] = 9;
//    state.tiles[1][3] = 10;
//    state.tiles[2][3] = 11;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 13;
//    state.tiles[2][4] = 14;
//
//    state.blankx = 1;
//    state.blanky = 1;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//



//    state.tiles[0][0] = 3;
//    state.tiles[1][0] = 4;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 6;
//    state.tiles[1][1] = 8;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 9;
//    state.tiles[1][2] = 7;
//    state.tiles[2][2] = 5;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 11;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 0;
//
//    state.blankx = 2;
//    state.blanky = 4;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;



//    state.tiles[0][0] = 0;
//    state.tiles[1][0] = 3;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 6;
//    state.tiles[1][1] = 4;
//    state.tiles[2][1] = 8;
//
//    state.tiles[0][2] = 9;
//    state.tiles[1][2] = 7;
//    state.tiles[2][2] = 2;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 0;
//    state.blanky = 0;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 3;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 4;
//    state.tiles[1][1] = 0;
//    state.tiles[2][1] = 8;
//
//    state.tiles[0][2] = 9;
//    state.tiles[1][2] = 7;
//    state.tiles[2][2] = 2;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 1;
//    state.blanky = 1;
//
//    std::cout << state << std::endl;
//	t.StartTimer();
//	path.clear();
//	a.GetPath(stp, state, goal, &m, path);
//	t.EndTimer();
//	for(int i = 0; i < path.size(); i++) {
//		std::cout << path[i] << " ";
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << "Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//	std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 3;
//    state.tiles[2][0] = 0;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 8;
//    state.tiles[2][1] = 1;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 4;
//    state.tiles[2][2] = 2;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 2;
//    state.blanky = 0;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 3;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 0;
//    state.tiles[2][1] = 8;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 4;
//    state.tiles[2][2] = 2;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 1;
//    state.blanky = 1;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 0;
//    state.tiles[1][0] = 6;
//    state.tiles[2][0] = 1;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 3;
//    state.tiles[2][1] = 8;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 4;
//    state.tiles[2][2] = 2;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 0;
//    state.blanky = 0;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 2;
//    state.tiles[2][1] = 4;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 3;
//    state.tiles[2][2] = 0;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 5;
//
//    state.tiles[0][4] = 12;
//    state.tiles[1][4] = 14;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 2;
//    state.blanky = 2;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 2;
//    state.tiles[2][1] = 4;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 5;
//    state.tiles[2][2] = 13;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 14;
//    state.tiles[2][3] = 3;
//
//    state.tiles[0][4] = 0;
//    state.tiles[1][4] = 12;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 0;
//    state.blanky = 4;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 0;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 5;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 14;
//    state.tiles[1][3] = 12;
//    state.tiles[2][3] = 13;
//
//    state.tiles[0][4] = 10;
//    state.tiles[1][4] = 11;
//    state.tiles[2][4] = 3;
//
//    state.blankx = 1;
//    state.blanky = 1;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 12;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 14;
//    state.tiles[1][3] = 13;
//    state.tiles[2][3] = 3;
//
//    state.tiles[0][4] = 10;
//    state.tiles[1][4] = 11;
//    state.tiles[2][4] = 0;
//
//    state.blankx = 2;
//    state.blanky = 4;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 12;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 14;
//    state.tiles[1][3] = 0;
//    state.tiles[2][3] = 13;
//
//    state.tiles[0][4] = 10;
//    state.tiles[1][4] = 11;
//    state.tiles[2][4] = 3;
//
//    state.blankx = 1;
//    state.blanky = 3;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 12;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 14;
//    state.tiles[1][3] = 0;
//    state.tiles[2][3] = 11;
//
//    state.tiles[0][4] = 10;
//    state.tiles[1][4] = 3;
//    state.tiles[2][4] = 13;
//
//    state.blankx = 1;
//    state.blanky = 3;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 12;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 14;
//    state.tiles[2][3] = 11;
//
//    state.tiles[0][4] = 3;
//    state.tiles[1][4] = 13;
//    state.tiles[2][4] = 0;
//
//    state.blankx = 2;
//    state.blanky = 4;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 7;
//    state.tiles[1][2] = 12;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 10;
//    state.tiles[1][3] = 0;
//    state.tiles[2][3] = 14;
//
//    state.tiles[0][4] = 3;
//    state.tiles[1][4] = 13;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 1;
//    state.blanky = 3;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 6;
//    state.tiles[1][0] = 1;
//    state.tiles[2][0] = 8;
//
//    state.tiles[0][1] = 9;
//    state.tiles[1][1] = 5;
//    state.tiles[2][1] = 2;
//
//    state.tiles[0][2] = 10;
//    state.tiles[1][2] = 7;
//    state.tiles[2][2] = 4;
//
//    state.tiles[0][3] = 12;
//    state.tiles[1][3] = 0;
//    state.tiles[2][3] = 14;
//
//    state.tiles[0][4] = 3;
//    state.tiles[1][4] = 13;
//    state.tiles[2][4] = 11;
//
//    state.blankx = 1;
//    state.blanky = 3;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;
//
//    state.tiles[0][0] = 5;
//    state.tiles[1][0] = 13;
//    state.tiles[2][0] = 14;
//
//    state.tiles[0][1] = 2;
//    state.tiles[1][1] = 4;
//    state.tiles[2][1] = 12;
//
//    state.tiles[0][2] = 0;
//    state.tiles[1][2] = 6;
//    state.tiles[2][2] = 8;
//
//    state.tiles[0][3] = 3;
//    state.tiles[1][3] = 1;
//    state.tiles[2][3] = 9;
//
//    state.tiles[0][4] = 11;
//    state.tiles[1][4] = 7;
//    state.tiles[2][4] = 10;
//
//    state.blankx = 0;
//    state.blanky = 2;
//
//    std::cout << state << std::endl;
//    t.StartTimer();
//    ida.GetPath(stp, state, goal, &ah, sol);
//    t.EndTimer();
//    for(int i = 0; i < sol.size(); i++) {
//        std::cout << sol[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Total time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << std::endl;

//	FourWayMovement fw("orz301d.map");
////	FWM fwm;
////	std::vector<FourWayMovement> vec;
////	fwm.GetSuccessors(fw, vec);
////
////	for(int i = 0; i < vec.size(); i++) {
////		std::cout << vec[i] << std::endl;
////	}
//	FWM fwm;
//	std::cout << fw;
	std::unordered_map<STPState, STPState> list;
	STPState s;
	std::pair<STPState, STPState> pair(s,s);
	list.insert(pair);
	std::cout << list.at(s);

	return 0;
}
