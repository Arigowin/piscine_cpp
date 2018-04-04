#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <iostream>
# include <sstream>
# include <ncurses.h>
# include <unistd.h>
# include <ctime>

class Screen {
    private:
        WINDOW                  *_win;
        size_t                  _nlines;
        size_t                  _ncols;


        std::string          _getDate(time_t const startTime) const;

    protected:

    public:
        Screen(void);
        Screen(Screen const &src);
        ~Screen(void);

        Screen          &operator=(Screen const &rhs);

        size_t          getNLines(void) const;
        size_t          getNCols(void) const;
        WINDOW          *getWindow(void) const;
    };

#endif
