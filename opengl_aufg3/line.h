#ifndef LINE_H
#define LINE_H
//#include "global.h"
#include "point.h"

class Line
{
public:
    Line(Point start, Point end);
    Point getStart();
    Point getEnd();

private:
    Point _start;
    Point _end;
};

#endif // LINE_H
