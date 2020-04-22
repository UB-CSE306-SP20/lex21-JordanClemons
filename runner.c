#include "blocksWorld.h"


int main(int argc, char * argv[]){
  int * world = create(10);
  world = move(2,3, world, 10);
  world = move(4,2,world, 10);
  bool retVal = above(4,3,world, 10);


  return 0;
}
