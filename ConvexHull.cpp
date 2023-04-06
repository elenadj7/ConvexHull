//
// Created by elena on 3/8/2023.
//
#include <iostream>
#include <algorithm>
#include <ctime>
#include "ConvexHull.h"

namespace ConvexHull{

    std::vector<Point> convexHull(const std::vector<Point> &vector){

        std::clock_t start = clock(), diff;

        std::vector<Point> points;
        if(points.size() == 1){
            return points;
        }


        for(Point i : vector){
            points.push_back(i);
        }


        std::sort(points.begin(), points.end(), compare);
        std::vector<Point> upperPart, lowerPart;

        Point firstElement = points[0];
        Point lastElement = points.back();

        upperPart.push_back(firstElement);
        lowerPart.push_back(firstElement);


        for(int i = 1; i < points.size(); ++i){

            if(i == points.size() - 1 || counterclockwise(firstElement, points[i], lastElement)){

                while (upperPart.size() >= 2 && !counterclockwise(upperPart[upperPart.size() - 2], upperPart[upperPart.size() - 1], points[i]))
                    upperPart.pop_back();

                upperPart.push_back(points[i]);
            }
            if(i == points.size() - 1 || clockwise(firstElement, points[i], lastElement)){

                while (lowerPart.size() >= 2 && !clockwise(lowerPart[lowerPart.size() - 2], lowerPart[lowerPart.size() - 1], points[i]))
                    lowerPart.pop_back();

                lowerPart.push_back(points[i]);
            }
        }

        points.clear();

        for(Point p : upperPart){
            points.push_back(p);
        }


        for(int i = (int)(lowerPart.size() - 2); i > 0; i--){
            points.push_back(lowerPart[i]);
        }


        diff = clock() - start;
        std::cout << (diff * 1000) / CLOCKS_PER_SEC;
        return points;
    }

}
