
#ifndef _MISC_H_
#define _MISC_H_

#include <Windows.h>
#include <stdio.h>

typedef struct {
  int x, y;
} coords;

coords getres();
POINT getmouse();
void printcoords(coords c);
coords pointtocoords(POINT p);

#endif