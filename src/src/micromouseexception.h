#ifndef MICROMOUSEEXCEPTION_H
#define MICROMOUSEEXCEPTION_H

class MicromouseException : public std::exception {
public:
	MicromouseException(char* error) : errorDescription(error) {}
	char* what() { return errorDescription; }

private:
	char* errorDescription;
};

#endif // MICROMOUSEEXCEPTION_H
