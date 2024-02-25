#pragma once

#include <stdexcept>
#include <unistd.h>

enum class Mode
{
    Normal,
    Insert,
};

class Model
{

public:

    Model()
        : mode(Mode::Normal)
    {}

    char GetKeystroke()
    {
        char keystroke;
        int bytesRead = read(STDIN_FILENO, &keystroke, 1);
        if (bytesRead != 1)
        {
            throw std::runtime_error("failed to read in keystroke");
        }
        return keystroke;
    }

    Mode mode;

};
