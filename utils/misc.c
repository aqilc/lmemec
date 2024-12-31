#include "misc.h"

coords screenres = {0};

// Get the screen resolution and store it in screenres
coords getres() {
  if (screenres.x == 0 || screenres.y == 0) {
    HDC hdc = GetDC(NULL);
    screenres.x = GetDeviceCaps(hdc, HORZRES);
    screenres.y = GetDeviceCaps(hdc, VERTRES);
    ReleaseDC(NULL, hdc);
  }

  return screenres;
}

// Gets mouse position
POINT getmouse() {

  // Where the cursor info is outputted to
  POINT p = {0};

  // Gets the cursor position, with error handling
  if (!GetCursorPos(&p))
    printf("Error getting mouse coords (EC%ld)", GetLastError());

  // Returns mouse
  return p;
}

// Prints given coordinates
void printcoords(coords c) {
  printf("x: %d, y: %d", c.x, c.y);
}

// Converts a POINT to a coords struct
coords pointtocoords(POINT p) {
  return (coords){p.x, p.y};
}
