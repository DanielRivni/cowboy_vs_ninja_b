#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

namespace ariel
{
    class Point
    {
    private:
        double xPoint;
        double yPoint;

    public:
        Point();

        Point(double xPoint, double yPoint);
        double distance(const Point &other) const;
        void print() const;
        static Point moveTowards(const Point &src, const Point &dest, double dist);
        double getXPoint() const;
        double getYPoint() const;
        void setXPoint(double xPoint);
        void setYPoint(double yPoint);

        // for the test
        bool operator==(const Point &other) const;
    };

}

#endif