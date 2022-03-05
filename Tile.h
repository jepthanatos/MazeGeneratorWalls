//============================================================================
// Name        : Tile.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
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
	Tile(void) : col{-1}, row{-1}, visited{false}, isRoom{false} {}

	// Initialize constructor.
	Tile(int i, int j, bool v = false, bool r = false) : col{i}, row{j}, visited{v}, isRoom{r} {}

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
		return Tile(tile.col + col, tile.row + row, false, this->isRoom and tile.isRoom);
	}

	// Getters.
	int getCol(void) const {
		return col;
	}

	int getRow(void) const {
		return row;
	}

	int isVisited(void) const {
		return visited;
	}

	bool getIsRoom(void) const {
		return isRoom;
	}

	bool getWall(int pos) const {
		return walls[pos];
	}

	int getRandomNeighbour(void) const {
		return neighbours[Utils::pickRandom(0, neighbours.size() - 1)];
	}

	// Setters.
	void setVisited(bool _visited) {
		visited = _visited;
	}

	void addNeighbour(int index) {
		neighbours.push_back(index);
	}

	void setWall(int pos, bool value) {
		walls[pos] = value;
	}

	void setIsRoom(bool _isRoom) {
		isRoom = _isRoom;
		if (isRoom) {
			walls = { false, false, false, false };
		}
	}

	// Other functions.
	bool hasNeighbours(void) {
		return neighbours.size() > 0;
	}

private:

	// Private variables
	int col, row;
	std::vector<bool> walls = { true, true, true, true };
	bool visited, isRoom;
	std::vector<int> neighbours;

};

//------------------------------------------------------------------------------
#endif /* TILE_H_ */

