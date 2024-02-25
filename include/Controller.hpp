#pragma once

#include "Model.hpp"
#include "View.hpp"

const char UP = 'k';
const char DOWN = 'j';
const char LEFT = 'h';
const char RIGHT = 'l';
const char QUIT = 'q';
const char INSERT = 'i';
const char ESC = '\033';

class Controller
{
public:

    Controller()
    {
        view.Reset();
    }

    void Main()
    {
        view.Render();

        while (true)
        {
            char keystroke = model.GetKeystroke();

            if (model.mode == Mode::Normal)
            {
                switch (keystroke)
                {
                    case QUIT:
                        view.Reset();
                        exit(0);
                    case UP:
                        view.MoveCursorUp();
                        break;
                    case DOWN:
                        view.MoveCursorDown();
                        break;
                    case LEFT:
                        view.MoveCursorLeft();
                        break;
                    case RIGHT:
                        view.MoveCursorRight();
                        break;
                    case INSERT:
                        model.mode = Mode::Insert;
                }
            }
            else if (model.mode == Mode::Insert)
            {
                switch (keystroke)
                {
                    case ESC:
                        model.mode = Mode::Normal;
                        break;
                    default:
                        std::cout << keystroke;
                        std::cout.flush();
                        break;
                }
            }
        }
    }

private:

    Model model;
    View view;

};
