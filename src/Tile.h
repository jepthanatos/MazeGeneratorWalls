//============================================================================
// Name        : Tile.h
// Author      : Jorge
// Version     : 0.1
// Copyright   :
// Description : File to define a tile used in the maze.
//============================================================================

#ifndef TILE_H_
#define TILE_H_

#include <vector>

// Local includes.
#include "Utils.h"

//==============================================================================
/* Tile */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a tile used in the maze.
 */
class Tile {

public:

	// Default constructor.
	Tile(void) {
		col = row = -1;
		visited = false;
	}

	// Initialize constructor.
	Tile(int i, int j, bool v) {
		col = i;
		row = j;
		visited = v;
	}

	// Destructor.
	~Tile(void) {}

	void clearNeighbours(void){
		neighbours.clear();
	}

	// Operators.
	bool operator==(const Tile &tile) {
		return tile.col == col and tile.row == row;
	}

	Tile operator+(const Tile &tile) {
		return Tile(tile.col + col, tile.row + row, false);
	}

	// Getters.
	int getCol(void) {
		return col;
	}

	int getRow(void) {
		return row;
	}

	int isVisited(void) const{
		return visited;
	}

	bool getWall(int pos) const{
		return walls[pos];
	}

	int getRandomNeighbour(void){
		return neighbours[Utils::pickRandom(0, neighbours.size() - 1)];
	}

	// Setters.
	void setVisited(bool _visited){
		visited = _visited;
	}

	void addNeighbour(int index){
		neighbours.push_back(index);
	}

	void setWall(int pos, bool value){
		walls[pos] = value;
	}

	// Other functions.
	bool hasNeighbours(void){
		return neighbours.size() > 0;
	}

private:

	// Private variables
	int col, row;
	std::vector<bool> walls = { true, true, true, true };
	bool visited;
	std::vector<int> neighbours;

};

//------------------------------------------------------------------------------
#endif /* TILE_H_ */

