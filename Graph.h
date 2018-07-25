#pragma once

typedef struct{
	double x, y;
	double ax, ay;
}vertex;

class Graph
{
public:
	Graph();
public:

	void setEdge(double, double, double, double);
	double getX();
	double getY();
	double getAx();
	double getAy();

private:
	vertex edge;
};