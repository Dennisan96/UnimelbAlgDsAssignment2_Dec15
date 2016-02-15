#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "io.h"
#include "ida.h"

inline coordinate_t
findCoordinate(int index) {
	coordinate_t c;

	c.x = index%4;
	c.y = index/4;
	return c;
}

inline int 
findManhattanDistance(coordinate_t* initial, coordinate_t* final) {
	return (abs(initial->x - final->x) + abs(initial->y - final->y));
}


/* given current state find possible actions in next step
   pass into an array of actions, "0" represent up, "1" represent left
   "2" represent down, "3" represent right.
*/
inline int
findPossibleActions(int state[], int actions[], int *blank) {
	int i = 0;
	coordinate_t c_blank;
	
	//Find blank (0) position
	*blank = findBlank(state);
	c_blank = findCoordinate(*blank);

	//Find impossible actions, "-1" represent this action is not possible.
	if (c_blank.y > UPPER_BOUND) {
		//can go up
		actions[i++] = UP;
	}  
	if (c_blank.x > LEFT_BOUND) {
		//can go left
		actions[i++] = LEFT;
	}
	if (c_blank.y < LOWER_BOUND) {
		//can go down
		actions[i++] = DOWN;
	}
	if (c_blank.x < RIGHT_BOUND) {
		//can go right
		actions[i++] = RIGHT;
	} 
	//finish
	return i;
}


inline int
findBlank(int state[]) {
	int i=0;
	while (state[i]!= 0) {
		i++;
	}
	return i;
}


inline void
applyAction(int action, int state[], int blank) {
	if (action == UP) {
		cellSwap(CURRENT_CELL, UPPER_CELL);
	}
	if (action == LEFT) {
		cellSwap(CURRENT_CELL, LEFT_CELL);
	}
	if (action == DOWN) {
		cellSwap(CURRENT_CELL, LOWER_CELL);
	}
	if (action == RIGHT) {
		cellSwap(CURRENT_CELL, RIGHT_CELL);
	}
	return;
}



inline void
copyState(int original[], int copyed[]) {
	int i;
	for (i=0; i<MAXSIZE; i++) {
		copyed[i] = original[i];
	}
	return;
}

inline int 
isMoveBack(int last_action, int current_action) {
	return (last_action + current_action == MOVE_BACK);
}


inline int 
cost(int action, int state[]) {
	return 1;
}

inline solution_t
graphSearch(node* initial) {
	return idaSearch(initial);
}

inline void
cellSwap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

inline float 
findMinThold(float a, float b) {
	if (a < b) {
		return a;
	}
	return b;
}





