cmake_minimum_required(VERSION 3.10)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Project3
        BFS.cpp
        BFS.h
        DFID.cpp
        DFID.h
        Heuristic.h
        IDA.cpp
        IDA.h
        main.cpp
        ManhattanDistance.cpp
        ManhattanDistance.h
        PDB.cpp
        PDB.h
        STP.cpp
        STP.h
        Timer.cpp
        Timer.h All_Heruistics.cpp All_Heruistics.h VectorList.cpp VectorList.h InefficientAStar.cpp InefficientAStar.h)
