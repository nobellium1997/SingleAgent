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
#include "HashmapListMap.h"

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
//     pattern 1 generation
//    std::vector<uint8_t> ptrn1;
//    for(int i = 0; i < 6; i++) {
//        ptrn1.push_back(i);
//    }
//    PDB pdb1(ptrn1);
//    pdb1.distribution();
//    std::cout << std::endl;

	// pattern 2 generation
//    std::vector<uint8_t> ptrn2;
//    ptrn2.push_back(0);
//    for(int i = 0; i < 6; i++) {
//        ptrn2.push_back(9+i);
//    }
//    PDB pdb2(ptrn2);
//    pdb2.distribution();
//    std::cout << std::endl;
	FourWayMovement fw("orz301d.map");
	std::cout << fw;
	HashmapListMap list;
	fw.gcost = 13;
	list.add_element(fw);
	FourWayMovement fw2("orz301d.map");
	fw2.gcost = 3;
	list.update_cost(fw, fw2);
	std::cout << list.list.at(fw).gcost;
	return 0;
}
