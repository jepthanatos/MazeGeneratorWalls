//============================================================================
// Name        : MazeGeneratorWalls.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Main program to generate a maze.
//============================================================================

// Local includes.
#include "Maze.h"
#include "Utils.h"

//==============================================================================
/* MazeGeneratorWalls */
//==============================================================================

/*------------------------------------------------------------------------------
 * Main program
 */
int main() {

	// Initialize random seed.
	Utils::initRamdom();

	// Columns and rows.
	const int COLUMNS = 100;
	const int ROWS = 50;

	// Create an empty maze.
	Maze maze(COLUMNS, ROWS);

	// Print the maze while generating it.
	maze.generateMazePrinting();

	// Generate the maze, then print it.
	//maze.GenerateMaze();
	//maze.PrintMaze();

	return 0;
}

//==============================================================================
