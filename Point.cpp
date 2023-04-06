//
// Created by elena on 3/8/2023.
//
#include "Point.h"

namespace ConvexHull {

    Point Point::operator*(const Point &other) const {
        return {this->x*other.x, this->y*other.y};
    }

    Point::Point(float x, float y) {

        this->x = x;
        this->y = y;

    }

    Point::Point() {

        x = 0.0;
        y = 0.0;

    }

    Point Point::operator+(const Point &other) const {
        return {this->x+other.x, this->y+other.y};
    }

    float Point::getX() const {
        return x;
    }

    float Point::getY() const {
        return y;
    }

    Point Point::operator-(const Point &other) const {
        return {this->x-other.x, this->y-other.y};
    }

    float pseudoScalarProduct(const Point &a, const Point &b) {
        return a.getX() * b.getY() - a.getY() * b.getX();
    }

    bool clockwise(const Point &a, const Point &b, const Point &c) {
        return pseudoScalarProduct(a - b, c - b) < 0;
    }

    bool counterclockwise(const Point &a, const Point &b, const Point &c) {
        return pseudoScalarProduct(a - b, c - b) > 0;
    }

    bool collinear(const Point &a, const Point &b, const Point &c) {
        return pseudoScalarProduct(a - b, c - b) == 0;
    }

    bool compare(const Point &a, const Point &b){

        if(a.getX() == b.getX())
            return a.getY() < b.getY();

        return a.getX() < b.getX();
    }
}
