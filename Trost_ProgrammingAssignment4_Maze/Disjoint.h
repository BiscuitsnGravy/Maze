#ifndef DISJOINT_H
#define DISJOINT_H
#include "Maze.h"
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
class DisjSets
{
public:
	explicit DisjSets ( int numElements ) : S(numElements), visits(numElements)
	{
		for ( int i = 0; i < S.size(); i++){
			S[i] = -1;
			visits[i] = 0; // 1 = visited
		}
	}

	int find ( int x ) const{
		if ( S[x] < 0 )
			return x;
		else 
			return find ( S [x] );
	}

	void unionSets ( int root1, int root2 ){
		if ( S [root2] < S [root1] )
			S[root1] = root2;
		else {
			if ( S [root1] == S [root2] )
				S[root1]--;
			S[root2] = root1;
		}
	}

	void fileSet (Maze maze, int n, int N){
		for (int i = 0; i < N; i++){
			if (-1 < i-n && i-n < N && maze.getWall (i, 'n') == 0)
				if (find(i)!= find(i-n))
					unionSets(find(i), find(i-n));
			if (-1 < i+n && i+n < N &&maze.getWall (i, 's') == 0)
				if (find(i) != find (i+n))
					unionSets(find(i), find(i+n));
			if (-1 < i+1 && i+1 < N &&maze.getWall (i, 'e') == 0)
				if (find (i) != find (i+1))
					unionSets(find(i), find(i+1));
			if (-1 < i-1 && i-1 < N && maze.getWall (i, 'w') == 0)
				if (find(i) != find(i-1))
					unionSets(find(i), find(i-1));
		}
	}

	void markVisited ( int x ){
		visits[x] = 1;
	}

	bool isVisited ( int x ){
		if (visits[x] == 1)
			return true;
		return false;
	}

	void upPath ( int x){
		path.push_back (x);
	}

	bool checkAdjacency (int i, int j, int n){
		if (i%n != 0 && j == (i-1)) 
			return true;
		if (j%n != 0 && j == (i+1))
			return true;
		if (i>n && j == (i-n))
			return true;
		if (i < ((n*n) -n) && j == (i+n))
			return true;
		return false;
	}

	void createPath (Maze maze, int n ){
		int i = 0, j = 0;

		i = path.size()-1;

		while ( i != 0){
			if (!checkAdjacency (path[i-1], path[i], n))
				path.erase (path.begin() + (i-1));	
			if (maze.getWall(path[i], getDir(path[i], path[i-1], n)) == 1)
				path.erase (path.begin() + (i-1));
			i--;
		}
		printPath();
	}

	char getDir (int i, int j, int n){
		if (j == (i-1))
			return 'w';
		if (j == (i+1))
			return 'e';
		if (j == (i-n))
			return 'n';
		if (j == (i+n))
			return 's';
	}

	void printPath (void){
		cout << '\n' << '\n' << "Path in reverse: ";
		for (int i = path.size()-1; i > -1; i--)
			cout << path[i] << ", ";
		cout << "End." << '\n' << '\n';
	}

	bool checkPath ( int x ){
		for (int i = 0; i < path.size(); i++){
			if (x == path[i])
				return true;
		}
		return false;
	}

	void printMazePath ( Maze maze, int n, int N ){
		cout << "Maze Generated with Path: " << '\n';

		for (int i = 0; i < N; i++){
			if (i % (n) == 0)
				cout << '\n'; // 1, 2, 3
			
			if (checkPath (i))
				cout << "X";
			else cout << "|";
			}
			
		cout << '\n' << '\n';
	}

	private:
		vector<int> S;
		vector<int> path;
		vector<int> visits;
};
#endif