#ifndef GRAPH_H
#define GRAPH_H

#define UP      1
#define DOWN   -1
#define RIGHT   2
#define LEFT   -2
#define INITIAL 0
#define MOVE_BACK 0

#define UPPER_BOUND 0
#define LOWER_BOUND 3
#define LEFT_BOUND  0
#define RIGHT_BOUND 3

#define UPPER_CELL (state + blank - 4)
#define LOWER_CELL (state + blank + 4)
#define RIGHT_CELL (state + blank + 1)
#define LEFT_CELL  (state + blank - 1)
#define CURRENT_CELL (state + blank)

#define MAXACTIONS 4
#define MAXSIZE 16
#define MAXNUMTHOLD 100

typedef struct
{
	int s[MAXSIZE];	
	int g;
	float f;
	int last_action;
}node;

typedef struct
{
	int x;
	int y;
}coordinate_t;

typedef struct 
{
	long int gen_node;
	long int exp_node;
	int final_soln;
	float thold_used[MAXNUMTHOLD];
	int num_thold_used;
}solution_t;


/*return Manhattan Distance between given two points*/
inline int findManhattanDistance(coordinate_t* initial, coordinate_t* final);

/*return the cost of each move, in this assignment, 1*/
inline int cost(int action, int state[]);

/*return 1 if current action will lead to previous state, return 0 if not*/
inline int isMoveBack(int last_action, int current_action);

/*return the index of the blank in the state represented by an array*/
inline int findBlank(int state[]);

/*assign possible actions to an array, given a current state*/
inline int findPossibleActions(int state[], int actions[], int *blank);

/*	given a specified action,
	modify the state (make movement of the blank) in order to achieve a new state
*/
inline void applyAction(int action, int state[], int blank);

/*copy the state from parent node to current node */
inline void copyState(int original[], int copyed[]);

/*search the graph, return a structure contains information of soluntion*/
inline solution_t graphSearch(node *initial);

/*change the sell's index in the 1d array to a coordinate with x and y */
inline coordinate_t findCoordinate(int index);

/*	swap the position two sell in the array representing the current state 
	to actieved applied action
*/
inline void cellSwap(int *a, int *b);

/*return the minimun of two given floats*/
inline float findMinThold(float a, float b);
#endif