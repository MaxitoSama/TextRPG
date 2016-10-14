#include "enemies.h"

using namespace std;

RogueBandit::RogueBandit(){
  health=100;
  max_health=100;
  XPperKill=33;
  name="Rogue Bandit";
}
void RogueBandit::DealDamage(int dmg){
int dod=nrand(3);
if(dod==1 || dod==2) health=max(0,health-dmg);
if(dod==3){ dodged=true; cout << name << " dodged the attack! His next attack will be stronger." << endl;}
}

void RogueBandit::Attack(Charac& F1){
  int dmg=31;
  if(dodged){
    dmg = dmg*1.5;
    dodged=false;
    cout << name << " deals " << dmg << " damage to " << F1.getName() << " using dodge combo!" << endl;
  } else {
    cout << name << " deals " << dmg << " damage to " << F1.getName() << "!" << endl;
  }
  F1.DealDamage(dmg);
}

void RogueBandit::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  ++turn;
  chooseagain:
  int targ=nrand(3);
  if(targ==1 && F1.IsAlive()) Attack(F1);
  else if(targ==1 && !F1.IsAlive()) goto chooseagain;
  if(targ==2) Attack(F2);
  else if(targ==2 && !F2.IsAlive()) goto chooseagain;
  if(targ==3) Attack(F3);
  else if(targ==3 && !F3.IsAlive()) goto chooseagain;
}
