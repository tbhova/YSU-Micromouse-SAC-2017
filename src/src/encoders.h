#ifndef BUILD_FOR_PC
#ifndef ENCODERS_H
#define ENCODERS_H

class Encoders {

public:
    Encoders();

private:
    class Encoder {
    public:
        Encoder();
    };

    Encoder rightEncoder, leftEncoder;
};

#endif // ENCODERS_H
#endif // BUILD_FOR_PC
