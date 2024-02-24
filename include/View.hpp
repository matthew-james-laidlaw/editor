#pragma once

#include <iostream>
#include "Terminal.hpp"

const char UP = 'k';
const char DOWN = 'j';
const char LEFT = 'h';
const char RIGHT = 'l';

class View
{
public:

    void Reset()
    {
        std::cout << "\033[2J";
        std::cout << "\033[H";
        std::cout.flush();
    }

    void Update(char keystroke)
    {
        switch (keystroke)
        {
            case UP:
                std::cout << "\033[1A";
                break;
            case DOWN:
                std::cout << "\033[1B";
                break;
            case LEFT:
                std::cout << "\033[1D";
                break;
            case RIGHT:
                std::cout << "\033[1C";
                break;
            default:
                break;
        }
        std::cout.flush();
    }

    Terminal terminal;

};
