#include "Header.h"

int main (int argc, char* argv[]){
	int n = 0, i = 0, j = 0, count = 0, num = 0, N = 0;
	 
	char choice = 'a';
	
	string read_in;

	if (2 <= argc){
		fstream read;
		read_in = argv[1];

		read.open(read_in);

		if (!read.is_open())
			cout << "Error File Not Read" << '\n';

		getline (read, read_in);

		n = read_in[0] - '0';

		N = n*n;

		DisjSets U ( N );
		Maze maze ( N );

		for (j = 0; j < N; j++){
			getline (read, read_in);
			for (int i = 0; i < read_in.size(); i++){
				if (read_in[i] == ' ' || read_in[i] == '\t')
					read_in.erase(read_in.begin() + i);
			}
			maze.setWall(j, read_in);
		}// sets walls
		
		U.fileSet(maze, n, N); // sets disjoint class

		//maze.printWalls (); //prints the walls

		maze.printMaze (n, N); // prints maze

		BFS (maze, U, N, n); // BFS

		DFS (maze, U, N, n); // DFS

		read.close ();
	}
	else{
// generating a maze
		cout << "Enter a size for the maze: ";
		cin >> n;
		cout << '\n';

		N = n*n;

		DisjSets U ( N );
		Maze maze ( N );

		srand ( time (NULL) );

		while (U.find(0) != U.find( N - 1)){
			i = rand () % ( N  );
			while (!U.checkAdjacency (i, j, n))
				j = rand ( ) % ( N );
			char temp = U.getDir (i, j, n);
			if (U.find(i) != U.find(j)){
				maze.breakWall (i, j, temp);
				U.unionSets (U.find(i), U.find(j));
			}
		}	// creates disjoint sets and generates mazes walls
		

		//maze.printWalls(); // prints walls

		maze.printMaze (n, N); // prints maze

 		BFS (maze, U, N, n); // BFS

		DFS (maze, U, N, n); // DFS

	}
	return 0;	
}