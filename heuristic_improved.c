#include <stdio.h>
#include <stdlib.h>

#include "heuristic.h"

/*last move heuristic function*/
int findHeuristic(int state[]) {
	int i;
	int h = 0;
	int one_tile_x, four_tile_y;
	coordinate_t initial_pos, final_pos;

	for (i=0; i<MAXSIZE; i++) {
		if (state[i] == 0) {
			continue;
		}
		initial_pos = findCoordinate(i);
		final_pos = findCoordinate(state[i]);
		h += findManhattanDistance(&initial_pos, &final_pos);
		if (state[i] == 1) {
			one_tile_x = initial_pos.x;
		}
		if (state[i] == 4) {
			four_tile_y = initial_pos.y;
		}
	}
	if (h != 0){
		if (one_tile_x != 0 && four_tile_y != 0) {
			h += 2;
		}
	}
	return h;
}
