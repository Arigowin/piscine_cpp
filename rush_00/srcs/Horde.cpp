#include "Horde.hpp"

int Horde::_nb = 0;

Horde::Horde(void) {
    this->initTab();
}

Horde::Horde(Horde const &src) {
    *this = src;
}

Horde::~Horde(void) {
    int i = -1;
    while (++i < NB)
    {
        if (this->_tab[i])
            this->desaloc(i);
    }
}

void Horde::initTab(void) {
    int i = -1;
    while (++i < NB)
        this->_tab[i] = NULL;
}

void Horde::addEnemy(void) {
    int i = -1;

    if (this->_nb < NB)
    {
        while (this->_tab[++i] != NULL)
            ;
        this->_tab[i] = new Enemy(1 + (rand() % (COLS - 2)), 3);
        ++this->_nb;
    }
}

void Horde::move(void) {
    int i = -1;

    while (++i < NB)
    {
        if (this->_tab[i])
        {
            bool b = this->_tab[i]->move();
            if (!b)
                this->desaloc(i);
        }
    }
}

void Horde::desaloc(int i) {
    if (this->_tab[i] != NULL) {
        delete this->_tab[i];
        this->_tab[i] = NULL;
        this->_nb--;
    }
}

int Horde::getNb(void) const {
    return this->_nb;
}

Enemy *Horde::getTab(int i) const {
    return this->_tab[i];
}

Horde &Horde::operator=(Horde const &src) {
    int i = -1;

    while (++i < NB)
        this->_tab[i] = src.getTab(i);
    this->_nb = src.getNb();
    return *this;
}
