#include <Windows.h>
#include <stdbool.h>
#include <stdio.h>

#include "misc.h"
#include "click.h"


// Clicks on the point `x`,`y` with `button` button.
void click(int x, int y, bool absolute, mousebutton button) {

  // Gets screen resolution to scale to later
  coords screenres = getres();

  // Sets default flags
  DWORD flags = MOUSEEVENTF_MOVE;
  
  // If we should use absolute coordinates or not
  if(absolute) flags |= MOUSEEVENTF_ABSOLUTE;

  // Sets flags for right and left click
  if (button == left) {
    flags |= MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP;
  } else flags |= MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP;
  
  // Sets up the input struct
  INPUT pog = {
    .type = INPUT_MOUSE,
    .mi = {
      .dy = ((float) y / (float) screenres.y) * 65535,
      .dx = ((float) x / (float) screenres.x) * 65535,
      .dwFlags = flags,
      .time = 0
    }
  };

  // Executes the inputs
  SendInput(1, &pog, sizeof(pog));
}

// Absolute left click
void clickl(int x, int y) { click(x, y, true, left); }

// Absolute right click
void clickr(int x, int y) { click(x, y, true, right); }

// Relative left click
void clicklr(int x, int y) { click(x, y, false, left); }

// Relative right click
void clickrr(int x, int y) { click(x, y, false, right); }
