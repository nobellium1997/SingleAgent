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
#include "DifferentialHeuristic.h"
#include "MaxHeuristic.h"

void states_to_path(const std::vector<EightWayMovement>& states, std::vector<EWMoves>& operators);
std::pair<int, int> get_random_point(const EightWayMovement& ew);
void optimized_pivots(const EightWayMovement& ew, std::vector<DifferentialHeuristic>& optimized_pivot_points);

int main(int argc, const char * argv[]) {
    std::srand(std::time(nullptr));

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

    std::vector<DifferentialHeuristic> pivot_points_randomized;
    optimized_pivots(ew, pivot_points_randomized);

//    for(int i = 0; i < 5; i++) {
//        DifferentialHeuristic dh;
//        pivot_points_randomized.push_back(dh);
//    }

    // Comment out the heuristic here to test the difference between
    // octile (EightWayHeuristic) and Differential (MaxHeuristic)
    MaxHeuristic h(pivot_points_randomized);
//    EightWayHeuristic h;

    std::unordered_map<EightWayMovement, double> temp_map;
    for(int i = start_points.size()-1; i < start_points.size(); i++) {
        ew.posx = start_points.at(i).first;
        ew.posy = start_points.at(i).second;

        goal.posx = end_points.at(i).first;
        goal.posy = end_points.at(i).second;

        std::cout << "Solution from " << start_points.at(i).first << ", " << start_points.at(i).second
                  << " to " << end_points.at(i).first
                  << ", "
                  << end_points.at(i).second
                  << std::endl;

        astar.GetPath(&environment, ew, goal, &h, path, false, temp_map);

        states_to_path(path, operators);

        int counter = 1;
        for(auto op: operators) {
            if(counter % 10 == 0) {
                std::cout << std::endl;
            }
            std::cout << op << " ";
            counter++;
        }
        std::cout << std::endl;
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

void optimized_pivots(const EightWayMovement& ew, std::vector<DifferentialHeuristic>& optimized_pivot_points) {
    EightWayHeuristic octile_distance;
    std::vector<std::pair<int, int>> random_points;

    for(int i = 0; i < 20; i++) {
        std::pair<int, int> temp_point = get_random_point(ew);
        random_points.push_back(temp_point);
    }
    double max_q = 0;

    EightWayMovement ew1;
    EightWayMovement ew2;
    for(int i = 0; i < random_points.size(); i++) {
        ew1.posx = random_points.at(i).first;
        ew1.posy = random_points.at(i).second;
        for(int j = 0; j < random_points.size(); j++) {
            ew2.posx = random_points.at(j).first;
            ew2.posy = random_points.at(j).second;
            max_q += octile_distance.h(ew1, ew2);
        }
    }

    // creates 20 new random potential pivots
    // tests to see which creates the biggest difference in max_q
    optimized_pivot_points.clear();
    optimized_pivot_points.resize(5);

    double other_max_q = 0;
    double max_difference = 0;
    for(int w = 0; w < 5; w++) {
        random_points.clear();
        for (int i = 0; i < 20; i++) {
            std::pair<int, int> temp_point = get_random_point(ew);
            random_points.push_back(temp_point);
        }

        max_difference = 0;

        for(int z = 0; z < 20; z++) {
            int x = random_points.at(z).first;
            int y = random_points.at(z).second;

            DifferentialHeuristic dh(x, y);

            other_max_q = 0;

            for (int i = 0; i < 20; i++) {
                ew1.posx = random_points.at(i).first;
                ew1.posy = random_points.at(i).second;
                for (int j = 0; j < 20; j++) {
                    ew2.posx = random_points.at(j).first;
                    ew2.posy = random_points.at(j).second;
                    other_max_q += dh.h(ew1, ew2);
                }
            }
            if(std::abs(other_max_q - max_q) > max_difference) {
                max_difference = std::abs(other_max_q - max_q);
                optimized_pivot_points.at(w) = dh;
            }
        }
        std::cout << other_max_q << std::endl;
        std::cout << max_difference << std::endl;
        std::cout << std::endl;
    }
}