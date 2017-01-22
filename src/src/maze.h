#ifndef MAZE_H
#define MAZE_H

#include "cardinal8.h"
#include <vector>
#include "coordinate.h"

class Maze {

private:
	class Cell {

	private:
		char walls : 4;
		bool visitied : 1;

	public:
		Cell();
        void placeWall(const Cardinal8 dir);
        void removeWall(const Cardinal8 dir);
        bool isWall(const Cardinal8 dir) const;
		bool isVisited() const { return visitied; }
	};

	int sizeX, sizeY;
	std::vector<std::vector<Cell>> mazeCells = std::vector<std::vector<Cell>>();

    static int cardinalToBit(const Cardinal8 dir);
    static Coordinate adjacentCell(const int x, const int y, const Cardinal8 dir);

    bool isValidCell(const Coordinate cell) const;
    bool isValidCell(const int x, const int y) const;


public:
	Maze(const int sizeX, const int sizeY);

	int getSizeX() const { return sizeX; }
	int getSizeY() const { return sizeY; }

    void placeWall(const int x, const int y, const Cardinal8 dir);
    void removeWall(const int x, const int y, const Cardinal8 dir);
    bool isWall(const int x, const int y, const Cardinal8 dir) const;

};

#endif // MAZE_H
