#include "line.h"
#include "point.h"
#include <iostream>
Line::Line(Point start, Point end) :
    _start(start),
    _end(end)
{
    std::cout <<std::endl << _start.getX() << std::endl;
}

Point Line::getStart()
{
    return _start;
}

Point Line::getEnd()
{
    return _end;
}
