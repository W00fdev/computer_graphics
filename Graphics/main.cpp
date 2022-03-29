#include <gl/glut.h>
#include <iostream>

#include "Core/Renderer.h"

using namespace std;
using namespace graphics;

int rx = 100, ry = 125;
int xCenter = 250, yCenter = 250;

void ellipseMidPoint()
{
    float x = 0;
    float y = ry;
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    while (dx < dy)
    {
        Renderer::SetPixel(xCenter + x, yCenter + y);
        Renderer::SetPixel(xCenter - x, yCenter + y);
        Renderer::SetPixel(xCenter + x, yCenter - y);
        Renderer::SetPixel(xCenter - x, yCenter - y);

        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }
    glFlush();

    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y
        - 1) * (y - 1) - (rx * rx) * (ry * ry);
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    while (y > 0)
    {
        Renderer::SetPixel(xCenter + x, yCenter + y);
        Renderer::SetPixel(xCenter - x, yCenter + y);
        Renderer::SetPixel(xCenter + x, yCenter - y);
        Renderer::SetPixel(xCenter - x, yCenter - y);
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx -
                dy + (rx * rx);
        }
    }
    glFlush();
}

//void display(const Renderer& render)
//{
    //render.Display();
    //glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 0.0, 0.0);
    //glPointSize(2.0);
    //ellipseMidPoint();
    //glFlush();
//}

struct point {
    int x, y, z;
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

void printSizeCheck()
{
    point2 p2;
    point3 p3 (1, 0, -1);

    pointWrapper pc2(2);
    pointWrapper pc3(3);

    pc2 = p2;
    pc3 = p3;

    cout << "Point2: " << sizeof(p2) << endl;
    cout << "Point3: " << sizeof(p3) << endl;

    cout << "PointWrapperType: " << sizeof(pointWrapperType) << endl;

    cout << "Empty PointWrapper2: " << sizeof(pointWrapper(2)) << endl;
    cout << "Empty PointWrapper3: " << sizeof(pointWrapper(3)) << endl;

    cout << "PointWrapper2: " << sizeof(pc2) << endl;
    cout << "PointWrapper3: " << sizeof(pc3) << endl;

    //pointWrapper* pArr = new pointWrapper[10]{  };
    pointArray pArr(2, pc3);
    cout << pArr << endl;

    point3 p33(-1, -2, -3);
    pointWrapper pc4(3);
    pc4 = p33;

    pArr.add(pc4);

    cout << endl << pArr << endl;
}

int main(int argc, char** argv)
{
    printSizeCheck();

    //Renderer render;
    //render.Init(argc, argv);
    //render.StartGameLoop();

    return 0;
}