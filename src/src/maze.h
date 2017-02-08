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
        bool visited : 1;
        bool traversalVisited : 1;

	public:
		Cell();
        void placeWall(const Cardinal8 dir);
        void removeWall(const Cardinal8 dir);
        bool isWall(const Cardinal8 dir) const;

        bool isVisited() const { return visited; }
        void setVisited() { visited = true; }

        bool isTraversalVisited() const { return traversalVisited; }
        void setTraversalVisited(const bool val) { traversalVisited = val; }
	};

	int sizeX, sizeY;
	std::vector<std::vector<Cell>> mazeCells = std::vector<std::vector<Cell>>();

    static int cardinalToBit(const Cardinal8 dir);
    static Coordinate adjacentCell(const int x, const int y, const Cardinal8 dir);

    bool isValidCell(const Coordinate cell) const;
    bool isValidCell(const int x, const int y) const;

    //We need 2 copies of these so that we may call the method both from const and non const methods
    const Cell& getCell(const int x, const int y) const;
    const Cell& getCell(const Coordinate cell) const;
    Cell& getCell(const int x, const int y);
    Cell& getCell(const Coordinate cell);


public:
	Maze(const int sizeX, const int sizeY);

	int getSizeX() const { return sizeX; }
	int getSizeY() const { return sizeY; }

    void placeWall(const int x, const int y, const Cardinal8 dir);
    void removeWall(const int x, const int y, const Cardinal8 dir);
    bool isWall(const int x, const int y, const Cardinal8 dir) const;
    bool isWall(const int x1, const int y1, const int x2, const int y2) const;

    std::vector<Coordinate> getNeighboringCells(const int x, const int y) const;

    bool hasMouseVisited(const int x, const int y) const;
    bool hasMouseVisited(const Coordinate cell) const;
    void setMouseVisited(const int x, const int y);
    void setMouseVisited(const Coordinate cell);

    bool hasTraversalVisited(const int x, const int y) const;
    bool hasTraversalVisited(const Coordinate cell) const;
    void setTraversalVisited(const int x, const int y);
    void setTraversalVisited(const Coordinate cell);
    void resetTraversalVisited();
};

#endif // MAZE_H
