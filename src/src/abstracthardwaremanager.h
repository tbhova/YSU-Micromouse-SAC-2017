#ifndef ABSTRACTHARDWAREMANAGER_H
#define ABSTRACTHARDWAREMANAGER_H

#include "infraredsensorarray.h"

class AbstractHardwareManager {
public:
    virtual ~AbstractHardwareManager() {}
    virtual bool isLeftWall() const = 0;
    virtual bool isCenterWall() const = 0;
    virtual bool isRightWall() const = 0;
};

#endif // ABSTRACTHARDWAREMANAGER_H
