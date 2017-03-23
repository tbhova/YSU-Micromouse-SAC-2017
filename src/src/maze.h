#ifndef MAZE_H
#define MAZE_H

#include "cardinal8.h"
#include <vector>
#include "coordinate.h"

/**
 * @brief The Maze class
 * Keeps track of walls and which cells the mouse (and traversal algorithm) has visited
 */
class Maze {

private:
    /**
     * @brief The Cell class
     * 1 cell in the maze
     * A cell has 4 walls (North, South, East, West)
     * Keeps tracks of whether the maze or solver has visited the cell
     */
	class Cell {
	private:
        // Order of bits from least to most significant is: North, West, South, East
		char walls : 4;

        // true is mouse has been to this cell
        bool visited : 1;
        // true if current graph traversal has seen this cell
        bool traversalVisited : 1;

	public:
        /**
         * @brief Cell
         * Constructor - set up initial state of no walls and not visited
         */
		Cell();

        /**
         * @brief placeWall - adds a wall in the direction given
         * @param dir - Selects which wall to place - North, South, West, East
         */
        void placeWall(const Cardinal8 dir);

        /**
         * @brief removeWall - removes a wall from the cell in the given direction
         * @param dir - Which wall (NSWE) to remove
         */
        void removeWall(const Cardinal8 dir);

        /**
         * @brief isWall - checks whether there is a wall in "dir" direction
         * @param dir - Wall to check for (NSWE)
         * @return true if there is a wall, false otherwise
         */
        bool isWall(const Cardinal8 dir) const;

        /**
         * @brief isVisited - checks if the mouse has been to this cell
         * @return true if the mouse has visited this cell
         */
        bool isVisited() const { return visited; }
        /**
         * @brief setVisited - Mark this cell as visited by the mouse
         */
        void setVisited() { visited = true; }

        /**
         * @brief isTraversalVisited - checks whether the maze solver has seen this cell
         * @return true if the maze solver has seen this cell
         */
        bool isTraversalVisited() const { return traversalVisited; }
        /**
         * @brief setTraversalVisited - sets maze solver visited property of the cell
         * @param val - True -> has visited this cell, False -> has not visited
         */
        void setTraversalVisited(const bool val) { traversalVisited = val; }
	};

    unsigned int sizeX, sizeY;
    unsigned int cellsVisited = 0;
	std::vector<std::vector<Cell>> mazeCells = std::vector<std::vector<Cell>>();

    /**
     * @brief cardinalToBit converts a primary cardinal direction to an 8 bit number
     * @param dir - primary cardinal direction NSWE
     * @return int with 1 of the first 4 bits set
     */
    static int cardinalToBit(const Cardinal8 dir);

    /**
     * @brief isValidCell - checks if coordinates are in the maze
     * @param cell - coordinates of cell
     * @return true if the coordinates are in the maze
     */
    bool isValidCell(const Coordinate cell) const;
    bool isValidCell(const unsigned int x, const unsigned int y) const;

    //We need 2 copies of these so that we may call the method both from const and non const methods
    /**
     * @brief getCell return the cell at x, y
     * @param x - x coordinate
     * @param y - y coordinate
     * @return Reference to the cell at x,y
     */
    const Cell& getCell(const unsigned int x, const unsigned int y) const;
    const Cell& getCell(const Coordinate cell) const;
    Cell& getCell(const unsigned int x, const unsigned int y);
    Cell& getCell(const Coordinate cell);


public:
    /**
     * @brief Maze - Constructor, adds outer perimeter walls
     * @param sizeX - x dimension of the maze
     * @param sizeY - y dimension of the maze
     */
    explicit Maze(const unsigned int sizeX, const unsigned int sizeY);

    unsigned int getSizeX() const { return sizeX; }
    unsigned int getSizeY() const { return sizeY; }

    Coordinate getDestinationCell() const { return Coordinate(sizeX/2, sizeY/2); }

    /**
     * @brief placeWall - puts the "dir" wall at location x, y
     * Does nothing if there is already a wall there
     * @param x - x coordinate of cell to place a wall at
     * @param y - y coordinate of cell to place a wall at
     * @param dir - Wall to place (NSWE)
     */
    void placeWall(const unsigned int x, const unsigned int y, const Cardinal8 dir);

