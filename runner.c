#include <stdio.h>
#include "pyramid.h"

int main() {
  int max = 3;
  create(max);
  for (int i=1; i<=max; i++) {
    printf("onTable(%d) is %d\n",i,onTable(i));
  }
  move(2,3);
  move(2,1);
  move(1,3);
  for (int i=1; i<=max; i++) {
    printf("onTable(%d) is %d\n",i,onTable(i));
  }
  return 0;
}
