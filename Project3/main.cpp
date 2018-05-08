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
#include "HashmapListMap.h"
#include "AStarMap.h"

int main(int argc, const char * argv[]) {
    std::vector<state_struct> state1;
    state_struct s1;
    s1.fcost = 100;
    state_struct s2;
    s2.fcost = 10;
    state_struct s3;
    s3.fcost = 5;
    state_struct s4;
    s4.fcost = 7;
    state1.push_back(s1);
    state1.push_back(s2);
    state1.push_back(s3);
    state1.push_back(s4);
    std::make_heap(state1.begin(), state1.end(), std::greater<state_struct>());

    for(int i = 0; i < state1.size(); i++) {
        std::cout << state1.at(i).fcost << std::endl;
    }

//    // all this code is to test the map
//    std::ifstream file;
//    std::string file_name = "orz301d.map.scen";
//    file.open(file_name);
//
//    // retrieving start and goal coordinates
//    std::vector<std::pair<int, int>> start_points;
//    std::vector<std::pair<int, int>> end_points;
//
//    std::string line;
//    if(file.is_open()) {
//        int counter = 0;
//        while(std::getline(file, line)) {
//            if(counter == 0) {
//                counter++;
//                continue;
//            }
//            std::pair<int, int> coords;
//            std::istringstream stream(line);
//            std::string temp;
//            for (int i = 0; i < 4; i++) {
//                stream >> temp;
//            }
//            stream >> temp;
//            coords.first = std::stoi(temp, nullptr, 10);
//            stream >> temp;
//            coords.second = std::stoi(temp, nullptr, 10);
//            start_points.push_back(coords);
//
//            stream >> temp;
//            coords.first = std::stoi(temp, nullptr, 10);
//            stream >> temp;
//            coords.second = std::stoi(temp, nullptr, 10);
//            end_points.push_back(coords);
//        }
//    }
//
//    // first test case for map
//    FourWayMovement fw("orz301d.map");
//    fw.posX = start_points.at(0).first;
//    fw.posY = start_points.at(0).second;
//
//    fw.goalX = end_points.at(0).first;
//    fw.goalY = end_points.at(0).second;
//
//    AStarMap a;
//    FWM fwm;
//    MDFourway md;
//    std::vector<STPSlideDir> path;
//    a.GetPath(fwm, fw, md, path);
//    for(int i = 0; i < path.size(); i++) {
//        std::cout << path.at(i) << " ";
//    }


    return 0;
}
