//
// Created by nobel on 5/6/18.
//

#ifndef PROJECT3_FOURWAYMOVEMENT_H
#define PROJECT3_FOURWAYMOVEMENT_H


#include "STP.h"

class FourWayMovement {
public:
    FourWayMovement(const int& height, const int& width);
    FourWayMovement(std::string file_name);
//    ~FourWayMovement();
    FourWayMovement& operator=(const FourWayMovement& fw);
    int** map;
    int posX, posY;
    int goalX, goalY;
    int map_width, map_height;
//    int gcost, hcost, fcost;
//    STPSlideDir direction;
//    FourWayMovement* parent_state;
};

std::ostream& operator<<(std::ostream&out, const FourWayMovement& fw);
bool operator==(const FourWayMovement& fw1, const FourWayMovement& fw2);

class FWM {
public:
    void GetSuccessors(FourWayMovement& fw, std::vector<FourWayMovement>& states);
    void GetOperators(FourWayMovement& fw, std::vector<STPSlideDir>& operators);
    void ApplyOperator(FourWayMovement& fw, STPSlideDir o);
};

struct fourway_struct {
    int gcost, hcost, fcost;
    FourWayMovement state;
    fourway_struct* parent;
    STPSlideDir direction;
};


#endif //PROJECT3_FOURWAYMOVEMENT_H
