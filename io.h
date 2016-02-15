#ifndef IO_H
#define IO_H

#include "graph.h"

#define MAXNUMTHOLD 100
#define MAXCOLUMN 4

/*initlize the program by fill initial state into an array */
inline void initialize(FILE* inputFile, node* initial_State);

/*given a structer contains solution and print it out*/
inline void printSoln(node *initial, solution_t *soln, double time_spend);

/*safe open a file and return a file pointer */
inline FILE* safeOpen(char *fname, const char *mode);
#endif