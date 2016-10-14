#ifndef GAME
#define GAME

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "characters.h"
using namespace std;

class Game{
private:
  int ExperienceRequired(int level);
  Hero* Tank;
  Hero* Healer;
  Hero* Damager;
  int level;
  int xp;
  void show_enemies_1();
  void show_enemies_2();

public:
  Game(int lvl, int char1, int char2, int char3, int xp);
  void main_game();
  int main_battle(int enemy);


};

#endif
