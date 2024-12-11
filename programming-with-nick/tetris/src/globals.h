#pragma once

#include <vector>

#include "raylib.h"

extern const Color clrDarkBlue;

// Colors for the grid
extern const Color gridClrDarkGrey;
extern const Color gridClrGreen;
extern const Color gridClrRed;
extern const Color gridClrOrange;
extern const Color gridClrYellow;
extern const Color gridClrPurple;
extern const Color gridClrCyan;
extern const Color gridClrBlue;

extern const Color gridClrGridLines;

std::vector<Color> getCellColors(void);