    /**
     * @brief removeWall - removes the "dir" wall from location x, y
     * Does nothing if there is no wall
     * @param x - x coordinate of cell to remove wall
     * @param y - y coordinate of cell to remove wall
     * @param dir - which wall to remove (NSWE)
     */
    void removeWall(const unsigned int x, const unsigned int y, const Cardinal8 dir);

    /**
     * @brief isWall - checks whether there is a "dir" wall at location x, y
     * @param x - x coordinate of cell to check
     * @param y - y coordinate of cell to check
     * @param dir - wall to check for (NSWE)
     * @return true if there is a wall
     */
    bool isWall(const unsigned int x, const unsigned int y, const Cardinal8 dir) const;
    bool isWall(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2) const;

    /**
     * @brief getNeighboringCells - get a list of reachable (no wall) adjacent cells
     * @param x - x coordinate of cell to check
     * @param y - y coordinate of cell to check
     * @return List of all cells that are reachable from x, y
     */
    std::vector<Coordinate> getNeighboringCells(const unsigned int x, const unsigned int y) const;
    std::vector<Coordinate> getNeighboringCells(const Coordinate cell) const;

    /**
     * @brief getDirectionBetweenCells get the Cardinal direction between 2 cells
     * The cells must be 1 cell apart, there is no error checking for this
     * @param fromCell first cell
     * @param toCell second cell
     * @return direction from fromCell to toCell
     */
    static Cardinal8 getDirectionBetweenCells(const Coordinate fromCell, const Coordinate toCell);

    /**
     * @brief getDirectionBetweenCells
     * @param x1 x coordinate of 1st cell
     * @param y1 y coordinate of 1st cell
     * @param x2 x coordinate of 2nd cell
     * @param y2 y coordinate of 2nd cell
     * @return Cardinal direction from (x1, y1) to (x2, y2)
     *
     * @see getDirectionBetweenCells
     */
    static Cardinal8 getDirectionBetweenCells(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2);

    /**
     * @brief adjacentCell - get the coordinates of the cell to the NSWE of given cell
     * @param x - given cell's x coordinate
     * @param y - given cell's y coordinate
     * @param dir - primary cardinal NSWE
     * @return int with 1 of lower 4 bits set
     *
     * North -> least significant bit (LSB)
     * West -> 2nd LSB
     * South -> 3rd LSB
     * East -> 4th LSB
     */
    static Coordinate adjacentCell(const unsigned int x, const unsigned int y, const Cardinal8 dir);
    static Coordinate adjacentCell(const Coordinate cell, const Cardinal8 dir);

    /**
     * @brief hasMouseVisited - checks if the mouse has visited x, y
     * @param x - x coordinate
     * @param y - y coordinate
     * @return true if the mouse has visited x, y
     */
    bool hasMouseVisited(const unsigned int x, const unsigned int y) const;
    bool hasMouseVisited(const Coordinate cell) const;

    /**
     * @brief setMouseVisited - mark cell x, y as visited by the mouse
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void setMouseVisited(const unsigned int x, const unsigned int y);
    void setMouseVisited(const Coordinate cell);

    /**
     * @brief hasTraversalVisited - checks if the maze solve has seen cell x, y
     * @param x - x coordinate
     * @param y - y coordinate
     * @return true if the maze solver has seen this cell
     */
    bool hasTraversalVisited(const unsigned int x, const unsigned int y) const;
    bool hasTraversalVisited(const Coordinate cell) const;

    /**
     * @brief setTraversalVisited - mark cell x,y as seen by the maze solver
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void setTraversalVisited(const unsigned int x, const unsigned int y);
    void setTraversalVisited(const Coordinate cell);

    /**
     * @brief resetTraversalVisited - mark all cells as not visited by maze solver
     */
    void resetTraversalVisited();

    /**
     * @brief isMazeMapped
     * @return true if all cells have been visited
     */
    bool isMazeMapped() const;
};

#endif // MAZE_H
