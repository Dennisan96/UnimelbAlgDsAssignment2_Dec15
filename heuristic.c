#include <stdio.h>
#include <stdlib.h>

#include "heuristic.h"

/*heuristic using sum of Manhattan Distance*/
int 
findHeuristic(int state[]) {
	int i;
	int h = 0;
	coordinate_t initial_pos, final_pos;

	for (i=0; i<MAXSIZE; i++) {
		if (state[i] == 0) {
			continue;
		}
		initial_pos = findCoordinate(i);
		final_pos = findCoordinate(state[i]);
		h += findManhattanDistance(&initial_pos, &final_pos);
	}
	return h;
}
