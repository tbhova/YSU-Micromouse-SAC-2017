#ifndef MAZE_H
#define MAZE_H

#include "cardinal8.h"
#include <vector>

class Maze {

private:
	class Cell {

	private:
		char walls : 4;
		bool visitied : 1;

	public:
		Cell();
		void placeWall(Cardinal8 dir);
		void removeWall(Cardinal8 dir);
		bool isWall(Cardinal8 dir) const;
		bool isVisited() const { return visitied; }
	};

	int sizeX, sizeY;
	std::vector<std::vector<Cell>> mazeCells = std::vector<std::vector<Cell>>();

	static int cardinalToBit(Cardinal8 dir);


public:
	Maze(const int sizeX, const int sizeY);

	int getSizeX() const { return sizeX; }
	int getSizeY() const { return sizeY; }

	void placeWall(int x, int y, Cardinal8 dir);
	void removeWall(int x, int y, Cardinal8 dir);
	bool isWall(int x, int y, Cardinal8 dir) const;

};

#endif // MAZE_H
