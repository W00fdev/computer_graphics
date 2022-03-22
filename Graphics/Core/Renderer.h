#pragma once

#include <gl/glut.h>
#include "../Math/Point/point_varieties.h"

namespace graphics {
	class Renderer
	{
	public:
		static void Init(int argc, char** argv) {
			glutInit(&argc, argv);
			glutInitWindowSize(640, 480);
			glutInitWindowPosition(10, 10);
			glutCreateWindow("Graphics Window");
		
			glClearColor(1.0, 1.0, 1.0, 0.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(0.0, 640.0, 0.0, 480.0);
		}

		static void Display() {
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(1.0, 0.0, 0.0);
			glPointSize(2.0);
			//ellipseMidPoint();
			glFlush();
		}

		static void SetPixel(point2 point) {
			glBegin(GL_POINTS);
			glVertex2i(point.x(), point.y());
			glEnd();
		}

		static void SetPixel(int _x, int _y) {
			glBegin(GL_POINTS);
			glVertex2i(_x, _y);
			glEnd();
		}

		static void StartGameLoop() {
			glutDisplayFunc(Display);
			glutMainLoop();
		}
	};
}