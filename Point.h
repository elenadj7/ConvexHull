//
// Created by elena on 3/8/2023.
//

#ifndef CONVEXHULL_POINT_H
#define CONVEXHULL_POINT_H

namespace ConvexHull {

    class Point {

    private:
        float x,y;
    public:
        Point();
        Point(float x, float y);
        Point operator*(const Point &other)const;
        Point operator+(const Point &other)const;
        Point operator-(const Point &other)const;
        [[nodiscard]] float getX()const;
        [[nodiscard]] float getY()const;
    };

    float pseudoScalarProduct(const Point &a, const Point &b);
    bool clockwise(const Point &a, const Point &b, const Point &c);
    bool counterclockwise(const Point &a, const Point &b, const Point &c);
    bool collinear(const Point &a, const Point &b, const Point &c);
    bool compare(const Point &a, const Point &b);
}
#endif
