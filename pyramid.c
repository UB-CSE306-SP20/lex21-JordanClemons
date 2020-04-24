#include <stdlib.h>
#include "pyramid.h"

void create(int n) {
  struct pyramid * * w;
  w = malloc(sizeof(*w)*(n+1));
  for (int i=1; i<=n; i++) {
    w[i] = malloc(sizeof(*world[i]));
    (*w[i]).myNumber = i;
    (*w[i]).onTopOf = 0;
  }
  world = w;
}

_Bool onTable(int m) {
  return m==0 || world[0]->onTopOf == m;
}

_Bool open(int m) {
  return true;
}

int on(int m) {
  return world[m] -> onTopOf;
}

_Bool above(int m, int n) {
  return world[m] -> onTopOf == n;
}

void move(int m, int n) {
  struct pyramid * p = malloc(sizeof(*world[m]));
  (*p).myNumber = (*world[m]).myNumber;
  (*p).onTopOf = n;
  world[m] = p;
}
