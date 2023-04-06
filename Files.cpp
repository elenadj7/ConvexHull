//
// Created by elena on 3/10/2023.
//
#include <string>
#include <vector>
#include <fstream>
#include "Point.h"

namespace ConvexHull{

    std::vector<Point> readData(const std::string& inputFile){

        std::vector<Point> points;
        std::ifstream file(inputFile);
        std::string line;

        if(!file.is_open()){
            throw std::exception();
        }

        while(std::getline(file, line)){

            std::size_t pos = line.find(',');
            if(pos == std::string::npos){

                throw std::exception();

            }

            points.emplace_back(std::stof(line.substr(0, pos)), std::stof(line.substr(pos+1)));
        }

        file.close();
        return points;
    }

    void writeData(std::vector<Point> points, const std::string& outputFile){

        std::ofstream file(outputFile);

        if(!file.is_open()){

            throw std::exception();

        }

        while (!points.empty()){

            Point point = points.back();
            file << point.getX() << "," << point.getY() << "\n";
            points.pop_back();

        }

        file.close();
    }
}
