//
// Created by nobel on 5/15/2018.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "EightWayMovement.h"

EightWayMovement::EightWayMovement(/*const std::string &file_name*/) {
    this->file_name = "lak303d.map";
    std::ifstream file;
    file.open(this->file_name);
    this->posx = 0;
    this->posy = 0;

    std::string command;
    int counter = 1;
    if(file.is_open()) {

        for(int i = 0; i < 4; i++) {
            std::getline(file, command);
            std::istringstream stream(command);
            std::string temp;

            if(counter == 2) {
                stream >> temp;
                stream >> temp;
                this->map_height = std::stoi(temp, nullptr, 10);
            } else if(counter == 3) {
                stream >> temp;
                stream >> temp;
                this->map_width = std::stoi(temp, nullptr, 10);
            }

            counter++;
        }

        map = new int*[map_height];
        for(int i = 0; i <map_height; i++) {
            map[i] = new int[map_width];
        }

        int row_counter = 0;
        while(std::getline(file, command)) {
            for(int i = 0; i < command.length(); i++) {
                if(command.at(i) == '.') {
                    map[row_counter][i] = 1;
                } else {
                    map[row_counter][i] = 0;
                }
            }
            row_counter++;
        }
    } else {
        std::cout << "ERROR FILE NOT FOUND" << std::endl;
    }

    file.close();
}

std::ostream& operator<<(std::ostream& out, const EightWayMovement& ew) {
    for(int i = 0; i < ew.map_height; i++) {
        for(int j = 0; j < ew.map_width; j++) {
            out << ew.map[i][j];
        }
        out << "\n";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const EWMoves& move) {
    switch(move) {
        case up:
            out << "Up";
            break;
        case down:
            out << "Down";
            break;
        case right:
            out << "Right";
            break;
        case left:
            out << "Left";
            break;
        case up_right:
            out << "Up-Right";
            break;
        case up_left:
            out << "Up-Left";
            break;
        case down_left:
            out << "Down-Left";
            break;
        case down_right:
            out << "Down-Right";
            break;
    }
}

bool operator==(const EightWayMovement& ew1, const EightWayMovement& ew2) {
    if(ew1.posx == ew2.posx && ew1.posy == ew2.posy) {
        return true;
    }
    return false;
}

// Begin environment class
void EWM::GetOperators(EightWayMovement &ew, std::vector<EWMoves> &operators) {
    operators.clear();

    if(ew.posy != 0) {
        if(ew.map[ew.posy-1][ew.posx] == 1) {
            operators.push_back(up);
        }
    }
    if(ew.posy != ew.map_height-1) {
        if(ew.map[ew.posy + 1][ew.posx] == 1) {
            operators.push_back(down);
        }
    }
    if(ew.posx != 0) {
        if(ew.map[ew.posy][ew.posx-1] == 1) {
            operators.push_back(left);
        }
    }
    if(ew.posx != ew.map_width-1) {
        if(ew.map[ew.posy][ew.posx+1]) {
            operators.push_back(right);
        }
    }

    //new operators
    if(ew.posy != 0 && ew.posx != ew.map_width-1) {
        if(ew.map[ew.posy-1][ew.posx] == 1 && ew.map[ew.posy][ew.posx + 1] == 1
                && ew.map[ew.posy-1][ew.posx+1] == 1) {
            operators.push_back(up_right);
        }
    }
    if(ew.posy != ew.map_height-1 && ew.posx != ew.map_width-1) {
        if(ew.map[ew.posy+1][ew.posx] == 1 && ew.map[ew.posy][ew.posx + 1] == 1
                && ew.map[ew.posy+1][ew.posx+1] == 1) {
            operators.push_back(down_right);
        }
    }
    if(ew.posy != 0 && ew.posx != 0) {
        if(ew.map[ew.posy][ew.posx-1] == 1 && ew.map[ew.posy-1][ew.posx] == 1
                && ew.map[ew.posy-1][ew.posx-1] == 1) {
            operators.push_back(up_left);
        }
    }
    if(ew.posy != ew.map_height-1 && ew.posx != 0) {
        if(ew.map[ew.posy+1][ew.posx] == 1 && ew.map[ew.posy][ew.posx-1] == 1
                && ew.map[ew.posy+1][ew.posx-1]) {
            operators.push_back(down_left);
        }
    }
}

void EWM::ApplyOperator(EightWayMovement &ew, EWMoves o) {

    switch(o) {
        case up:
            ew.posy--;
            break;
        case down:
            ew.posy++;
            break;
        case left:
            ew.posx--;
            break;
        case right:
            ew.posx++;
            break;
        case up_right:
            ew.posx++;
            ew.posy--;
            break;
        case down_right:
            ew.posx++;
            ew.posy++;
            break;
        case up_left:
            ew.posx--;
            ew.posy--;
            break;
        case down_left:
            ew.posx--;
            ew.posy++;
            break;
    }
}
