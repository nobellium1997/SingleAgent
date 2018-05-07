//
// Created by nobel on 5/7/2018.
//

#include "MDFourway.h"

int MDFourway::h(const FourWayMovement &start) {
    return abs(start.goalX - start.posX) + abs(start.goalY - start.posY);
}