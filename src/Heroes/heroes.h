#ifndef HEROES_H
#define HEROES_H

#include "../characters.h"
#include "../utils.h"

class Hero : public Charac{
public:

protected:
  std::vector<std::string> SkillsList;
};

class Tank1 : public Hero{
public:
  Tank1(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
  void FirstAid();
};

class Tank2 : public Hero{
public:
  Tank2(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Attack(Charac&);
  void DealDamage(int);
  void RestSkill();
};

class Heal1 : public Hero{
public:
  Heal1(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Healing(Charac&,Charac&,Charac&);
  void BloodTrans(Charac&,Charac&,Charac&);
};

class Heal2 : public Hero{
public:
  Heal2(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Healing(Charac&,Charac&,Charac&);
  void Resurrection(Charac&,Charac&);
};

class Damager1 : public Hero{
public:
  Damager1(int);
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Fireball(Charac&);
  void BloodFreeze(Charac&);
};
class Damager2 : public Hero{
public:
  Damager2(int);
  bool RogueStealth;
  void ChooseAction(Charac&,Charac&,Charac&,Charac&);
  void Stab(Charac&);
  void Stealth();
};

#endif
