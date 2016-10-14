#include "enemies.h"

using namespace std;

MagicWorm::MagicWorm(){
  health=100;
  max_health=100;
  XPperKill=90;
  name="Magic Worm";
  cacoon=false;
  cacoon_turns=0;
  dmg_multiplier=1;
}

void MagicWorm::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
if(cacoon){
  --cacoon_turns;
  if(cacoon_turns==0){
    cacoon=false;
    max_health=100;
    health=100;
    ++dmg_multiplier;
    cout << name << "has exited from its cacoon!" << endl;
    name="Magic Worm";
  }
} else {
  chooseagain:
  int targ=nrand(3);
  if(targ==1 && F1.IsAlive()) Attack(F1);
  else if(targ==1 && !F1.IsAlive()) goto chooseagain;
  if(targ==2 && F2.IsAlive()) Attack(F2);
  else if(targ==2 && !F2.IsAlive()) goto chooseagain;
  if(targ==3 && F3.IsAlive()) Attack(F3);
  else if(targ==3 && !F3.IsAlive()) goto chooseagain;
}

}

void MagicWorm::DealDamage(int dmg){
  if(cacoon){
    health=max(0,health-dmg);
  } else {
    health=max(1,health-dmg);
    if(health==1){
      cacoon=true;
      cacoon_turns=4;
      max_health=120;
      health=120;
      cout << name << "has transformed into a cacoon to fully heal and become stronger!" << endl;
      name="Cacoon";
    }
  }

}

void MagicWorm::Attack(Charac& F1){
int dmg=25*dmg_multiplier;
F1.DealDamage(dmg);
cout << name << " strikes " << F1.getName() << " dealing " << dmg << " damage!" << endl;
}
