#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Player.hpp"
#include "ShootList.hpp"
#include "Horde.hpp"

class Game
{
private:
  size_t                  _nbLives;
  size_t                  _score;
  time_t const            _startTime;  

public:
  Game(void);
  Game(Game const &src);
  ~Game(void);

  bool          collisionS(ShootList *shootList, Horde *horde, Player *p1);
  bool          collisionPE(Horde *horde, Player *p1);
  void          moveShoot(ShootList *shootList);
  void          input(Player *p, ShootList *shootList);
  int           mainLoop(void);
  void          printInfosGame(void) const;
  std::string   getDate(time_t const startTime) const;    

  size_t        getScore(void) const;
  size_t        getNbLives(void) const;

  Game &operator=(Game const &rhs);
};

#endif
