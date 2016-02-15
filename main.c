#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "io.h"

int 
main(int argc, char *argv[]) {
	node initial;
	clock_t begin, end;
	double time_spend;
	solution_t soln;

	/*test number of arguments*/
	if (argc < 2){
		printf("no file specified on commandline\n");
		exit(EXIT_FAILURE);
	}
	/*open input file*/
	FILE *inputFile = safeOpen(argv[1], "r");

	/*get the initial state*/
	initialize(inputFile, &initial);
	fclose(inputFile);

	/*clock begin and start searching*/
	begin = clock();
	soln = graphSearch(&initial);
	end = clock();
	time_spend = (double)(end-begin)/CLOCKS_PER_SEC;

	/*print result*/
	printSoln(&initial, &soln, time_spend);
	return 0;
}