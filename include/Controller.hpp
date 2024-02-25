#pragma once

#include "Model.hpp"
#include "View.hpp"
#include "Exceptions.hpp"

#include <stdexcept>

class Controller
{

public:

    Controller() = default;
    ~Controller() = default;
    Controller(Controller const& other) = delete;
    Controller(Controller&& other) = delete;
    Controller& operator= (Controller const& other) = delete;
    Controller&& operator= (Controller&& other) = delete;

    void Main()
    {
        view.Reset();
        try
        {
            while (true)
            {
                char keystroke = GetKeystroke();
                model.Update(keystroke);
                view.Render(model);
            }
        }
        catch (ExitApplicationException const& e)
        {
            view.Reset();
            return;
        }
        catch (...)
        {
            throw;
        }
    }

    char GetKeystroke() const
    {
        char keystroke;
        int bytesRead = read(STDIN_FILENO, &keystroke, 1);
        if (bytesRead != 1)
        {
            throw std::runtime_error("failed to read in keystroke");
        }
        return keystroke;
    }

private:

    Model model;
    View view;

};
