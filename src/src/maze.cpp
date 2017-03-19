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


Maze::Maze(const unsigned int sizeX, const unsigned int sizeY) : sizeX(sizeX), sizeY(sizeY){
    for (unsigned int x = 0; x < sizeX; x++) {
		mazeCells.push_back(std::vector<Cell>());
        for (unsigned int y = 0; y < sizeY; y++) {
			mazeCells.at(x).push_back(Cell());
		}
	}

    for (unsigned int x = 0; x < sizeX; x++) {
		placeWall(x, 0, South);
		placeWall(x, sizeY - 1, North);
	}

    for (unsigned int y = 0; y < sizeY; y++) {
		placeWall(0, y, West);
		placeWall(sizeX - 1, y, East);
	}
}

int Maze::cardinalToBit(const Cardinal8 dir) {
    int dirInt = static_cast<int>(dir);
	int bitShifts = dirInt / 2;
	return 1 << bitShifts;
}

Coordinate Maze::adjacentCell(const unsigned int x, const unsigned int y, const Cardinal8 dir) {
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

bool Maze::isValidCell(const unsigned int x, const unsigned int y) const {
    return (x < sizeX) && (y < sizeY);
}

const Maze::Cell& Maze::getCell(const unsigned int x, const unsigned int y) const {
    return mazeCells.at(x).at(y);
}

const Maze::Cell& Maze::getCell(const Coordinate cell) const {
    return getCell(cell.x, cell.y);
}

Maze::Cell& Maze::getCell(const unsigned int x, const unsigned int y) {
    return mazeCells.at(x).at(y);
}

Maze::Cell& Maze::getCell(const Coordinate cell) {
    return getCell(cell.x, cell.y);
}

void Maze::placeWall(const unsigned int x, const unsigned int y, const Cardinal8 dir) {
    getCell(x, y).placeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    getCell(adj).placeWall(oppDir);
}

void Maze::removeWall(const unsigned int x, const unsigned int y, const Cardinal8 dir) {
    getCell(x, y).removeWall(dir);

    Coordinate adj = adjacentCell(x, y, dir);
    if (!isValidCell(adj)) return;

    Cardinal8 oppDir = oppositeDirection(dir);
    getCell(adj).removeWall(oppDir);
}


bool Maze::isWall(const unsigned int x, const unsigned int y, const Cardinal8 dir) const {
    return getCell(x, y).isWall(dir);
}

vector<Coordinate> Maze::getNeighboringCells(const unsigned int x, const unsigned int y) const {
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

bool Maze::hasMouseVisited(const unsigned int x, const unsigned int y) const {
    return getCell(x, y).isVisited();
}

bool Maze::hasMouseVisited(const Coordinate cell) const {
    return hasMouseVisited(cell.x, cell.y);
}

void Maze::setMouseVisited(const unsigned int x, const unsigned int y) {
    if (!hasMouseVisited(x, y)) {
        cellsVisited++;
    }
    getCell(x, y).setVisited();
}

void Maze::setMouseVisited(const Coordinate cell) {
    setMouseVisited(cell.x, cell.y);
}

bool Maze::hasTraversalVisited(const unsigned int x, const unsigned int y) const {
    return getCell(x, y).isTraversalVisited();
}

bool Maze::hasTraversalVisited(const Coordinate cell) const {
    return hasTraversalVisited(cell.x, cell.y);
}

void Maze::setTraversalVisited(const unsigned int x, const unsigned int y) {
    getCell(x, y).setTraversalVisited(true);
}

void Maze::setTraversalVisited(const Coordinate cell) {
    setMouseVisited(cell.x, cell.y);
}

void Maze::resetTraversalVisited() {
    for (unsigned int x = 0; x < sizeX; x++) {
        for (unsigned int y = 0; y < sizeY; y++) {
            getCell(x, y).setTraversalVisited(false);
        }
    }
}

Cardinal8 Maze::getDirectionBetweenCells(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2) {
    if ((x1 == x2) == (y1 == y2)) {
        //Invalid input
        return NorthEast;
    } else if (x1 == x2) {
        return y1 > y2 ? South : North;
    } else {
        return x1 > x2 ? West : East;
    }
}

Cardinal8 Maze::getDirectionBetweenCells(const Coordinate fromCell, const Coordinate toCell) {
    return getDirectionBetweenCells(fromCell.x, fromCell.y, toCell.x, toCell.y);
}

bool Maze::isMazeMapped() const {
    const unsigned int numberOfCells = sizeX * sizeY;
    return (numberOfCells == cellsVisited);
}
