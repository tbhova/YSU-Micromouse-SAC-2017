#include <vector>
#include <queue>
#include "breadthfirstgps.h"

std::vector<Cardinal8> getPath(const Cardinal8 fromWhere[][16], const Coordinate current, const Coordinate destination){
    std::vector<Cardinal8> path;
    return path;
}


void BreadthFirstGPS::setMaze(Maze* maze){
    this->maze = maze;
}

Cardinal8 BreadthFirstGPS::nextDirection(const Coordinate start,  const Coordinate destination){
    //Coordinate current;
    //Coordinate Destination;
    Coordinate current = start;
    std::queue<Coordinate> coordQueue;
    std::vector<Coordinate> neighbors;
    Cardinal8 fromWhere[16][16];
   while(!coordQueue.empty()){

     current = coordQueue.back();
     coordQueue.pop();
     if(current == destination){
           break;
    }

   for(int i=0; i<maze->getNeighboringCells(current.x, current.y).size(); i++)
        neighbors.push_back(maze->getNeighboringCells(current.x, current.y).at(i));

    for(int i=0; i<neighbors.size(); i++){ //Maybe iterator?
         if(!maze->hasTraversalVisited(neighbors.at(i))){
            maze->setTraversalVisited(neighbors.at(i));

           //Keep track of where the robot has been

           fromWhere[neighbors.at(i).x][neighbors.at(i).y]
               = North; //get which direction by asking the maze
              //Add neighbor to the queue
              coordQueue.push(neighbors.at(i));
           }
        }
        neighbors.clear();
    }
   //Need to write path pseudo code that uses fromWhere
   Cardinal8 next;
   //this->getPath(fromWhere, start, destination);
   return North;
}


