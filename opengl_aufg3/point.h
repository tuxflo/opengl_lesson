#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(float x=0, float y=0, float z=0);
    void setPos(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float getX() const;
    float getY() const;
    float getZ() const;

private:
    float _x;
    float _y;
    float _z;
};

#endif // POINT_H
