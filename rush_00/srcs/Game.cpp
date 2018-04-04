#include "Game.hpp"

Game::Game(void) : _nbLives(3), _score(0), _startTime(time(NULL))  {}

Game::Game(Game const &src) : _startTime(time(NULL)) {
    *this = src;
}

Game::~Game(void) {}

// Collision with shoot for player or enemy
bool Game::collisionS(ShootList *shootList, Horde *horde, Player *p1) {
    size_t sX = 0;
    size_t sY = 0;
    size_t pX = 0;
    size_t pY = 0;
    size_t eX = 0;
    size_t eY = 0;
    size_t eSX = 0;
    size_t eSY = 0;
    int j;

    for (int i = 0; i < shootList->size(); ++i)
    {
        sX = shootList->consult_position(i)->getPosX();
        sY = shootList->consult_position(i)->getPosY();
        pX = p1->getPosX();
        pY = p1->getPosY();

        if (sX >= pX && sX <= pX + p1->getSizeX() - 1 && sY >= pY &&
            sY <= pY + p1->getSizeY() - 1)
        {
            shootList->remove_position(i);
            return true;
        }

        j = -1;
        while (++j < NB)
        {
            if (horde->getTab(j))
            {
                eX = horde->getTab(j)->getPosX();
                eY = horde->getTab(j)->getPosY();
                eSX = horde->getTab(j)->getSizeX();
                eSY = horde->getTab(j)->getSizeY();

                if (sX >= eX && sX <= eX + eSX - 1 && sY >= eY && sY <= eY + eSY - 1)
                {
                    shootList->remove_position(i);
                    horde->desaloc(j);
                    this->_score += 10;
                }
            }
        }
    }
    return false;
}

// Collision with player for enemy
bool Game::collisionPE(Horde *horde, Player *p1) {
    size_t pX = 0;
    size_t pY = 0;
    size_t eX = 0;
    size_t eY = 0;
    size_t eSX = 0;
    size_t eSY = 0;

    int j = -1;
    while (++j < NB) {
        if (horde->getTab(j)) {
            pX = p1->getPosX();
            pY = p1->getPosY();
            eX = horde->getTab(j)->getPosX();
            eY = horde->getTab(j)->getPosY();
            eSX = horde->getTab(j)->getSizeX();
            eSY = horde->getTab(j)->getSizeY();

            if ((pX >= eX && pX <= eX + eSX - 1 && pY >= eY && pY <= eY + eSY - 1) ||
                    (eX >= pX && eX + eSX <= pX + p1->getSizeX() - 1
                    && eY >= pY && eY + eSY <= pY + p1->getSizeY() - 1)) {
                horde->desaloc(j);
                return true;
            }
        }
    }
    return false;
}

void Game::moveShoot(ShootList *shootList) {
    for (int i = 0; i < shootList->size(); ++i) {
        bool b = shootList->consult_position(i)->move();
        if (!b) {
            shootList->remove_position(i);
        }
    }
}

void Game::input(Player *p, ShootList *shootList) {
    int c;

    c = getch();
    if (c && c >= KEY_DOWN && c <= KEY_RIGHT)
        p->move(c);

    if (c == 32)
        shootList->add_beginning(p->shoot());
}

std::string     Game::getDate(time_t const startTime) const {
    struct tm   *dt;
    char        buffer[30];
    time_t      tmp;

    tmp = time(NULL) - startTime;
    dt = localtime(&tmp);
    strftime(buffer, sizeof(buffer), "%M:%S", dt);
    return std::string(buffer);
}

void            Game::printInfosGame(void) const {
    std::stringstream   ss;
    std::string         date;

    date = this->getDate(this->_startTime);
    ss << "Score = " << this->_score << " Nb. lives = " << this->_nbLives << " Time = " << date;
    mvprintw(1, 1, ss.str().c_str());
    refresh();
}

int Game::mainLoop(void) {
    bool    loop = true;
    int     nframes = 0;

    Screen win;
    Player *p1 = new Player();
    ShootList shootList;
    Horde horde;

    while (loop) {
        this->printInfosGame();
        this->input(p1, &shootList);
        if (nframes % 200 == 0) {

            moveShoot(&shootList);
            horde.move();
            horde.addEnemy();

            loop = !this->collisionS(&shootList, &horde, p1);
            if (loop && this->_nbLives > 0)
                loop = !this->collisionPE(&horde, p1);
            if (!loop) {
                this->_nbLives--;
                if (this->_nbLives > 0) {
                    loop = true;
                    delete p1;
                    p1 = new Player();
                    p1->move(KEY_UP);
                    p1->move(KEY_DOWN);
                    sleep(1);
                }
            }
        }
        if (nframes % 1000 == 0)
            this->_score += 1;
        usleep(200);
        nframes++;
    }
    delete p1;
    return true;
}

size_t  Game::getScore(void) const {
    return this->_score;
}

size_t  Game::getNbLives(void) const {
    return this->_nbLives;
}

Game &Game::operator=(Game const &rhs) {
    this->_score = rhs.getScore();
    this->_nbLives = rhs.getNbLives();
    return *this;
}
