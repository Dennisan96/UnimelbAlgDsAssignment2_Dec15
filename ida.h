#ifndef IDA_H
#define IDA_H

#include "graph.h"
#define MAXFLOAT 1000.0
#define NOTFOUND 1

/*ida* search algorithm, return the total cost to reach the final state*/
inline int IDA(node *current, float thold, float *tmp_thold, long int *gen_node, long int *exp_node);

/*implement ida or wida search algorithm and return the solution of the this assignment*/
inline solution_t idaSearch(node *initial);
#endif