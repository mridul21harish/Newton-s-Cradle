//g++ test.cpp -o test -lGL -lGLU -lglut -lGLEW
//./test

#include <GL/glew.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <cmath>
#include <unistd.h>
using namespace std;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1200.0, 0.0, 750.0);
	glMatrixMode(GL_MODELVIEW);
}

void pixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void BLA(float point_initial[2], float point_final[2])
{

	float x1 = point_initial[0]; float y1 = point_initial[1];
	float x2 = point_final[0]; float y2 = point_final[1];
	
	int distance_x = (int)(x2 - x1);
	int distance_y = (int)(y2 - y1);
    	int parameter;

    	if(abs(distance_y) <= abs(distance_x))
    	{
        	parameter = 2*abs(distance_y) - abs(distance_x);
        	for(int i = 0; i < abs(distance_x); i = i+1)
        	{
            		if(parameter >= 0)
            		{
                		parameter = parameter + (2*abs(distance_y) - 2*abs(distance_x));
                		y1 = y1 + distance_y/abs(distance_y);
                	}
            		else
            		{
                		parameter = parameter + (2*abs(distance_y));
            		}
            		pixel(round(x1), round(y1));
            
            		x1 = x1 + distance_x/(abs(distance_x));
        	}
    	}
    	else
    	{
        	parameter = 2*abs(distance_x) - abs(distance_y);
        	for(int i = 0; i < abs(distance_y); i = i+1)
        	{
            		if(parameter >= 0)
            		{
            			parameter = parameter + (2*abs(distance_x) - 2*abs(distance_y));
               			x1 = x1 + distance_x/abs(distance_x);
			}
            		else
            		{
            			parameter = parameter + (2*abs(distance_x));
            		}
            		pixel(round(x1), round(y1));
            		
            		y1 = y1 + distance_y/(abs(distance_y));
        	}
    	}	
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(4.0);
	
	glLoadIdentity();
   	 //car body
    	float a[2] = {125, 250};
    	float b[2] = {350, 250};
    	float c[2] = {350, 400};
    	float d[2] = {125, 400};
    	
    	glColor3f(0, 0, 0);
    	BLA(a, b);
    	BLA(b, c);
    	BLA(c, d);
    	BLA(d, a);
    	
    	glRotatef(30, 1, 0, 0);
	
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	srand(time(0));
    	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  	glutInitWindowSize(1200, 750);
   	glutInitWindowPosition(0, 0); 
   	glutCreateWindow("Test");
   	init();
    	glutDisplayFunc(display);
    	glutMainLoop();
    	return 0;
}
