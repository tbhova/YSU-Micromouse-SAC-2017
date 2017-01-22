#include "maze.h"

Maze::Cell::Cell() {
	visitied = false;
	walls = 0;
}

bool Maze::Cell::isWall(const Cardinal8 dir) const {
	int wallBit = cardinalToBit(dir);
	return (wallBit & walls) > 0;
}

void Maze::Cell::placeWall(const Cardinal8 dir) {
	walls |= cardinalToBit(dir);
}

void Maze::Cell::removeWall(const Cardinal8 dir) {
	walls &= ~cardinalToBit(dir);
}


Maze::Maze(const int sizeX, const int sizeY) : sizeX(sizeX), sizeY(sizeY){
	for (int x = 0; x < sizeX; x++) {
		mazeCells.push_back(std::vector<Cell>());
		for (int y = 0; y < sizeY; y++) {
			mazeCells.at(x).push_back(Cell());
		}
	}

	for (int x = 0; x < sizeX; x++) {
		placeWall(x, 0, South);
		placeWall(x, sizeY - 1, North);
	}

	for (int y = 0; y < sizeY; y++) {
		placeWall(0, y, West);
		placeWall(sizeX - 1, y, East);
	}
}

int Maze::cardinalToBit(const Cardinal8 dir) {
    int dirInt = (int)dir;
	int bitShifts = dirInt / 2;
	return 1 << bitShifts;
}

Coordinate Maze::adjacentCell(const int x, const int y, const Cardinal8 dir) {
    Coordinate adjacent;
    adjacent.x = x;
    adjacent.y = y;

    switch (dir) {
    case North:
        adjacent.y++;
        break;
    case South:
        adjacent.y--;
        break;
    case West:
        adjacent.x--;
        break;
    case East:
        adjacent.x++;
        break;
    default:
        break;
    }
    return adjacent;
}

bool Maze::isValidCell(const Coordinate cell) const {
    return isValidCell(cell.x, cell.y);
}

bool Maze::isValidCell(const int x, const int y) const {
    return (x >=0) && (x < sizeX) && (y >= 0) && (y < sizeY);
}

void Maze::placeWall(const int x, const int y, const Cardinal8 dir) {
	mazeCells.at(x).at(y).placeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    mazeCells.at(adj.x).at(adj.y).placeWall(oppDir);
}

void Maze::removeWall(const int x, const int y, const Cardinal8 dir) {
	mazeCells.at(x).at(y).removeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    mazeCells.at(adj.x).at(adj.y).removeWall(oppDir);
}


bool Maze::isWall(const int x, const int y, const Cardinal8 dir) const {
	return mazeCells.at(x).at(y).isWall(dir);
}
