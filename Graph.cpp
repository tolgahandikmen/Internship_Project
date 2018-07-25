#include "Graph.h"

Graph::Graph(){
	edge.x;
	edge.y;
	edge.ax;
	edge.ay;
}

void Graph::setEdge(double X, double Y, double AX, double AY){
	edge.x = X;
	edge.y = Y;
	edge.ax = AX;
	edge.ay = AY;
}

double Graph::getX(){
	return edge.x;
}

double Graph::getY(){
	return edge.y;
}

double Graph::getAx(){
	return edge.ax;
}

double Graph::getAy(){
	return edge.ay;
}