#include "point.h"

Point::Point(float x, float y, float z)
    : _x(x),
      _y(y),
      _z(z)
{
}


float Point::getX() const
{
    return _x;
}

float Point::getY() const
{
    return _y;
}

float Point::getZ() const
{
    return _z;
}


void Point::setX(float x)
{
    _x = x;
}

void Point::setY(float y)
{
    _y = y;
}

void Point::setZ(float z)
{
    _z = z;
}
