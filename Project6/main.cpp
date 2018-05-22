//
//  main.cpp
//  HW1
//

#include <iostream>
#include <sstream>
#include "STP.h"
#include "Timer.h"
#include "DFID.h"
#include "BFS.h"
#include "AStar.h"
#include "EightWayMovement.h"
#include "EightWayHeuristic.h"
#include "DifferentialHelper.h"
#include "DifferentialHeuristic.h"
#include "MaxHeuristic.h"

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators);

int main(int argc, const char * argv[]) {
    // all this code is to test the map
    std::ifstream file;
    std::string file_name = "lak303d.map.scen";
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
    } else {
        std::cerr << "No file found ";
    }

    EightWayMovement ew;
    EightWayMovement goal;
    AStar<EWM, EightWayMovement, EWMoves> astar;
    std::vector<EightWayMovement> path;
    std::vector<EWMoves> operators;
    EWM environment;

    DifferentialHeuristic dh(90, 189);
    DifferentialHeuristic dh2(7, 111);
    DifferentialHeuristic dh3(184, 108);
    DifferentialHeuristic dh4(98, 7);
    DifferentialHeuristic dh5(95, 97);

    std::vector<DifferentialHeuristic> pivot_points;
    pivot_points.push_back(dh);
    pivot_points.push_back(dh2);
    pivot_points.push_back(dh3);
    pivot_points.push_back(dh4);
    pivot_points.push_back(dh5);

    MaxHeuristic h(pivot_points);
//    EightWayHeuristic h;

    for(int i = 0; i < 1; i++) {
        ew.posx = start_points.at(i).first;
        ew.posy = start_points.at(i).second;

        goal.posx = end_points.at(i).first;
        goal.posy = end_points.at(i).second;

        std::cout << "Solution from " << start_points.at(i).first << ", " << start_points.at(i).second
                  << " to " << end_points.at(i).first
                  << ", "
                  << end_points.at(i).second
                  << std::endl;

        astar.GetPath(&environment, ew, goal, &h, path, false);

        states_to_path(path, operators);


        for(auto op: operators) {
            std::cout << op << " ";
        }
        std::cout << std::endl;
        std::cout << "Nodes Expanded: " << astar.get_nodes_expanded() << std::endl;
        std::cout << "g-cost of goal: " << astar.get_final_gcost() << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;
    }
	return 0;
}

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators) {
    operators.clear();
    EightWayMovement previous_state = states.at(states.size()-1);
    for(int i = states.size()-2; i > -1; i--) {
        EightWayMovement current_state = states.at(i);

        if(current_state.posy > previous_state.posy &&
                current_state.posx > previous_state.posx) {
            operators.push_back(down_right);
        } else if(previous_state.posy > current_state.posy &&
                previous_state.posx > current_state.posx) {
            operators.push_back(up_left);
        } else if (current_state.posy > previous_state.posy &&
                previous_state.posx > current_state.posx) {
            operators.push_back(down_left);
        } else if(previous_state.posy > current_state.posy &&
                current_state.posx > previous_state.posx){
            operators.push_back(up_right);
        } else if(current_state.posy > previous_state.posy) {
            operators.push_back(down);
        } else if(previous_state.posy > current_state.posy) {
            operators.push_back(up);
        } else if (current_state.posx > previous_state.posx) {
            operators.push_back(right);
        } else if(previous_state.posx > current_state.posx) {
            operators.push_back(left);
        }

        previous_state = current_state;
    }
}