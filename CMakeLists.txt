cmake_minimum_required(VERSION 3.24)
project(ConvexHull)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(ConvexHull main.cpp Point.h Point.cpp ConvexHull.cpp ConvexHull.h Files.cpp Files.h ConvexHullCache.cpp ConvexHullCache.h ConvexHullOpenMP.cpp cmake-build-debug/ConvexHullOpenMP.h ConvexHullOpenMP.h ConvexHullOpenMP.h ConvexHullOpenMP.h)
