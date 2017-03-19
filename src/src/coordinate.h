#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate {
    unsigned int x, y;

    Coordinate(const unsigned int x, const unsigned int y) : x(x), y(y) {}

    Coordinate() {x = 0; y = 0;}

    bool operator==(const Coordinate& other) const {
        return other.x == x && other.y == y;
    }

    bool operator!=(const Coordinate& other) const {
        return !(*this == other);
    }
};

#endif // COORDINATE_H
