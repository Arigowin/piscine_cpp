#include "Screen.hpp"

Screen::Screen(void) {
    initscr();
    timeout(-1);

    this->_win = newwin(10, 10, 0, 0); // Create a new windows. Start at the position [0,0]

    box(stdscr, ACS_VLINE, ACS_HLINE);
    mvhline(2, 1, '-', COLS - 2);
    cbreak(); // One character a time
    noecho(); // Don't print the user input
    keypad(stdscr, TRUE); // Enable special keys
    nodelay(stdscr, TRUE); // Don't wait for input
    curs_set(0);
    refresh();
}

Screen::Screen(Screen const &src) {
    *this = src;
}

Screen::~Screen(void) {
    echo();
    nocbreak();
    endwin();
}

Screen          &Screen::operator=(Screen const &rhs) {
    if (this != &rhs) {
        this->_nlines = rhs.getNLines();
        this->_ncols = rhs.getNCols();
        this->_win = rhs._win;
    }
    return (*this);
}

size_t        Screen::getNLines(void) const {
    return  (this->_nlines);
}

size_t        Screen::getNCols(void) const {
    return (this->_ncols);
}

WINDOW      *Screen::getWindow(void) const {
    return this->_win;
}
