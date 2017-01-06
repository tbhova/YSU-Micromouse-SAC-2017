#include "maze.h"
#include "micromouseexception.h"

Maze::Cell::Cell() {
	visitied = false;
	walls = 0;
}

bool Maze::Cell::isWall(Cardinal8 dir) const {
	int wallBit = cardinalToBit(dir);
	return (wallBit & walls) > 0;
}

void Maze::Cell::placeWall(Cardinal8 dir) {
	walls |= cardinalToBit(dir);
}

void Maze::Cell::removeWall(Cardinal8 dir) {
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

int Maze::cardinalToBit(Cardinal8 dir) {
	// If we get NE/SE/NW/SW
	int dirInt = (int)dir;
//	if ((dirInt % 2) == 1) {
//		throw MicromouseException("Can only convert NSWE to bit, given " + dir);
//	}

	int bitShifts = dirInt / 2;
	return 1 << bitShifts;
}

void Maze::placeWall(int x, int y, Cardinal8 dir) {
	mazeCells.at(x).at(y).placeWall(dir);
}

void Maze::removeWall(int x, int y, Cardinal8 dir) {
	mazeCells.at(x).at(y).removeWall(dir);
}

bool Maze::isWall(int x, int y, Cardinal8 dir) const {
	return mazeCells.at(x).at(y).isWall(dir);
}
