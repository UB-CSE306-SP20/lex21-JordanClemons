#ifndef PYRAMID_H
#define PYRAMID_H

#include <stdbool.h>

struct pyramid {
  int myNumber;
  int onTopOf;
};

struct pyramid * * world;

void create(int n);
_Bool onTable(int m);
_Bool open(int m);
int on(int m);
_Bool above(int m, int n);
void move(int m, int n);

#endif
