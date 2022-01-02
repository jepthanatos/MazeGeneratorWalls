//============================================================================
// Name        : Maze.cpp
// Author      : Jorge
// Version     : 0.1
// Copyright   :
// Description : File to define and generate a maze.
//============================================================================

#ifndef MAZE_H_
#define MAZE_H_

#include <vector>
#include <stack>

// Local includes.
#include "Tile.h"
#include "Img.h"

//==============================================================================
/* Maze */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define and generate a maze.
 */
class Maze {
public:
	// Constructor, copy constructor and destructor.
	Maze(const int _cols, const int _rows);
	Maze(const Maze &other);
	~Maze(void) {}

	// Public functions.
	void generateMaze(void);
	void generateMazePrinting(void);
	void printMaze(void);

	// Getters.
	std::vector<Tile> getGrid(void) {
		return grid;
	}

private:

	// Private functions.
	int index(int i, int j);
	int checkNeighbours(Tile &c);
	void removeWalls(Tile &a, Tile &b);
	void printWalls(int i, int j, const Tile &tile, Img &img);

	// Private variables
	int cols, rows;
	std::vector<Tile> grid;
	std::stack<int> visited;
};

//------------------------------------------------------------------------------
#endif /* MAZE_H_ */