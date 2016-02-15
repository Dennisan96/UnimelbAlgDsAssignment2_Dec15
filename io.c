#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "graph.h"
#include "heuristic.h"


inline FILE*
safeOpen(char *fname, const char *mode) {
	FILE *fp;
	if ((fp = fopen(fname, mode)) == NULL) {
		printf("unable to open file\n");
		exit(EXIT_FAILURE);
	}
	return fp;
}


inline void
initialize(FILE* inputFile, node* initial) {
	int i = 0;

	while ((fscanf(inputFile, "%d", &(initial->s[i]))) == 1) {
		i++;
	}
	initial->last_action = INITIAL;
	initial->g = 0;
	initial->f = initial->g + findHeuristic(initial->s);
	return;
}


inline void
printSoln(node *initial, solution_t *soln, double time_spend) {
	int i, j;
	printf("Initial State:\n");
	for (i=0; i<MAXCOLUMN; i++) {
		for (j=0; j<MAXCOLUMN; j++) {
			printf("%4d", initial->s[4*i+j]);
		}
		printf("\n");
	}
	printf("Initial Estimate =%5.1f\n", soln->thold_used[0]);
	printf("Threshold =");
	for (i=0; i<soln->num_thold_used; i++) {
		printf("%5.1f ", soln->thold_used[i]);
	}
	printf("\n");
	printf("Solution = %3d\n", soln->final_soln);
	printf("Generated = %ld\n", soln->gen_node);
	printf("Expanded = %ld\n", soln->exp_node);
	printf("Time = %f\n", time_spend);
	printf("Expanded/Second = %d\n", (int)(soln->exp_node/time_spend));
	return;
}



