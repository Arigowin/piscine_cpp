#ifndef HORDE_HPP
#define HORDE_HPP

#include <iostream>
#include "Enemy.hpp"

#define NB 50

class Horde
{

  private:
    static int  _nb;
    Enemy       *_tab[NB];

  public:
    Horde(void);
    Horde(int x, int y);
    Horde(Horde const &src);
    ~Horde(void);

    void    initTab(void);
    void    addEnemy(void);
    void    move(void);
    void    desaloc(int i);

    Horde &operator=(Horde const &src);

    int     getNb(void) const;
    Enemy   *getTab(int i) const;
};

#endif
