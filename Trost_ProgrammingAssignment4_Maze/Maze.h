#ifndef MAZE_H
#define MAZE_H
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Maze
{
public:
	explicit Maze ( int numElements ) : S(numElements)
	{
		for ( int i = 0; i < numElements; i++){
			S[i].n = 1;
			S[i].w = 1;
			S[i].e = 1;
			S[i].s = 1;
		}
	}

	void breakWall ( int i, int j, char temp ){
		if ( temp == 'w'){
			S[j].e = 0;
			S[i].w = 0;
		}
			
		if ( temp == 'e' ){
			S[j].w = 0;
			S[i].e = 0;
		}
			
		if ( temp == 'n' ){
			S[j].s = 0;
			S[i].n = 0;
		}
		
		if ( temp == 's' ){
			S[j].n = 0;
			S[i].s = 0;
		}
	}

	void printWalls (void){ // prints out the four walls of each cell
		for (int i = 0; i < S.size(); i++){
			cout << S[i].n << ' ' << S[i].s << ' ' << S[i].e << ' ' << S[i].w << '\n';
		}
		cout << '\n';
	}

	void printMaze  ( int n, int N ){ // prints out generated maze
		cout << "Maze Generated: " << '\n';
		for (int i = 0; i < n; i++){ // top
			if (i == 0)
				cout << "   ";
			else 
				cout << "__";
		}
		for (int i = 0; i < N-1; i++){
			if (i % (n) == 0){
				cout << '\n' <<  '|'; // 1, 2, 3
			}

			if (getWall (i, 's') )
				cout << "_";
			else 
				cout << " ";
			if (getWall (i, 'e'))
				cout << "|";
			else
				cout << " ";			
		}	
		cout << '\n' << '\n';
	}

	bool getWall ( int i, char c){
		if (c == 'n')
			return S[i].n;
		if (c == 'e')
			return S[i].e;
		if (c == 's')
			return S[i].s;
		if (c == 'w')
			return S[i].w;
	}

	void setWall ( int i, string read_in){
		if (read_in[0] == '0')
			S[i].n = 0;
		if (read_in[1] == '0')
			S[i].s = 0;
		if (read_in[2] == '0')
			S[i].e = 0;
		if (read_in[3] == '0')
			S[i].w = 0;
	}


private:
	typedef struct cell{
		bool n;
		bool s;
		bool e;
		bool w;
	};
	vector<cell> S;

};
#endif