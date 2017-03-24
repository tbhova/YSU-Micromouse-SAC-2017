#include <vector>
#include <queue>
#include <stack>
#include "breadthfirstgps.h"

std::stack<Cardinal8> BreadthFirstGPS::getPath(std::vector<std::vector<Cardinal8>> fromWhere,
                                               const Coordinate current, const Coordinate destination){
    std::stack<Cardinal8> path;
    Coordinate traversalCoord = destination;

    while(traversalCoord != current) {
      const Cardinal8 direction = oppositeDirection(fromWhere[traversalCoord.x][traversalCoord.y]);
      traversalCoord = Maze::adjacentCell(traversalCoord, fromWhere[traversalCoord.x][traversalCoord.y]);

      path.push(direction);
    }

    return path;
}

std::vector<std::vector<Cardinal8>> BreadthFirstGPS::search(const Coordinate start, const Coordinate destination){
    maze->resetTraversalVisited();
    Coordinate current = start;  //The current location of the search
    std::queue<Coordinate> coordQueue; //The queue of coordinates to search
    std::vector<Coordinate> neighbors; //The neighbors of current
    bool foundDest = false; //If the search has found a neighbor that is the destination

    //Add the start to the queue and set is as visited so that it doesn't find it again
    coordQueue.push(current);
    maze->setTraversalVisited(current);

    std::vector<std::vector<Cardinal8>> fromWhere;
    fromWhere.resize(maze->getSizeY());
    for(unsigned int i = 0; i < maze->getSizeY(); i++){
        fromWhere.at(i).resize(maze->getSizeX());
    }


   do{
     //Get the current and remove it from the queue
     current = coordQueue.front();
     coordQueue.pop();

     //Get the neighboring cells (all cells that neighbor the current coordinate)
     neighbors = maze->getNeighboringCells(current);


    //Loop through all the neighbors,
    //and if they are not visited add them to the queue
    //and keep track of the direction that the neighbor came from
    for(unsigned int i=0; i < neighbors.size(); i++){
         if(!maze->hasTraversalVisited(neighbors.at(i))){
            maze->setTraversalVisited(neighbors.at(i));

           //Keep track of where the robot has been
           fromWhere[neighbors.at(i).x][neighbors.at(i).y]
               = maze->getDirectionBetweenCells(neighbors.at(i), current);
           //If the neighbor is the destination
           //then exit all loops and return the path
           if(neighbors.at(i) == destination){
               foundDest = true;
               break;
           }
           //Add neighbor to the queue
           coordQueue.push(neighbors.at(i));
         }
      }

    } while(!coordQueue.empty() && !foundDest);
    return fromWhere;
}

std::stack<Cardinal8> BreadthFirstGPS::fullPath(const Coordinate start, const Coordinate destination) {
    std::vector<std::vector<Cardinal8>> fromWhere;
    fromWhere = this->search(start, destination);

    return this->getPath(fromWhere, start, destination);
}

Cardinal8 BreadthFirstGPS::getDirectionTo(const Coordinate start, const Coordinate destination){
   return this->fullPath(start, destination).top();
}
