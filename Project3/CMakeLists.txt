cmake_minimum_required(VERSION 3.10)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Project3
        All_Heruistics.cpp
        All_Heruistics.h
        AStar.cpp
        AStar.h
        AStarMap.cpp
        AStarMap.h
        BFS.cpp
        BFS.h
        DFID.cpp
        DFID.h
        EfficientDataStructure.cpp
        EfficientDataStructure.h
        FourWayMovement.cpp
        FourWayMovement.h
        HashmapList.cpp
        HashmapList.h
        HashmapListMap.cpp
        HashmapListMap.h
        Heuristic.h
        IDA.cpp
        IDA.h
        InefficientAStar.cpp
        InefficientAStar.h
        main.cpp
        ManhattanDistance.cpp
        ManhattanDistance.h
        MDFourway.cpp
        MDFourway.h
        PDB.cpp
        PDB.h
        STP.cpp
        STP.h
        Timer.cpp
        Timer.h
        VectorList.cpp
        VectorList.h
        VectorListMap.cpp
        VectorListMap.h)
