#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

extern int V;

int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[]);
void dijkstra(int graph[][V], int src);

#endif