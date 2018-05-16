//
// Created by nobel on 5/15/2018.
//

#ifndef PROJECT6_EIGHTWAYMOVEMENT_H
#define PROJECT6_EIGHTWAYMOVEMENT_H

#include <string>
#include <vector>

enum EWMoves {
    up,
    down,
    left,
    right,
    up_right,
    down_right,
    up_left,
    down_left,
    none
};

class EightWayMovement {
public:
    EightWayMovement(const std::string& file_name);
//    ~EightWayMovement();
//    EightWayMovement& operator=(const EightWayMovement& ew);
    int** map;
    int posx, posy;
    int map_width, map_height;
};

std::ostream& operator<<(std::ostream& out, const EightWayMovement& ew);
std::ostream& operator<<(std::ostream& out, const EWMoves& move);
bool operator==(const EightWayMovement& ew1, const EightWayMovement& ew2);

class EWM {
public:
    void GetOperators(EightWayMovement& ew, std::vector<EWMoves>& operators);
    void ApplyOperator(EightWayMovement& ew, EWMoves o);
};

namespace std {
    template<> struct hash<EightWayMovement> {
        std::size_t operator()(EightWayMovement const& s) const noexcept {
            size_t hash1 = std::hash<int>()(s.posx);
            size_t hash2 = std::hash<int>()(s.posy);
            return hash1 ^ (hash2 << 1);
        }
    };
}

#endif //PROJECT6_EIGHTWAYMOVEMENT_H
