//
//  main.cpp
//  HW1
//

#include <iostream>
#include "STP.h"
#include "Timer.h"
#include "DFID.h"
#include "BFS.h"
#include "IDA.h"
#include "ManhattanDistance.h"
#include "PDB.h"

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
//	Analyze(20);
//	Analyze(30);
//	Analyze(40);
//	Analyze(50);
//	Analyze(60); // This used approximately 1.7 GB on our machine
//
//	for (int x = 10; x < 200; x+=10)
//	{
//		GenerateInstance(x);
//	}
//	GenerateInstance(10000000);

	STPState goal;
	std::vector<uint8_t> ptrn;
	for(int i = 0; i < 6; i++) {
		ptrn.push_back(i);
	}
	PDB pdb(123, ptrn);
//	std::cout << pdb.rank(goal) << std::endl;
	STP stp;
	stp.ApplyOperator(goal, kRight);
	std::cout << goal << std::endl;
	std::cout << pdb.rank(goal);
	return 0;
}

/**
 * Transcript:
 
 <--- Starting new problem with random walk depth 20 --->
 Initial state:
 3  4  1
 6  0  2
 7  8  5
 9  10 11
 12 13 14
 Starting DFID:
 Depth 1 complete; 1 total expansions (1 new)
 Depth 2 complete; 6 total expansions (5 new)
 Depth 3 complete; 20 total expansions (14 new)
 Depth 4 complete; 49 total expansions (29 new)
 Depth 5 complete; 110 total expansions (61 new)
 Depth 6 complete; 237 total expansions (127 new)
 Depth 7 complete; 510 total expansions (273 new)
 Goal found at depth 8; 828 total expansions
 0.00s elapsed
 Starting BFS:
 Depth 0 complete; 1 total expansions (1 new)
 Depth 1 complete; 5 total expansions (4 new)
 Depth 2 complete; 14 total expansions (9 new)
 Depth 3 complete; 29 total expansions (15 new)
 Depth 4 complete; 61 total expansions (32 new)
 Depth 5 complete; 127 total expansions (66 new)
 Depth 6 complete; 273 total expansions (146 new)
 Goal found at depth 8; 426 nodes expanded
 0.00s elapsed
 <--- Starting new problem with random walk depth 30 --->
 Initial state:
 3  4  1
 6  8  2
 9  7  5
 10 13 11
 12 14 0
 Starting DFID:
 Depth 1 complete; 1 total expansions (1 new)
 Depth 2 complete; 4 total expansions (3 new)
 Depth 3 complete; 11 total expansions (7 new)
 Depth 4 complete; 27 total expansions (16 new)
 Depth 5 complete; 64 total expansions (37 new)
 Depth 6 complete; 143 total expansions (79 new)
 Depth 7 complete; 312 total expansions (169 new)
 Depth 8 complete; 651 total expansions (339 new)
 Depth 9 complete; 1362 total expansions (711 new)
 Depth 10 complete; 2781 total expansions (1419 new)
 Depth 11 complete; 5744 total expansions (2963 new)
 Depth 12 complete; 11703 total expansions (5959 new)
 Depth 13 complete; 24222 total expansions (12519 new)
 Goal found at depth 14; 28092 total expansions
 0.01s elapsed
 Starting BFS:
 Depth 0 complete; 1 total expansions (1 new)
 Depth 1 complete; 3 total expansions (2 new)
 Depth 2 complete; 7 total expansions (4 new)
 Depth 3 complete; 16 total expansions (9 new)
 Depth 4 complete; 37 total expansions (21 new)
 Depth 5 complete; 79 total expansions (42 new)
 Depth 6 complete; 169 total expansions (90 new)
 Depth 7 complete; 339 total expansions (170 new)
 Depth 8 complete; 711 total expansions (372 new)
 Depth 9 complete; 1419 total expansions (708 new)
 Depth 10 complete; 2963 total expansions (1544 new)
 Depth 11 complete; 5959 total expansions (2996 new)
 Depth 12 complete; 12519 total expansions (6560 new)
 Goal found at depth 14; 14444 nodes expanded
 0.00s elapsed
 <--- Starting new problem with random walk depth 40 --->
 Initial state:
 0  3  1
 6  4  8
 9  7  2
 10 13 5
 12 14 11
 Starting DFID:
 Depth 1 complete; 1 total expansions (1 new)
 Depth 2 complete; 4 total expansions (3 new)
 Depth 3 complete; 11 total expansions (7 new)
 Depth 4 complete; 27 total expansions (16 new)
 Depth 5 complete; 64 total expansions (37 new)
 Depth 6 complete; 143 total expansions (79 new)
 Depth 7 complete; 312 total expansions (169 new)
 Depth 8 complete; 651 total expansions (339 new)
 Depth 9 complete; 1362 total expansions (711 new)
 Depth 10 complete; 2781 total expansions (1419 new)
 Depth 11 complete; 5744 total expansions (2963 new)
 Depth 12 complete; 11703 total expansions (5959 new)
 Depth 13 complete; 24222 total expansions (12519 new)
 Depth 14 complete; 49317 total expansions (25095 new)
 Depth 15 complete; 101812 total expansions (52495 new)
 Depth 16 complete; 206891 total expansions (105079 new)
 Depth 17 complete; 426946 total expansions (220055 new)
 Depth 18 complete; 868297 total expansions (441351 new)
 Depth 19 complete; 1792640 total expansions (924343 new)
 Goal found at depth 20; 2346173 total expansions
 0.76s elapsed
 Starting BFS:
 Depth 0 complete; 1 total expansions (1 new)
 Depth 1 complete; 3 total expansions (2 new)
 Depth 2 complete; 7 total expansions (4 new)
 Depth 3 complete; 16 total expansions (9 new)
 Depth 4 complete; 37 total expansions (21 new)
 Depth 5 complete; 79 total expansions (42 new)
 Depth 6 complete; 169 total expansions (90 new)
 Depth 7 complete; 339 total expansions (170 new)
 Depth 8 complete; 711 total expansions (372 new)
 Depth 9 complete; 1419 total expansions (708 new)
 Depth 10 complete; 2963 total expansions (1544 new)
 Depth 11 complete; 5959 total expansions (2996 new)
 Depth 12 complete; 12519 total expansions (6560 new)
 Depth 13 complete; 25095 total expansions (12576 new)
 Depth 14 complete; 52495 total expansions (27400 new)
 Depth 15 complete; 105079 total expansions (52584 new)
 Depth 16 complete; 220055 total expansions (114976 new)
 Depth 17 complete; 441351 total expansions (221296 new)
 Depth 18 complete; 924343 total expansions (482992 new)
 Goal found at depth 20; 1202012 nodes expanded
 0.19s elapsed
 <--- Starting new problem with random walk depth 50 --->
 Initial state:
 6  3  1
 4  0  8
 9  7  2
 10 13 5
 12 14 11
 Starting DFID:
 Depth 1 complete; 1 total expansions (1 new)
 Depth 2 complete; 6 total expansions (5 new)
 Depth 3 complete; 20 total expansions (14 new)
 Depth 4 complete; 49 total expansions (29 new)
 Depth 5 complete; 110 total expansions (61 new)
 Depth 6 complete; 237 total expansions (127 new)
 Depth 7 complete; 510 total expansions (273 new)
 Depth 8 complete; 1053 total expansions (543 new)
 Depth 9 complete; 2180 total expansions (1127 new)
 Depth 10 complete; 4451 total expansions (2271 new)
 Depth 11 complete; 9238 total expansions (4787 new)
 Depth 12 complete; 18829 total expansions (9591 new)
 Depth 13 complete; 38860 total expansions (20031 new)
 Depth 14 complete; 78963 total expansions (40103 new)
 Depth 15 complete; 163026 total expansions (84063 new)
 Depth 16 complete; 331673 total expansions (168647 new)
 Depth 17 complete; 684736 total expansions (353063 new)
 Depth 18 complete; 1391687 total expansions (706951 new)
 Depth 19 complete; 2872094 total expansions (1480407 new)
 Goal found at depth 20; 4177047 total expansions
 1.37s elapsed
 Starting BFS:
 Depth 0 complete; 1 total expansions (1 new)
 Depth 1 complete; 5 total expansions (4 new)
 Depth 2 complete; 14 total expansions (9 new)
 Depth 3 complete; 29 total expansions (15 new)
 Depth 4 complete; 61 total expansions (32 new)
 Depth 5 complete; 127 total expansions (66 new)
 Depth 6 complete; 273 total expansions (146 new)
 Depth 7 complete; 543 total expansions (270 new)
 Depth 8 complete; 1127 total expansions (584 new)
 Depth 9 complete; 2271 total expansions (1144 new)
 Depth 10 complete; 4787 total expansions (2516 new)
 Depth 11 complete; 9591 total expansions (4804 new)
 Depth 12 complete; 20031 total expansions (10440 new)
 Depth 13 complete; 40103 total expansions (20072 new)
 Depth 14 complete; 84063 total expansions (43960 new)
 Depth 15 complete; 168647 total expansions (84584 new)
 Depth 16 complete; 353063 total expansions (184416 new)
 Depth 17 complete; 706951 total expansions (353888 new)
 Depth 18 complete; 1480407 total expansions (773456 new)
 Goal found at depth 20; 2133996 nodes expanded
 0.33s elapsed
 <--- Starting new problem with random walk depth 60 --->
 Initial state:
 6  3  0
 9  8  1
 7  4  2
 10 13 5
 12 14 11
 Starting DFID:
 Depth 1 complete; 1 total expansions (1 new)
 Depth 2 complete; 4 total expansions (3 new)
 Depth 3 complete; 11 total expansions (7 new)
 Depth 4 complete; 27 total expansions (16 new)
 Depth 5 complete; 64 total expansions (37 new)
 Depth 6 complete; 143 total expansions (79 new)
 Depth 7 complete; 312 total expansions (169 new)
 Depth 8 complete; 651 total expansions (339 new)
 Depth 9 complete; 1362 total expansions (711 new)
 Depth 10 complete; 2781 total expansions (1419 new)
 Depth 11 complete; 5744 total expansions (2963 new)
 Depth 12 complete; 11703 total expansions (5959 new)
 Depth 13 complete; 24222 total expansions (12519 new)
 Depth 14 complete; 49317 total expansions (25095 new)
 Depth 15 complete; 101812 total expansions (52495 new)
 Depth 16 complete; 206891 total expansions (105079 new)
 Depth 17 complete; 426946 total expansions (220055 new)
 Depth 18 complete; 868297 total expansions (441351 new)
 Depth 19 complete; 1792640 total expansions (924343 new)
 Depth 20 complete; 3644231 total expansions (1851591 new)
 Depth 21 complete; 7521166 total expansions (3876935 new)
 Depth 22 complete; 15292053 total expansions (7770887 new)
 Depth 23 complete; 31565436 total expansions (16273383 new)
 Goal found at depth 24; 56504739 total expansions
 19.13s elapsed
 Starting BFS:
 Depth 0 complete; 1 total expansions (1 new)
 Depth 1 complete; 3 total expansions (2 new)
 Depth 2 complete; 7 total expansions (4 new)
 Depth 3 complete; 16 total expansions (9 new)
 Depth 4 complete; 37 total expansions (21 new)
 Depth 5 complete; 79 total expansions (42 new)
 Depth 6 complete; 169 total expansions (90 new)
 Depth 7 complete; 339 total expansions (170 new)
 Depth 8 complete; 711 total expansions (372 new)
 Depth 9 complete; 1419 total expansions (708 new)
 Depth 10 complete; 2963 total expansions (1544 new)
 Depth 11 complete; 5959 total expansions (2996 new)
 Depth 12 complete; 12519 total expansions (6560 new)
 Depth 13 complete; 25095 total expansions (12576 new)
 Depth 14 complete; 52495 total expansions (27400 new)
 Depth 15 complete; 105079 total expansions (52584 new)
 Depth 16 complete; 220055 total expansions (114976 new)
 Depth 17 complete; 441351 total expansions (221296 new)
 Depth 18 complete; 924343 total expansions (482992 new)
 Depth 19 complete; 1851591 total expansions (927248 new)
 Depth 20 complete; 3876935 total expansions (2025344 new)
 Depth 21 complete; 7770887 total expansions (3893952 new)
 Depth 22 complete; 16273383 total expansions (8502496 new)
 Goal found at depth 24; 28764560 nodes expanded
 4.91s elapsed
 Program ended with exit code: 0
 
 */
