//
//  main.cpp
//  HW1
//

#include <iostream>
#include <unordered_map>
#include <deque>
#include <queue>
#include <sstream>
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
#include "AStarMap.h"
#include "EfficientDataStructure.h"
#include "AStar.h"

int main(int argc, const char * argv[]) {
        // all this code is to test the map
    std::ifstream file;
    std::string file_name = "orz301d.map.scen";
    file.open(file_name);

    // retrieving start and goal coordinates
    std::vector<std::pair<int, int>> start_points;
    std::vector<std::pair<int, int>> end_points;

    std::string line;
    if(file.is_open()) {
        int counter = 0;
        while(std::getline(file, line)) {
            if(counter == 0) {
                counter++;
                continue;
            }
            std::pair<int, int> coords;
            std::istringstream stream(line);
            std::string temp;
            for (int i = 0; i < 4; i++) {
                stream >> temp;
            }
            stream >> temp;
            coords.first = std::stoi(temp, nullptr, 10);
            stream >> temp;
            coords.second = std::stoi(temp, nullptr, 10);
            start_points.push_back(coords);

            stream >> temp;
            coords.first = std::stoi(temp, nullptr, 10);
            stream >> temp;
            coords.second = std::stoi(temp, nullptr, 10);
            end_points.push_back(coords);
        }
    }

    // first test case for map
    FourWayMovement fw("orz301d.map");
    fw.posX = start_points.at(0).first;
    fw.posY = start_points.at(0).second;

    fw.goalX = end_points.at(0).first;
    fw.goalY = end_points.at(0).second;

    AStarMap a_map;
    FWM fwm;
    MDFourway md;
    std::vector<STPSlideDir> path;
    a_map.GetPath(fwm, fw, md, path);
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << a_map.GetNodesExpanded();
    std::cout << std::endl;

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
    InefficientAStar a2;
	STP stp;

    std::cout << state << std::endl;

//    All_Heruistics ah(pdb1, pdb2);
    ManhattanDistance m;
    t.StartTimer();
    path.clear();
	a.GetPath(stp, state, goal, &m, path);
	t.EndTimer();
	for(int i = 0; i < path.size(); i++) {
		std::cout << path.at(path.size()-1-i) << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Efficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
    std::cout << std::endl;


    t.StartTimer();
    path.clear();
    a2.GetPath(stp, state, goal, &m, path);
    t.EndTimer();
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(path.size()-1-i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Inefficient a star nodes expanded " << a2.GetNodesExpanded() << std::endl;
    std::cout << std::endl;


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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
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
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//
        state.tiles[0][0] = 6;
    state.tiles[1][0] = 3;
    state.tiles[2][0] = 1;

    state.tiles[0][1] = 4;
    state.tiles[1][1] = 0;
    state.tiles[2][1] = 8;

    state.tiles[0][2] = 9;
    state.tiles[1][2] = 7;
    state.tiles[2][2] = 2;

    state.tiles[0][3] = 10;
    state.tiles[1][3] = 13;
    state.tiles[2][3] = 5;

    state.tiles[0][4] = 12;
    state.tiles[1][4] = 14;
    state.tiles[2][4] = 11;

    state.blankx = 1;
    state.blanky = 1;

    std::cout << state << std::endl;
    t.StartTimer();
    path.clear();
    a.GetPath(stp, state, goal, &m, path);
    t.EndTimer();
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(path.size()-1-i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
    std::cout << std::endl;

    t.StartTimer();
    path.clear();
    a2.GetPath(stp, state, goal, &m, path);
    t.EndTimer();
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(path.size()-1-i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Inefficient a star nodes expanded " << a2.GetNodesExpanded() << std::endl;
    std::cout << std::endl;

        state.tiles[0][0] = 6;
    state.tiles[1][0] = 3;
    state.tiles[2][0] = 0;

    state.tiles[0][1] = 9;
    state.tiles[1][1] = 8;
    state.tiles[2][1] = 1;

    state.tiles[0][2] = 7;
    state.tiles[1][2] = 4;
    state.tiles[2][2] = 2;

    state.tiles[0][3] = 10;
    state.tiles[1][3] = 13;
    state.tiles[2][3] = 5;

    state.tiles[0][4] = 12;
    state.tiles[1][4] = 14;
    state.tiles[2][4] = 11;

    state.blankx = 2;
    state.blanky = 0;

    std::cout << state << std::endl;
    t.StartTimer();
    path.clear();
    a.GetPath(stp, state, goal, &m, path);
    t.EndTimer();
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(path.size()-1-i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
    std::cout << std::endl;

    t.StartTimer();
    path.clear();
    a2.GetPath(stp, state, goal, &m, path);
    t.EndTimer();
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(path.size()-1-i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
    std::cout << "Inefficient a star nodes expanded " << a2.GetNodesExpanded() << std::endl;
    std::cout << std::endl;
//
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//
//        state.tiles[0][0] = 6;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//        state.tiles[0][0] = 6;
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
//        std::cout << state << std::endl;
//    t.StartTimer();
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//        state.tiles[0][0] = 5;
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
//    path.clear();
//    a.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Efficient a star Time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Efficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;
//
//    t.StartTimer();
//    path.clear();
//    a2.GetPath(stp, state, goal, &m, path);
//    t.EndTimer();
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(path.size()-1-i) << " ";
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "Inefficient a star time is " << t.GetElapsedTime() << " seconds " << std::endl;
//    std::cout << "Inefficient a star nodes expanded " << a.GetNodesExpanded() << std::endl;
//    std::cout << std::endl;


    return 0;
}
