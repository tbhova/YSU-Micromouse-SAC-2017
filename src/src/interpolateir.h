#ifndef INTERPOLATEIR_H
#define INTERPOLATEIR_H

#include <vector>

class InterpolateIR {
private:
    struct IR_Data {
        unsigned short int voltage, distance;

        IR_Data(const unsigned short int voltage, const unsigned short int distance) :
            voltage(voltage), distance(distance) {}

        inline bool operator<(const IR_Data& rhs) const {
            // use greater than instead of less than since voltages are sorted in reverse order
            return voltage > rhs.voltage;
        }
    };

    static const unsigned short int threshold = 22;

    static const unsigned short int size = 16;

    // This data should be sorted in reverse order by voltage (high voltage = low distance)
    const IR_Data dataArray[size] =
    {
        IR_Data(852, 40),
        IR_Data(830, 50),
        IR_Data(765, 60),
        IR_Data(700, 70),
        IR_Data(623, 80),
        IR_Data(564, 90),
        IR_Data(511, 100),
        IR_Data(433, 120),
        IR_Data(361, 140),
        IR_Data(314, 160),
        IR_Data(273, 180),
        IR_Data(243, 200),
        IR_Data(167, 250),
        IR_Data(114, 300),
        IR_Data(83, 350),
        IR_Data(59, 400)

    };

    const std::vector<IR_Data>sensorCurve = std::vector<IR_Data>(dataArray, std::end(dataArray));

    unsigned short int voltsAt(const unsigned int index) const {
        return sensorCurve.at(index).voltage;
    }

    unsigned short int distAt(const unsigned int index) const {
        return sensorCurve.at(index).distance;
    }

public:
    InterpolateIR() {}

    unsigned short int getDistance(const unsigned short int voltage) const;

};

#endif // INTERPOLATEIR_H
