#pragma once

#include "Exceptions.hpp"

#include <stdexcept>
#include <unistd.h>

enum class Mode
{
    Normal,
    Insert,
};

const char UP = 'k';
const char DOWN = 'j';
const char LEFT = 'h';
const char RIGHT = 'l';
const char QUIT = 'q';
const char INSERT = 'i';
const char ESC = '\033';

class Model
{

public:

    Model()
        : mode(Mode::Normal)
        , row(0)
        , col(0)
    {}

    void Update(char keystroke)
    {
        switch (mode)
        {
            case Mode::Normal:
                UpdateNormalMode(keystroke);
                break;
            case Mode::Insert:
                UpdateInsertMode(keystroke);
                break;
        }
    }

    void UpdateNormalMode(char keystroke)
    {
        switch (keystroke)
        {
            case UP:
                --row;
                break;
            case DOWN:
                ++row;
                break;
            case LEFT:
                --col;
                break;
            case RIGHT:
                ++col;
                break;
            case INSERT:
                mode = Mode::Insert;
                break;
            case QUIT:
                throw ExitApplicationException();
                break;
        }
    }

    void UpdateInsertMode(char keystroke)
    {
        switch (keystroke)
        {
            case ESC:
                mode = Mode::Normal;
                break;
            default:
                break;
        }
    }

    Mode mode;

    int row;
    int col;

};
