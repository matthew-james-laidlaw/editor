#pragma once

#include <termios.h>

class Terminal
{

public:

    Terminal()
    {
        EnableRawMode();
    }

    ~Terminal()
    {
        DisableRawMode();
    }

private:

    void EnableRawMode() {
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    }

    void DisableRawMode() {
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag |= (ICANON | ECHO); // Re-enable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    }

};
