#pragma once

#include <iostream>
#include "Terminal.hpp"
#include "Exceptions.hpp"
#include "Model.hpp"

class View
{
public:

    void Render(Model& model)
    {
        this->Reset();
        std::string move = "\033[" + std::to_string(model.row) + ";" + std::to_string(model.col) + "H";
        std::cout << move;
        std::cout.flush();
    }

    void Reset()
    {
        this->Clear();
        this->MoveCursorHome();
    }

    void Clear()
    {
        std::cout << "\033[2J";
        std::cout.flush();
    }

    void MoveCursorHome()
    {
        std::cout << "\033[H";
        std::cout.flush();
    }


    // void Render()
    // {
    //     this->Reset();
    //     for (int i = 0; i < 10; ++i)
    //     {
    //         std::cout << "~";
    //         std::cout << "\033[1E";
    //         std::cout.flush();
    //     }
    //     this->MoveCursorHome();
    // }

    // void MoveCursorUp()
    // {
    //     std::cout << "\033[1A";
    //     std::cout.flush();
    // }

    // void MoveCursorDown()
    // {
    //     std::cout << "\033[1B";
    //     std::cout.flush();
    // }

    // void MoveCursorLeft()
    // {
    //     std::cout << "\033[1D";
    //     std::cout.flush();
    // }

    // void MoveCursorRight()
    // {
    //     std::cout << "\033[1C";
    //     std::cout.flush();
    // }

    Terminal terminal;

};
