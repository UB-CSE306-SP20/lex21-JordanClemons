#include "blocksWorld.h"

int * create(int n){
  int array[n];
  for(int x = 0; x < n; x++){
    array[x] = 0;
  }
  int * p = array;
  return p;
  
}


bool onTable(int m, int * world, int worldSize){
  if(m == 0){return false;}
  else if(m < 0 || m >= worldSize){return false;}
  else if(world[m] == 0){return true;}
  else{return false;}
}

bool open(int m, int * world, int worldSize){
  if(m == 0){return true;}
  for(int x = 0; x < worldSize; x++){
    if(world[x] == m)
      {
	return false;
      }
    
      } 
    return true; 
}


int on(int m, int * world, int worldSize){
  /*bool table = onTable(m, world, worldSize);
    if (table){ return 0;} */
  if(m < 0 || m >= worldSize){return m;}
  return world[m];

}


bool above(int m, int n, int * world, int worldSize){
  while(world[m] != 0){
    if (world[m] == n){return true;}
    else {
      m= world[m]; 
    }
  }
  return false;
}


  int * move(int m, int n, int * world, int worldSize){
       if ((open(m, world, worldSize)) && (open(n, world, worldSize))){
	 world[m] = n;
      } 
  return world;
}

