//
// Created by elena on 3/10/2023.
//

#ifndef CONVEXHULL_FILES_H
#define CONVEXHULL_FILES_H

#include <string>
#include <vector>

namespace ConvexHull{

    std::vector<Point> readData(const std::string& inputFile);
    void writeData(std::vector<Point> points, const std::string& outputFile);
}

#endif
