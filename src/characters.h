#ifndef CHARACS_H
#define CHARACS_H

#include <iostream>
#include <string>
#include <vector>

#include "functionscharacters.h"

class Charac{
public:
  bool IsAlive();
  int getHealth();
  int getMaxHealth();
  std::string getName();
  virtual void AddHealth(int);
  virtual void DealDamage(int);
  virtual void ChooseAction(Charac&,Charac&,Charac&,Charac&)=0;
protected:
  std::string name;
  int turn;
  int turn_rest;
  int level;
  int aggro;
  int absorption;
  int health;
  int max_health;
};

#endif
