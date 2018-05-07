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
#include "HashmapList.h"
#include "AStar.h"

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
        Timer t;
	STPState goal;
	std::vector<STPSlideDir> sol;

	STPState state;
	state.tiles[0][0] = 3;
	state.tiles[1][0] = 1;
	state.tiles[2][0] = 2;

	state.tiles[0][1] = 6;
	state.tiles[1][1] = 4;
	state.tiles[2][1] = 5;

	state.tiles[0][2] = 7;
	state.tiles[1][2] = 8;
	state.tiles[2][2] = 0;

	state.tiles[0][3] = 9;
	state.tiles[1][3] = 10;
	state.tiles[2][3] = 11;

	state.tiles[0][4] = 12;
	state.tiles[1][4] = 13;
	state.tiles[2][4] = 14;

	state.blankx = 2;
	state.blanky = 2;

//	IDA ida;
    AStar a;
	STP stp;

    std::cout << state << std::endl;

//    All_Heruistics ah(pdb1, pdb2);
    ManhattanDistance m;
    t.StartTimer();
    std::vector<STPSlideDir> path;
	a.GetPath(stp, state, goal, &m, path);
	t.EndTimer();
	for(int i = 0; i < path.size(); i++) {
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Time is " << t.GetElapsedTime() << " seconds " << std::endl;
	std::cout << std::endl;

        state.tiles[0][0] = 0;
    state.tiles[1][0] = 6;
    state.tiles[2][0] = 1;

    state.tiles[0][1] = 9;
    state.tiles[1][1] = 3;
    state.tiles[2][1] = 8;

    state.tiles[0][2] = 7;
    state.tiles[1][2] = 4;
    state.tiles[2][2] = 2;

    state.tiles[0][3] = 10;
    state.tiles[1][3] = 13;
    state.tiles[2][3] = 5;

    state.tiles[0][4] = 12;
    state.tiles[1][4] = 14;
    state.tiles[2][4] = 11;

    state.blankx = 0;
    state.blanky = 0;

    std::cout << state << std::endl;
	t.StartTimer();
	path.clear();
	a.GetPath(stp, state, goal, &m, path);
	t.EndTimer();
	for(int i = 0; i < path.size(); i++) {
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Time is " << t.GetElapsedTime() << " seconds " << std::endl;
	std::cout << std::endl;

	return 0;
}
