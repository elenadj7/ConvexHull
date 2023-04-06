#include <iostream>
#include <algorithm>
#include "ConvexHull.h"
#include "ConvexHullCache.h"
#include "ConvexHullOpenMP.h"
#include "Files.h"
int main(int argc, char** argv) {

    //input - output
    if(argc != 3){

        std::cout << "Invalid arguments!";

    }
    else{

        ConvexHull::writeData(ConvexHull::convexHull(ConvexHull::readData(argv[1])), argv[2]);

    }

    return 0;
}
