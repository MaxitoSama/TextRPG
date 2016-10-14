#ifndef ENEMIES_H
#define ENEMIES_H

#include "../characters.h"

class Enemy : public Charac{
public:
  int XPperKill;

protected:

};


class Goblin1 : public Enemy{
public:
  Goblin1();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
};

class Skeleton : public Enemy{
public:
  Skeleton();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
  void AutoHeal();
};

class GiantSkeleton : public Enemy{
public:
  GiantSkeleton();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
  void AutoHeal();
};

class Bandit : public Enemy{
public:
  Bandit();
  int V1;
  int V2;
  int V3;
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void ApplyVenom(Charac&,Charac&,Charac&);
  void Attack(Charac&);
  void Infect(int,Charac&,Charac&,Charac&);
};

class RogueBandit : public Enemy{
public:
  bool dodged;
  RogueBandit();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
};

class Gladiator : public Enemy{
public:
  int resolve;
  Gladiator();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
};

class MagicWorm : public Enemy{
public:
  MagicWorm();
  void DealDamage(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
private:
  bool cacoon;
  int cacoon_turns;
  int dmg_multiplier;
};

#endif
