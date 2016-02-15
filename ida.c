#include <stdio.h>
#include <stdlib.h>

#include "ida.h"
#include "graph.h"
#include "heuristic.h"

inline int
IDA(node *current, float thold, float *tmp_thold, long int *gen_node, long int *exp_node) {
	int i;
	int actions[MAXACTIONS];
	int blank;
	int result = NOTFOUND;
	int num_actions, h;
	node sub_node;

	num_actions = findPossibleActions(current->s, actions, &blank);
	for (i=0; i<num_actions; i++) {
		if (isMoveBack(current->last_action, actions[i])) {
			continue;
		}
		copyState(current->s, sub_node.s);
		applyAction(actions[i], sub_node.s, blank);
		*gen_node += 1;
		sub_node.g = current->g + cost(actions[i], sub_node.s);
		h = findHeuristic(sub_node.s);
		sub_node.f = sub_node.g + h;
		if (sub_node.f > thold) {
			*tmp_thold = findMinThold(sub_node.f, *tmp_thold);
		} else {
			if (h == 0) {
				result = sub_node.g;
				return result;
			}
			*exp_node += 1;
			sub_node.last_action = actions[i];
			result = IDA(&sub_node, thold, tmp_thold, gen_node, exp_node);
			if (result != NOTFOUND) {
				return result;
			}
		}
	}
	return result;
}

solution_t
idaSearch(node *initial) {
	solution_t soln;
	int i = 0;
	int result = NOTFOUND;
	float tmp_thold;
	float thold = initial->f;

	soln.thold_used[i++] = thold;
	soln.gen_node = 0;
	soln.exp_node = 0;
	soln.final_soln = 0;
	soln.num_thold_used = 1;
	while (result == NOTFOUND) {
		tmp_thold = MAXFLOAT;
		result = IDA(initial, thold, &tmp_thold, &soln.gen_node, &soln.exp_node);
		if (result == NOTFOUND) {
			thold = tmp_thold;
			soln.thold_used[i++] = tmp_thold;
			soln.num_thold_used++;
		}
	}
	soln.final_soln = result;
	return soln;
}