#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate {
    int x, y;

    Coordinate(const int x, const int y) : x(x), y(y) {}

    Coordinate() {x = 0; y = 0;}

    bool operator==(Coordinate& other) {
        return other.x == x && other.y == y;
    }

    bool operator==(const Coordinate& other) const {
        return other.x == x && other.y == y;
    }
};

#endif // COORDINATE_H
