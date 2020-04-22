#include <stdbool.h>


int * create(int n); //Returns array of size n and sets each block to the table 



bool onTable(int m);  //Returns true if block m is on the table, false otherwise



bool open(int m);  //Returns true if there is no block on m, false otherwise



int on(int m);  //returns 0 if m is on the table and n if m is on block n, if error return m



bool above(int m, int n);  //returns true if m is directly on n, or if m is directly on x and x is above n, false otherwise


int * move(int m, int n);  //moves m onto n iff both blocks are open and in range, no effect otherwise

  
