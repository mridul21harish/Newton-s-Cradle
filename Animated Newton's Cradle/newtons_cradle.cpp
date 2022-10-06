//g++ newtons_cradle.cpp -o nc -lGL -lGLU -lglut -lGLEW
//./nc

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
	gluOrtho2D(0.0, 1550.0, 0.0, 950.0);
	glMatrixMode(GL_MODELVIEW);
}

void pixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

struct circle
{
    	float centre[2];
    	float radius;
};

void octants(float c[2], float x, float y)
{
    	pixel(c[0] + y, c[1] + x); //O1
    	pixel(c[0] + x, c[1] + y); //O2
    	pixel(c[0] - x, c[1] + y); //O3
    	pixel(c[0] - y, c[1] + x); //O4
    	pixel(c[0] - y, c[1] - x); //O5
    	pixel(c[0] - x, c[1] - y); //O6
    	pixel(c[0] + x, c[1] - y); //O7
    	pixel(c[0] + y, c[1] - x); //O8
}

void MCD(circle cir)
{
    	float x = 0;
    	float y = cir.radius;

    	float p = 1 - cir.radius;

    	int x_limit = cir.radius / sqrt(2);

    	for (int i = 0; i < x_limit; i++)
    	{
		octants(cir.centre, x, y);
        
        	if (p < 0) //y does not change
            	{
            		p = p + 2*(x + 3);
            	}
        	else //y decrement
        	{
            		p = p + 2*x - 2*y + 5;
            		y = y-1;
        	}
        	x = x+1;
	}
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

float xcentre_ball1 = 550;
float ycentre_ball1 = 400;
float xcentre_ball2 = 650;
float ycentre_ball2 = 400;
float xcentre_ball3 = 750;
float ycentre_ball3 = 400;
float xcentre_ball4 = 850;
float ycentre_ball4 = 400;
float xcentre_ball5 = 950;
float ycentre_ball5 = 400;
float thread_end_y1 = 400;
float thread_end_y2 = 400;
float thread_end_y3 = 400;
float thread_end_y4 = 400;
float thread_end_y5 = 400;
int state = 1;
int number = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(4.0);
	
	glLoadIdentity();
	
	circle ball1 = {{xcentre_ball1, ycentre_ball1}, 50};
    	circle ball2 = {{xcentre_ball2, ycentre_ball2}, 50};
    	circle ball3 = {{xcentre_ball3, ycentre_ball3}, 50};
    	circle ball4 = {{xcentre_ball4, ycentre_ball4}, 50};
    	circle ball5 = {{xcentre_ball5, ycentre_ball5}, 50};
    	MCD(ball1);
    	MCD(ball2);
    	MCD(ball3);
    	MCD(ball4);
    	MCD(ball5);
    	
    	glColor3f(0.0, 0.0, 0.0);
    	float temp = ball1.radius;
    	while (temp = temp - 1)
    	{
        	circle b1 = {{ball1.centre[0], ball1.centre[1]}, temp};
        	circle b2 = {{ball2.centre[0], ball2.centre[1]}, temp};
        	circle b3 = {{ball3.centre[0], ball3.centre[1]}, temp};
        	circle b4 = {{ball4.centre[0], ball4.centre[1]}, temp};
        	circle b5 = {{ball5.centre[0], ball5.centre[1]}, temp};
        	
        	glColor3f(0.0, 0.0, 0.0);
        	MCD(b1);
        	MCD(b2);
        	MCD(b3);
        	MCD(b4);
        	MCD(b5);
    	}
    	
    	glPointSize(1.0);
    	float a[2] = {xcentre_ball1, thread_end_y1 + 50};
    	float b[2] = {550, 700};
    	float c[2] = {xcentre_ball2, thread_end_y2 + 50};
    	float d[2] = {650, 700};
    	float e[2] = {xcentre_ball3, thread_end_y3};
    	float f[2] = {750, 700};
    	float g[2] = {xcentre_ball4, thread_end_y4 + 50};
    	float h[2] = {850, 700};
    	float i[2] = {xcentre_ball5, thread_end_y5 + 50};
    	float j[2] = {950, 700};
    	
    	glColor3f(0.0, 0.0, 1.0);
    	BLA(a, b);
    	BLA(c, d);
    	BLA(e, f);
    	BLA(g, h);
    	BLA(i, j);
    	
    	glPointSize(6.0);
    	float k[2] = {450, 700};
    	float l[2] = {1050, 700};
    	
    	glColor3f(0.0, 0.0, 0.0);
    	BLA(k, l);
    	
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	if(number == 1)
	{
		if(state == 1)
		{	
			if(xcentre_ball5 <= 1208)
				xcentre_ball5 = xcentre_ball5 + 2;
			if(ycentre_ball5 <= 547)
			{
				ycentre_ball5 = ycentre_ball5 + 1.14;
				thread_end_y5 = thread_end_y5 + 0.8;
			}
			else
				state = 2;
		}
		else if(state == 2)
		{
			if(xcentre_ball5 > 950)
				xcentre_ball5 = xcentre_ball5 - 2;
			if(ycentre_ball5 > 400)
			{
				ycentre_ball5 = ycentre_ball5 - 1.14;
				thread_end_y5 = thread_end_y5 - 0.8;
			}
			else
				state = 3;
		}
		else if(state == 3)	
		{
			if(xcentre_ball1 >= 292)
				xcentre_ball1 = xcentre_ball1 - 2;
			if(ycentre_ball1 <= 547)
			{
				ycentre_ball1 = ycentre_ball1 + 1.14;
				thread_end_y1 = thread_end_y1 + 0.8;
			}
			else
				state = 4;
		}	
		else if(state == 4)	
		{
			if(xcentre_ball1 < 550)
				xcentre_ball1 = xcentre_ball1 + 2;
			if(ycentre_ball1 > 400)
			{
				ycentre_ball1 = ycentre_ball1 - 1.14;
				thread_end_y1 = thread_end_y1 - 0.8;
			}
			else
				state = 1 ;
		}
	}
	else if(number == 2)
	{
		if(state == 1)
		{	
			if(xcentre_ball5 <= 1208)
				xcentre_ball5 = xcentre_ball5 + 2;
			if(xcentre_ball4 <= 1108)
				xcentre_ball4 = xcentre_ball4 + 2;
			if(ycentre_ball4 <= 547)
			{
				ycentre_ball4 = ycentre_ball4 + 0.875;
				thread_end_y4 = thread_end_y4 + 0.8;
			}
			if(ycentre_ball5 <= 547)
			{
				ycentre_ball5 = ycentre_ball5 + 1.14;
				thread_end_y5 = thread_end_y5 + 0.8;
			}
			else
				state = 2;
		}
		else if(state == 2)
		{
			if(xcentre_ball5 > 950)
				xcentre_ball5 = xcentre_ball5 - 2;
			if(xcentre_ball4 > 850)
				xcentre_ball4 = xcentre_ball4 - 2;
			if(ycentre_ball4 > 400)
			{
				ycentre_ball4 = ycentre_ball4 - 0.875;
				thread_end_y4 = thread_end_y4 - 0.8;
			}
			if(ycentre_ball5 > 400)
			{
				ycentre_ball5 = ycentre_ball5 - 1.14;
				thread_end_y5 = thread_end_y5 - 0.8;
			}
			else
				state = 3;
		}
		else if(state == 3)	
		{
			if(xcentre_ball1 >= 292)
				xcentre_ball1 = xcentre_ball1 - 2;
			if(xcentre_ball2 >= 392)
				xcentre_ball2 = xcentre_ball2 - 2;
			if(ycentre_ball2 <= 547)
			{
				ycentre_ball2 = ycentre_ball2 + 0.875;
				thread_end_y2 = thread_end_y2 + 0.8;
			}
			if(ycentre_ball1 <= 547)
			{
				ycentre_ball1 = ycentre_ball1 + 1.14;
				thread_end_y1 = thread_end_y1 + 0.8;
			}
			else
				state = 4;
		}	
		else if(state == 4)	
		{
			if(xcentre_ball1 < 550)
				xcentre_ball1 = xcentre_ball1 + 2;
			if(xcentre_ball2 < 650)
				xcentre_ball2 = xcentre_ball2 + 2;
			if(ycentre_ball2 > 400)
			{
			 	ycentre_ball2 = ycentre_ball2 - 0.875;
				thread_end_y2 = thread_end_y2 - 0.8;
			}
			if(ycentre_ball1 > 400)
			{
				ycentre_ball1 = ycentre_ball1 - 1.14;
				thread_end_y1 = thread_end_y1 - 0.8;
			}
			else
				state = 1 ;
		}
	}
	else if(number == 3)
	{
		if(state == 1)
		{	
			if(xcentre_ball5 <= 1208)
				xcentre_ball5 = xcentre_ball5 + 2;
			if(xcentre_ball1 >= 292)
				xcentre_ball1 = xcentre_ball1 - 2;
			if(ycentre_ball1 <= 547)
			{
				ycentre_ball1 = ycentre_ball1 + 1.14;
				thread_end_y1 = thread_end_y1 + 0.8;
			}
			if(ycentre_ball5 <= 547)
			{
				ycentre_ball5 = ycentre_ball5 + 1.14;
				thread_end_y5 = thread_end_y5 + 0.8;
			}
			else
				state = 2;
		}
		else if(state == 2)
		{
			if(xcentre_ball5 > 950)
				xcentre_ball5 = xcentre_ball5 - 2;
			if(xcentre_ball1 < 550)
				xcentre_ball1 = xcentre_ball1 + 2;
			if(ycentre_ball1 > 400)
			{
				ycentre_ball1 = ycentre_ball1 - 1.14;
				thread_end_y1 = thread_end_y1 - 0.8;
			}
			if(ycentre_ball5 > 400)
			{
				ycentre_ball5 = ycentre_ball5 - 1.14;
				thread_end_y5 = thread_end_y5 - 0.8;
			}
			else
				state = 1;
		}
	}
	else if(number == 4)
	{
		if(state == 1)
		{	
			if(xcentre_ball5 <= 1208)
				xcentre_ball5 = xcentre_ball5 + 2;
			if(xcentre_ball4 <= 1108)
				xcentre_ball4 = xcentre_ball4 + 2;
			if(xcentre_ball1 >= 292)
				xcentre_ball1 = xcentre_ball1 - 2;
			if(xcentre_ball2 >= 392)
				xcentre_ball2 = xcentre_ball2 - 2;
			if(ycentre_ball2 <= 547)
			{
				ycentre_ball2 = ycentre_ball2 + 0.875;
				thread_end_y2 = thread_end_y2 + 0.8;
			}
			if(ycentre_ball1 <= 547)
			{
				ycentre_ball1 = ycentre_ball1 + 1.14;
				thread_end_y1 = thread_end_y1 + 0.8;
			}
			if(ycentre_ball4 <= 547)
			{
				ycentre_ball4 = ycentre_ball4 + 0.875;
				thread_end_y4 = thread_end_y4 + 0.8;
			}
			if(ycentre_ball5 <= 547)
			{
				ycentre_ball5 = ycentre_ball5 + 1.14;
				thread_end_y5 = thread_end_y5 + 0.8;
			}
			else
				state = 2;
		}
		else if(state == 2)
		{
			if(xcentre_ball5 > 950)
				xcentre_ball5 = xcentre_ball5 - 2;
			if(xcentre_ball4 > 850)
				xcentre_ball4 = xcentre_ball4 - 2;
			if(xcentre_ball1 < 550)
				xcentre_ball1 = xcentre_ball1 + 2;
			if(xcentre_ball2 < 650)
				xcentre_ball2 = xcentre_ball2 + 2;
			if(ycentre_ball2 > 400)
			{
			 	ycentre_ball2 = ycentre_ball2 - 0.875;
				thread_end_y2 = thread_end_y2 - 0.8;
			}
			if(ycentre_ball1 > 400)
			{
				ycentre_ball1 = ycentre_ball1 - 1.14;
				thread_end_y1 = thread_end_y1 - 0.8;
			}
			if(ycentre_ball4 > 400)
			{
				ycentre_ball4 = ycentre_ball4 - 0.875;
				thread_end_y4 = thread_end_y4 - 0.8;
			}
			if(ycentre_ball5 > 400)
			{
				ycentre_ball5 = ycentre_ball5 - 1.14;
				thread_end_y5 = thread_end_y5 - 0.8;
			}
			else
				state = 1;
		}
	}
	else if(number == 5)
	{
		if(state == 1)
		{	
			if(xcentre_ball5 <= 1208)
				xcentre_ball5 = xcentre_ball5 + 2;
			if(xcentre_ball4 <= 1108)
				xcentre_ball4 = xcentre_ball4 + 2;
			if(xcentre_ball3 <= 1008)
				xcentre_ball3 = xcentre_ball3 + 2;
			if(ycentre_ball3 <= 547)
			{
				ycentre_ball3 = ycentre_ball3 + 0.6;
				thread_end_y3 = thread_end_y3 + 0.8;
			}
			if(ycentre_ball4 <= 547)
			{
				ycentre_ball4 = ycentre_ball4 + 0.875;
				thread_end_y4 = thread_end_y4 + 0.8;
			}
			if(ycentre_ball5 <= 547)
			{
				ycentre_ball5 = ycentre_ball5 + 1.14;
				thread_end_y5 = thread_end_y5 + 0.8;
			}
			else
				state = 2;
		}
		else if(state == 2)
		{
			if(xcentre_ball5 > 950)
				xcentre_ball5 = xcentre_ball5 - 2;
			if(xcentre_ball4 > 850)
				xcentre_ball4 = xcentre_ball4 - 2;
			if(xcentre_ball3 > 750)
				xcentre_ball3 = xcentre_ball3 - 2;
			if(ycentre_ball3 > 400)
			{
				ycentre_ball3 = ycentre_ball3 - 0.6;
				thread_end_y3 = thread_end_y3 - 0.8;
			}
			if(ycentre_ball4 > 400)
			{
				ycentre_ball4 = ycentre_ball4 - 0.875;
				thread_end_y4 = thread_end_y4 - 0.8;
			}
			if(ycentre_ball5 > 400)
			{
				ycentre_ball5 = ycentre_ball5 - 1.14;
				thread_end_y5 = thread_end_y5 - 0.8;
			}
			else
				state = 3;
		}
		else if(state == 3)	
		{
			if(xcentre_ball1 >= 292)
				xcentre_ball1 = xcentre_ball1 - 2;
			if(xcentre_ball2 >= 392)
				xcentre_ball2 = xcentre_ball2 - 2;
			if(xcentre_ball3 >= 492)
				xcentre_ball3 = xcentre_ball3 - 2;
			if(ycentre_ball3 <= 547)
			{
				ycentre_ball3 = ycentre_ball3 + 0.6;
				thread_end_y3 = thread_end_y3 + 0.8;
			}
			if(ycentre_ball2 <= 547)
			{
				ycentre_ball2 = ycentre_ball2 + 0.875;
				thread_end_y2 = thread_end_y2 + 0.8;
			}
			if(ycentre_ball1 <= 547)
			{
				ycentre_ball1 = ycentre_ball1 + 1.14;
				thread_end_y1 = thread_end_y1 + 0.8;
			}
			else
				state = 4;
		}	
		else if(state == 4)	
		{
			if(xcentre_ball1 < 550)
				xcentre_ball1 = xcentre_ball1 + 2;
			if(xcentre_ball2 < 650)
				xcentre_ball2 = xcentre_ball2 + 2;
			if(xcentre_ball3 < 750)
				xcentre_ball3 = xcentre_ball3 + 2;
			if(ycentre_ball3 > 400)
			{
				ycentre_ball3 = ycentre_ball3 - 0.6;
				thread_end_y3 = thread_end_y3 - 0.8;
			}
			if(ycentre_ball2 > 400)
			{
			 	ycentre_ball2 = ycentre_ball2 - 0.875;
				thread_end_y2 = thread_end_y2 - 0.8;
			}
			if(ycentre_ball1 > 400)
			{
				ycentre_ball1 = ycentre_ball1 - 1.14;
				thread_end_y1 = thread_end_y1 - 0.8;
			}
			else
				state = 1 ;
		}
	}
}

int main(int argc, char** argv)
{
	//srand(time(0));
	cout << "Enter the movement mode for the spheres(1, 2, 3, 4, 5) : ";
	cin >> number;
	cout << "The number of spheres in motion are: " << number << endl;
    	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  	glutInitWindowSize(1550, 950);
   	glutInitWindowPosition(225, 0); 
   	glutCreateWindow("Newton's Cradle");
    	glutDisplayFunc(display);
    	glutTimerFunc(0, timer, 0);
    	init();
    	glutMainLoop();
    	return 0;
}
