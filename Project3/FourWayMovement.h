//
// Created by nobel on 5/6/18.
//

#ifndef PROJECT3_FOURWAYMOVEMENT_H
#define PROJECT3_FOURWAYMOVEMENT_H


#include "STP.h"

class FourWayMovement {
public:
    FourWayMovement(std::string file_name);
    ~FourWayMovement();
    FourWayMovement& operator=(const FourWayMovement& fw);
    int** map;
    int posX, posY;
    int map_width, map_height;
    int gcost, hcost, fcost;
    STPSlideDir direction;
    FourWayMovement* parent_state;
};

std::ostream& operator<<(std::ostream&out, const FourWayMovement& fw);

class FWM {
public:
    void GetSuccessors(FourWayMovement& fw, std::vector<FourWayMovement>& states);
    void GetOperators(FourWayMovement& fw, std::vector<STPSlideDir>& operators);
    void ApplyOperator(FourWayMovement& fw, STPSlideDir o);
};


#endif //PROJECT3_FOURWAYMOVEMENT_H