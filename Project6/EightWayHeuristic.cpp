//
// Created by nobel on 5/16/2018.
//

#include <cmath>
#include "EightWayHeuristic.h"

double EightWayHeuristic::h(const EightWayMovement &ew1, const EightWayMovement &ew2) {
    int dx = abs(ew1.posx - ew2.posx);
    int dy = abs(ew1.posy - ew2.posy);
    return 1*(dx+dy) + (std::sqrt(2) - 2 * 1) * std::min(dx, dy);
}