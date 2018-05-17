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

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators);

int main(int argc, const char * argv[]) {
    // So I know one of the requirements is to have astar run after finding the goal, but
    // I didn't include that to save on runtime for the tests. Simply removing the break statement
    // from astar.h will expand all nodes in the state space

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
    EightWayHeuristic h;

    // only did 20 tests, but you could do them all by looping to
    // start_points.size()
    for(int i = 0; i < 1; i++) {
        ew.posx = start_points.at(i).first;
        ew.posy = start_points.at(i).second;

        goal.posx = end_points.at(i).first;
        goal.posy = end_points.at(i).second;

        astar.GetPath(&environment, ew, goal, &h, path);

        states_to_path(path, operators);

        std::cout << "Solution from " << start_points.at(i).first << ", " << start_points.at(i).second
                                                                          << " to " << end_points.at(i).first
                                                                                    << ", "
                                                                                    << end_points.at(i).second
                                                                                    << std::endl;
        for(auto op: operators) {
            std::cout << op << " ";
        }
        std::cout << std::endl;

        // this will print all the gcosts of all nodes expanded
        // there is a method that I wrote to take in a particular state
        // and return it's gcost if it has been expanded
        std::vector<std::pair<EightWayMovement, double>> vec = astar.get_state_gcost();
        std::cout << "gcosts of all nodes expanded" << std::endl;
        for(auto i: vec) {
            std::cout << i.second << ", ";
        }
        std::cout << std::endl;

        // this is just a demo to show how the api works. It will return a gcost
        // when given a state if the state has been expanded
        std::cout << "finding the gcost of one state " << std::endl;
        std::cout << astar.get_state_gcost(ew) << std::endl;
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