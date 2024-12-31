
#ifndef _CLICK_H_
#define _CLICK_H_

#include <stdbool.h>

typedef enum { right, left } mousebutton;

void click(int x, int y, bool absolute, mousebutton button);
void clickl(int x, int y);
void clickr(int x, int y);
void clicklr(int x, int y);
void clickrr(int x, int y);

#endif