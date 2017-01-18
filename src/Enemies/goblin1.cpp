#include "../../include/Enemies/enemies.h"

using namespace std;

Goblin1::Goblin1(){
  max_health=20;
  health=20;
  XPperKill=10;
  name="Goblin";
}
void Goblin1::DealDamage(int dmg){
  health = max(health-dmg,0);
  //health = health-dmg;
}

void Goblin1::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  cc:
  int targ = nrand(3);

      if(targ==1 && F1.IsAlive()) {Attack(F1); return;}
      else if (targ==1 && !F1.IsAlive()) {goto cc;}

      if(targ==2 && F2.IsAlive()) {Attack(F2); return;}
      else if (targ==2 && !F2.IsAlive()) {goto cc;}

      if(targ==3 && F3.IsAlive()) {Attack(F3); return;}
      else if (targ==3 && !F3.IsAlive()) {goto cc;}
}
void Goblin1::Attack(Charac& F1){
  int dmg = 5;
  F1.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage to " << F1.getName() << endl;
}
