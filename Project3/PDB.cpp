//
// Created by nobel on 4/21/2018.
//

#include <deque>
#include "PDB.h"
long factorial(long n);

PDB::PDB(const long& size, const std::vector<uint8_t>& pattern) {
    this->pdb.resize(size);
    this->pattern.resize(pattern.size());

    for(int i = 0; i < pattern.size(); i++) {
        this->pattern[i] = pattern[i];
    }
}

int PDB::h(const STPState &s) {

}

std::vector<uint8_t> PDB::dual(const STPState &s) {

    std::vector<uint8_t> dual;
    std::vector<uint8_t> flat_state;
    for(int i = 0; i < kMaxHeight; i++) {
        for(int j = 0; j < kMaxWidth; j++) {
            int val = s.tiles[j][i];
            flat_state.push_back(s.tiles[j][i]);
        }
    }

    for(int i = 0; i < this->pattern.size(); i++) {
        for(int j = 0; j < flat_state.size(); j++) {
            if(this->pattern[i] == flat_state[j]) {
                dual.push_back(j);
                break;
            }
        }
    }


    return dual;
}

void PDB::mixed_radix(std::vector<uint8_t>& dual) {
    for(int i = 0; i < dual.size(); i++) {
        for(int j = i; j < dual.size(); j++) {
            if(dual[j] > dual[i]) {
                dual[j]--;
            }
        }
    }
}

int PDB::rank(const STPState& s) {
    std::vector<uint8_t> this_dual = dual(s);
    mixed_radix(this_dual);

    int rank = 0;
    long denominator = factorial(15-this_dual.size());
    for(int i = 0; i < this_dual.size(); i++) {
        rank += (this_dual[i] * factorial(14-i)/denominator);
    }
    return rank;
}

long factorial(long n) {
    if(n == 1) {
        return n;
    } else {
        return n * factorial(n-1);
    }
}

struct BFSNode {
    STPState s;
    STPSlideDir forbidden;
    int depth;
};

void BFS(STP &stp, STPState start, STPState &goal)
{
    std::deque<BFSNode> q;
    std::vector<STPSlideDir> acts;
    q.push_back({start, kNone, 0});

    int currDepth = 0;
    while (q.size() > 0)
    {
        BFSNode n = q.front();
        q.pop_front();

        if (n.depth != currDepth)
        {
            printf("Depth %d complete; \n", currDepth);
            currDepth = n.depth;
        }

        stp.GetOperators(n.s, acts);
        for (auto act : acts)
        {
            if (act == n.forbidden)
                continue;

            stp.ApplyOperator(n.s, act);
            if (n.s == goal)
            {
                printf("Goal found at depth %d;\n", n.depth+1);
                return;
            }
            stp.InvertOperator(act);
            q.push_back({n.s, act, n.depth+1});
            stp.ApplyOperator(n.s, act);
        }
    }
}
