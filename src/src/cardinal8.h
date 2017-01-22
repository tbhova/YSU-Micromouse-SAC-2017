#ifndef CARDINAL8_H
#define CARDINAL8_H

#include "vector"

enum Cardinal8 {
	North = 0,
	NorthWest = 1,
	West = 2,
	SouthWest = 3,
	South = 4,
	SouthEast = 5,
	East = 6,
	NorthEast = 7
};

static const Cardinal8 primaryCardinalArray[] = {North, West, South, East};

static const std::vector<Cardinal8> primaryCardinalList =
        std::vector<Cardinal8>(primaryCardinalArray, std::end(primaryCardinalArray));

Cardinal8 oppositeDirection(Cardinal8 dir) {
    int dirInt = (int)dir;
    dirInt += 4;
    if (dirInt > 7) { dirInt -= 8; }
    return (Cardinal8)dirInt;
}

#endif // CARDINAL8_H
