#include "Point.hpp"
using namespace std;
namespace ariel
{
    Point::Point() : xPoint(0), yPoint(0) {}

    Point::Point(double xPoint, double yPoint) : xPoint(xPoint), yPoint(yPoint) {}
    double Point::distance(const Point &other) const
    {
        double distX = xPoint - other.xPoint;
        double distY = yPoint - other.yPoint;
        return sqrt(pow(distX, 2) + pow(distY, 2));
    }

    void Point::print() const
    {
        cout << "(" << xPoint << "," << yPoint << ")";
    }

    // uses Euclidean formula
    Point Point::moveTowards(const Point &src, const Point &dest, double dist)
    {
        if (dist < 0)
        {
            throw invalid_argument("error: negative distance");
        }
        double distance = src.distance(dest);
        // if (distance <= dist)
        // {
        //     return dest;
        // }
        if (distance < dist)
        {
            throw invalid_argument("error: Can't move beyond the destination");
        }
        double rate = dist / distance;
        double newXPoint = src.xPoint + rate * (dest.xPoint - src.xPoint);
        double newYPoint = src.yPoint + rate * (dest.yPoint - src.yPoint);
        return Point(newXPoint, newYPoint);
    }
    double Point::getXPoint() const
    {
        return xPoint;
    }

    double Point::getYPoint() const
    {
        return yPoint;
    }

    void Point::setXPoint(double xPoint)
    {
        this->xPoint = xPoint;
    }

    void Point::setYPoint(double yPoint)
    {
        this->yPoint = yPoint;
    }
    bool Point::operator==(const Point &other) const
    {
        return abs(xPoint - other.xPoint) == 0 && abs(yPoint - other.yPoint) == 0;
    }
}