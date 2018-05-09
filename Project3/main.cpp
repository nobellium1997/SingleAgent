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

    AStarMap a;
    FWM fwm;
    MDFourway md;
    std::vector<STPSlideDir> path;
    a.GetPath(fwm, fw, md, path);
    for(int i = 0; i < path.size(); i++) {
        std::cout << path.at(i) << " ";
    }


    return 0;
}
