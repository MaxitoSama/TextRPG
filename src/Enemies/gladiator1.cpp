#include "../../include/Enemies/enemies.h"

using namespace std;


Gladiator::Gladiator(){
  health=500;
  max_health=500;
  XPperKill=90;
  name="Gladiator";
}
void Gladiator::DealDamage(int dmg){
  if(health<=max_health/2){ resolve+=dmg; cout << "The " << name << " is acumulating damage!" << endl;}
  health = max(0,health-dmg);
}
void Gladiator::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  chooseagain:
  int targ=nrand(3);
  if(targ==1 && F1.IsAlive()) Attack(F1);
  else if(targ==1 && !F1.IsAlive()) goto chooseagain;
  if(targ==2 && F2.IsAlive()) Attack(F2);
  else if(targ==2 && !F2.IsAlive()) goto chooseagain;
  if(targ==3 && F3.IsAlive()) Attack(F3);
  else if(targ==3 && !F3.IsAlive()) goto chooseagain;
}
void Gladiator::Attack(Charac& F1){
 int dmg=35+resolve/2;
 resolve = resolve/2;
 F1.DealDamage(dmg);
 cout << name << " strikes " << F1.getName() << " dealing " << dmg << " damage!" << endl;
}
