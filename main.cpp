#include <iostream>
#include <unistd.h>
#include <termios.h>

const char UP = 'j';
const char DOWN = 'k';
const char LEFT = 'h';
const char RIGHT = 'l';

// Function to set the terminal to raw mode
void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

// Function to reset the terminal to its original settings
void disableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Re-enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

int main()
{
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
    {
        int row = 0;
        int col = 0;
        std::cout << "\033[2J";
        std::cout << "\033[H";
        std::cout.flush();
        switch (c)
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
        // std::cout << "\033[" << row << ";" << col << "H";
        std::cout.flush();
    }

    disableRawMode();

    return 0;
}
