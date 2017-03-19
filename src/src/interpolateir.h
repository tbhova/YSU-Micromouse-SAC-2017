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

    static const unsigned short int size = 18;

    // This data should be sorted in reverse order by voltage (high voltage = low distance)
    const IR_Data dataArray[size] =
    {
        IR_Data(624, 3000),
        IR_Data(615, 3500),
        IR_Data(562, 4000),
        IR_Data(480, 5000),
        IR_Data(415, 6000),
        IR_Data(362, 7000),
        IR_Data(321, 8000),
        IR_Data(286, 9000),
        IR_Data(261, 10000),
        IR_Data(214, 12000),
        IR_Data(188, 14000),
        IR_Data(167, 16000),
        IR_Data(153, 18000),
        IR_Data(132, 20000),
        IR_Data(108, 25000),
        IR_Data(87, 30000),
        IR_Data(75, 35000),
        IR_Data(65, 40000)
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
