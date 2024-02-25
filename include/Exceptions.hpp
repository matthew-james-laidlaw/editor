#pragma once

#include <stdexcept>

class ExitApplicationException : public std::exception {
public:
    char* what () { return nullptr; }
};
