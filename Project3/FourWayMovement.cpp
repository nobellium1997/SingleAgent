//
// Created by nobel on 5/6/18.
//

#include <fstream>
#include <sstream>
#include "FourWayMovement.h"

FourWayMovement::FourWayMovement(const int& height, const int& width) {
    map_height = height;
    map_width = width;
    map = new int*[map_height];
    for(int i = 0; i < map_height; i++) {
        map[i] = new int[map_width];
    }
}

FourWayMovement::FourWayMovement(std::string file_name) {
    std::ifstream file;
    file.open(file_name);

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
            } else if (counter == 3) {
                stream >> temp;
                stream >> temp;
                this->map_width = std::stoi(temp, nullptr, 10);
            }

            counter++;
        }

        map = new int*[map_height];
        for(int i = 0; i < map_height; i++) {
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
//                std::cout << map[row_counter][i];
            }
//            std::cout << std::endl;
            row_counter++;
        }
    } else {
        std::cout << "ERROR FILE NOT FOUND" << std::endl;
    }

    file.close();
}

//FourWayMovement::~FourWayMovement() {
//    for(int i = 0; i < this->map_width; i++) {
//        delete[] map[i];
//    }
//    delete[] map;
//}

FourWayMovement& FourWayMovement::operator=(const FourWayMovement& fw) {
    for(int i = 0; i < this->map_width; i++) {
        for(int j = 0; j < this->map_height; j++) {
            this->map[i][j] = fw.map[i][j];
        }
    }

//    this->fcost = fw.fcost;
//    this->gcost = fw.gcost;
//    this->hcost = fw.hcost;

    this->posX = fw.posX;
    this->posY = fw.posY;

    this->goalX = fw.goalX;
    this->goalY = fw.goalY;

//    this->direction= fw.direction;
//    this->parent_state = fw.parent_state;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const FourWayMovement& fw) {
    for(int i = 0; i < fw.map_height; i++) {
        for(int j = 0; j < fw.map_width; j++) {
            out << fw.map[i][j];
        }
        out << "\n";
    }
    return out;
}

bool operator==(const FourWayMovement& fw1, const FourWayMovement& fw2) {
//    for(int i = 0; i < fw1.map_height; i++) {
//        for(int j = 0; j < fw1.map_width; j++) {
//            if(fw1.map[i][j] != fw2.map[i][j]) {
//                return false;
//            }
//        }
//    }

    if(fw1.posX == fw2.posX && fw1.posY == fw2.posY) {
        return true;
    }
    return false;
}

void FWM::GetOperators(FourWayMovement &fw, std::vector<STPSlideDir> &operators) {
    operators.clear();
    if(fw.posY != 0) {
        if(fw.map[fw.posY-1][fw.posX] == 1) {
            operators.push_back(kUp);
        }
    }
    if (fw.posY != fw.map_height-1) {
        if(fw.map[fw.posY + 1][fw.posX] == 1) {
            operators.push_back(kDown);
        }
    }
    if(fw.posX != 0) {
        if(fw.map[fw.posY][fw.posX-1]) {
            operators.push_back(kLeft);
        }
    }
    if(fw.posX != fw.map_width-1) {
        if(fw.map[fw.posY][fw.posX+1]) {
            operators.push_back(kRight);
        }
    }
}

// TODO this doesn't work for some reason
void FWM::GetSuccessors(FourWayMovement &fw, std::vector<FourWayMovement> &states) {
    states.clear();
    std::vector<STPSlideDir> operators;
    GetOperators(fw, operators);

    for(auto operation: operators) {
        states.push_back(fw);
        ApplyOperator(states.back(), operation);
    }
}

void FWM::ApplyOperator(FourWayMovement &fw, STPSlideDir o) {
    int temp = fw.map[fw.posY][fw.posX];
    switch (o) {
        case kUp:
            fw.map[fw.posY][fw.posX] = fw.map[fw.posY-1][fw.posX];
            fw.map[fw.posY-1][fw.posX] = temp;
            fw.posY--;
            break;
        case kDown:
            fw.map[fw.posY][fw.posX] = fw.map[fw.posY+1][fw.posX];
            fw.map[fw.posY+1][fw.posX] = temp;
            fw.posY++;
            break;
        case kLeft:
            fw.map[fw.posY][fw.posX] = fw.map[fw.posY][fw.posX-1];
            fw.map[fw.posY][fw.posX-1] = temp;
            fw.posX--;
            break;
        case kRight:
            fw.map[fw.posY][fw.posX] = fw.map[fw.posY][fw.posX+1];
            fw.map[fw.posY][fw.posX+1] = temp;
            fw.posX++;
            break;
        case kNone:
            break;
    }
}