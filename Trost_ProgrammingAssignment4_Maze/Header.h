#ifndef HEADER_H
#define HEADER_H

/*
	Jason Trost
	Computer Science 223
	May 20, 2013
	Programming Assignment 4 -- Maze
*/

#include "Disjoint.h"
#include "Queue.h"
#include "Stack.h"
#include "Maze.h"

#include <vector>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

void BFS (Maze maze, DisjSets U, int N, int n);
void DFS (Maze maze, DisjSets U, int N, int n);

#endif