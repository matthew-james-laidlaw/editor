#pragma once

#include "Model.hpp"
#include "View.hpp"

class Controller
{
public:

    Controller()
    {
        view.Reset();
    }

    void Main()
    {
        while (true)
        {
            // view.Clear();
            char keystroke = model.GetKeystroke();
            view.Update(keystroke);
        }
    }

private:

    Model model;
    View view;

};
