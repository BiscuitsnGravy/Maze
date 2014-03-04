#include "Header.h"
void BFS (Maze maze, DisjSets U, int N, int n){
	int i = 0;

	Queue<int> Q;

	Q.enqueue (0); 
	U.markVisited ( 0 );			   
	
	cout << "Rooms visited by BFS: 0, ";
	while (!Q.isEmpty()){
		i = Q.dequeue ();

		U.upPath(i);

		if (0 <= (i-n) && (i-n) < N){ // north
			if (U.find (i) == U.find(i-n) && !U.isVisited (i-n) && maze.getWall(i, 'n') == 0){
				Q.enqueue (i-n);
				U.markVisited(i-n);
				cout << i-n << ", ";
			}
		}
		if (0 <= (i+n) && (i+n) < N){ // south
			if (U.find(i)== U.find(i+n) && !U.isVisited (i+n) && maze.getWall(i, 's') == 0){
				Q.enqueue (i+n);
				U.markVisited(i+n);
				if (i+n == N-1){
					cout << i+n << ", End.";
					U.upPath(i+n);
					break;
				}
				else
					cout << i+n << ", ";
			}
		}
		if (0 <= (i+1) && (i+1) < N){ // east
			if (U.find(i) == U.find(i+1) && !U.isVisited (i+1) && maze.getWall(i, 'e') == 0){
				Q.enqueue (i+1);
				U.markVisited(i+1);
				if (i+1 == N-1){
					cout << i+1 << ", End.";
					U.upPath(i+1);
					break;
				}
				else
					cout << i+1 <<  ", ";
			}
		}
		if (0 <= (i-1) && (i-1) < N){ // west
			if (U.find(i)== U.find(i-1) && !U.isVisited (i-1) && maze.getWall(i, 'w') == 0){
				Q.enqueue (i-1);
				U.markVisited(i-1);
				cout << i-1 << ", ";
			}
		}
	}
	U.createPath(maze, n ); // Create and print path in reverse
	U.printMazePath (maze,n,N); // Print path in X's
} 
void DFS (Maze maze, DisjSets U, int N, int n){
	int i = 0;

	Stack<int> S;
		
	S.push (0);
	U.markVisited (0);

	cout << "Rooms visited by DFS: 0, ";
	while (!S.isEmpty()){
		i = S.pop();

		U.upPath(i);

		if (0 <= (i-n) && (i-n) < N){ // north
			if (U.find (i) == U.find(i-n) && !U.isVisited (i-n) && maze.getWall(i, 'n') == 0){
				S.push (i-n);
				U.markVisited(i-n);
				cout << i-n << ", ";
			}
		}
		if (0 <= (i+n) && (i+n) < N){ // south
			if (U.find(i)== U.find(i+n) && !U.isVisited (i+n) && maze.getWall(i, 's') == 0){
				S.push (i+n);
				U.markVisited(i+n);
				if (i+n == N-1){
					cout << i+n << ", End.";
					U.upPath(i+n);
					break;
				}
				else
					cout << i+n << ", ";
			}
		}
		if (0 <= (i+1) && (i+1) < N){ // east
			if (U.find(i) == U.find(i+1) && !U.isVisited (i+1) && maze.getWall(i, 'e') == 0){
				S.push (i+1);
				U.markVisited(i+1);
				if (i+1 == N-1){
					cout << i+1 << ", End.";
					U.upPath(i+1);
					break;
				}
				else
					cout << i+1 <<  ", ";
			}
		}
		if (0 <= (i-1) && (i-1) < N){ // west
			if (U.find(i)== U.find(i-1) && !U.isVisited (i-1) && maze.getWall(i, 'w') == 0){
				S.push (i-1);
				U.markVisited(i-1);
				cout << i-1 << ", ";
			}
		}
	}
	U.createPath(maze, n ); // Create and print path in reverse
	U.printMazePath (maze,n,N); // Print path in X's
}