//============================================================================
// Name        : Utils.h
// Author      : Jorge
// Version     : 0.1
// Copyright   :
// Description : File with useful functions.
//============================================================================

#ifndef UTILS_H_
#define UTILS_H_

#include <cstdlib>
#include <ctime>

//==============================================================================
/* Utils */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define useful functions.
 */
class Utils {

public:

	static void initRamdom(void){
		srand(time(NULL));
	}

	static int pickRandom(int min, int max) {
		return rand() % (max - min + 1) + min;
	}

};

//------------------------------------------------------------------------------
#endif /* UTILS_H_ */
