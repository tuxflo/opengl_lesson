#include "mouse_func.h"
#include "global.h"
using namespace Global;
using namespace std;
void mouse_func(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN)
        {
            if(Global::debug_mode)
                cout << "Left Mousebutton pressed x: " << x << " y: " << y << endl;
            Point p(x, height - y, 0);
            addPoint(p);
            if(points.size() > 1)
                addLine(points.at(points.size() - 2), points.back());
        }
    }
}




