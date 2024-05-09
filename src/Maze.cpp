//============================================================================
// Name        : Maze.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define and generate a maze.
//============================================================================

#include "Maze.h"

// Local includes.
#include "Color.h"


//==============================================================================
/* Maze */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Maze::Maze(const int _cols, const int _rows) : cols{_cols}, rows{_rows} {
	for (int j = 0; j < rows; ++j) {
		for (int i = 0; i < cols; ++i) {
			Tile tile(i, j, i == 0 && j == 0);
			grid.push_back(tile);
		}
	}
}

/*------------------------------------------------------------------------------
 * Function to get the index of a tile.
 * Returns -1 if the col or the row are out of the array.
 */
int Maze::index(int col, int row) {
	if (col < 0 or row < 0 or col >= cols or row >= rows){
		return -1;
	}
	return col + row * cols;
}

/*------------------------------------------------------------------------------
 * Function to get a random neighbor of a given tile.
 * Returns -1 if the there all neighbors have been visited.
 */
int Maze::checkNeighbours(Tile &tile) {
	std::vector<int> vectorIndex = {
		index(tile.getCol(), tile.getRow() - 1), 	// Top
		index(tile.getCol() + 1, tile.getRow()),	// Right
		index(tile.getCol(), tile.getRow() + 1),	// Bottom
		index(tile.getCol() - 1, tile.getRow()) 	// Left
	};

	tile.clearNeighbours();

	for (unsigned int i = 0; i < vectorIndex.size(); ++i) {
		int index = vectorIndex[i];
		if (index > -1 and !grid[index].isVisited()){
			tile.addNeighbour(index);
		}
	}
	if (tile.hasNeighbours()) {
		return tile.getRandomNeighbour();
	} else {
		return -1;
	}
}

/*------------------------------------------------------------------------------
 * Procedure to remove walls from two given tiles.
 */
void Maze::removeWalls(Tile &a, Tile &b) {
	int x = a.getCol() - b.getCol();
	if (x == 1) {
		a.setWall(3, false);
		b.setWall(1, false);
	} else if (x == -1) {
		a.setWall(1, false);
		b.setWall(3, false);
	}

	int y = a.getRow() - b.getRow();
	if (y == 1) {
		a.setWall(0, false);
		b.setWall(2, false);
	} else if (y == -1) {
		a.setWall(2, false);
		b.setWall(0, false);
	}
}

/*------------------------------------------------------------------------------
 * Procedure to generate a random maze.
 */
void Maze::generateMaze(void) {
	int currentIndex = 0;

	do {
		int nextIndex = checkNeighbours(grid[currentIndex]);
		if (nextIndex > -1) {
			removeWalls(grid[currentIndex], grid[nextIndex]);
			visited.push(currentIndex);
			grid[nextIndex].setVisited(true);
			currentIndex = nextIndex;
		} else {
			currentIndex = visited.top();
			visited.pop();
		}
	} while (!visited.empty());
}

/*------------------------------------------------------------------------------
 * Procedure to print a maze while it's being generated.
 */
void Maze::generateMazePrinting(void) {
	int currentIndex = 0;
	bool firstTime = true;
	bool completed = false;

	Img img(cols * 10, rows * 10, "Generating Maze");

	while (!img.isClosed()) {
		// Print the grid at the start only one time.
		if (firstTime) {
			for (int j = 0; j < rows; ++j) {
				for (int i = 0; i < cols; ++i) {
					const Tile tile = grid[index(i, j)];

					// Print each tile yellow.
					img.drawRectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10,
						(float*) &Color::yellow());

					printWalls(i, j, tile, img);
				}
			}
			firstTime = false;
		}

		if (!completed){
			do {
				int nextIndex = checkNeighbours(grid[currentIndex]);

				if (nextIndex > -1) {
					removeWalls(grid[currentIndex], grid[nextIndex]);
					visited.push(currentIndex);
					grid[nextIndex].setVisited(true);
					currentIndex = nextIndex;
				} else {
					currentIndex = visited.top();
					visited.pop();
				}

				for (int j = 0; j < rows; ++j) {
					for (int i = 0; i < cols; ++i) {
						const Tile tile = grid[index(i, j)];

						// Print the visited and actual tiles.
						if (currentIndex == index(i, j)) {
							img.drawRectangle
								(i * 10, j * 10, i * 10 + 10, j * 10 + 10,
									(float*) &Color::red());
						} else if (tile.isVisited()) {
							img.drawRectangle
								(i * 10, j * 10, i * 10 + 10, j * 10 + 10,
									(float*) &Color::blue());
						}

						printWalls(i, j, tile, img);
					}
				}

				img.display();

			} while (!visited.empty());
		}

		completed = visited.empty();

		img.display();
	}
}

/*------------------------------------------------------------------------------
 * Procedure to print an already generated maze.
 */
void Maze::printMaze(void) {
	Img img(cols * 10, rows * 10, "Generated Maze");

	bool firstTime = true;

	while (!img.isClosed()) {
		if (firstTime) {
			for (int j = 0; j < rows; ++j) {
				for (int i = 0; i < cols; ++i) {
					const Tile tile = grid[index(i, j)];

					// Print each tile blue.
					img.drawRectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10,
							(float*) &Color::blue());

					printWalls(i, j, tile, img);
				}
			}
			firstTime = false;
		}
		img.display();
	}
}

/*------------------------------------------------------------------------------
 * Procedure to print a maze's walls.
 */
void Maze::printWalls(int i, int j, const Tile &tile, Img &img){
	// Top.
	if (tile.getWall(0)) {
		img.drawLine(i * 10, j * 10, i * 10 + 10, j * 10,
			(float*) &Color::black());
	}

	// Bottom.
	if (tile.getWall(2)) {
		img.drawLine(i * 10, j * 10 + 10, i * 10 + 10,	j * 10 + 10,
			(float*) &Color::black());
	}

	// Right.
	if (tile.getWall(1)) {
		img.drawLine(i * 10 + 10, j * 10, i * 10 + 10,	j * 10 + 10,
			(float*) &Color::black());
	}

	// Left.
	if (tile.getWall(3)) {
		img.drawLine(i * 10, j * 10, i * 10, j * 10 + 10,
			(float*) &Color::black());
	}
}

//==============================================================================
