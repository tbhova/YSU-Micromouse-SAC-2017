#include "maze.h"

using namespace std;

Maze::Cell::Cell() {
    visited = false;
    traversalVisited = false;
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

const Maze::Cell& Maze::getCell(const int x, const int y) const {
    return mazeCells.at(x).at(y);
}

const Maze::Cell& Maze::getCell(const Coordinate cell) const {
    return getCell(cell.x, cell.y);
}

Maze::Cell& Maze::getCell(const int x, const int y) {
    return mazeCells.at(x).at(y);
}

Maze::Cell& Maze::getCell(const Coordinate cell) {
    return getCell(cell.x, cell.y);
}

void Maze::placeWall(const int x, const int y, const Cardinal8 dir) {
    getCell(x, y).placeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    getCell(adj).placeWall(oppDir);
}

void Maze::removeWall(const int x, const int y, const Cardinal8 dir) {
    getCell(x, y).removeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    getCell(adj).removeWall(oppDir);
}


bool Maze::isWall(const int x, const int y, const Cardinal8 dir) const {
    return getCell(x, y).isWall(dir);
}

vector<Coordinate> Maze::getNeighboringCells(const int x, const int y) const {
    vector<Coordinate> answer = vector<Coordinate>();

    if (isValidCell(x, y)) {
        for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
            if (!isWall(x, y, *it)) {
                answer.push_back(adjacentCell(x, y, *it));
            }
        }
    }

    return answer;
}

bool Maze::hasMouseVisited(const int x, const int y) const {
    return getCell(x, y).isVisited();
}

bool Maze::hasMouseVisited(const Coordinate cell) const {
    return hasMouseVisited(cell.x, cell.y);
}

void Maze::setMouseVisited(const int x, const int y) {
    if (!hasMouseVisited(x, y)) {
        cellsVisited++;
    }
    getCell(x, y).setVisited();
}

void Maze::setMouseVisited(const Coordinate cell) {
    setMouseVisited(cell.x, cell.y);
}

bool Maze::hasTraversalVisited(const int x, const int y) const {
    return getCell(x, y).isTraversalVisited();
}

bool Maze::hasTraversalVisited(const Coordinate cell) const {
    return hasTraversalVisited(cell.x, cell.y);
}

void Maze::setTraversalVisited(const int x, const int y) {
    getCell(x, y).setTraversalVisited(true);
}

void Maze::setTraversalVisited(const Coordinate cell) {
    setMouseVisited(cell.x, cell.y);
}

void Maze::resetTraversalVisited() {
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            getCell(x, y).setTraversalVisited(false);
        }
    }
}

bool Maze::isMazeMapped() {
    static const int numberOfCells = sizeX*sizeY;
    return (numberOfCells == cellsVisited);
}
