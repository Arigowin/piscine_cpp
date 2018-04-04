#include "Game.hpp"

int main(void) {
    Game    game;

    if (game.mainLoop())
        std::cout << "You loose :'( !" << std::endl;
    return (0);
}
