cmake_minimum_required(VERSION 3.10)
project(Project6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project6 main.cpp AStar.h AStarOpenList.h BFS.cpp BFS.h DFID.cpp DFID.h Heuristic.h
        STP.cpp STP.h
        Timer.cpp Timer.h EightWayMovement.cpp EightWayMovement.h EightWayHeuristic.cpp EightWayHeuristic.h DifferentialHeuristic.cpp DifferentialHeuristic.h DifferentialHelper.cpp DifferentialHelper.h)