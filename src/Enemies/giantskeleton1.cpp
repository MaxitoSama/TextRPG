#include "../../include/Enemies/enemies.h"

using namespace std;

GiantSkeleton::GiantSkeleton(){
  max_health=250;
  health=250;
  XPperKill=50;
  name="Giant Skeleton";
  turn=0;
}
void GiantSkeleton::DealDamage(int dmg){
  health = max(health-dmg,0);
  //health = health-dmg;
}

void GiantSkeleton::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  ++turn;
  int SecretDecission=nrand(7);
  if (SecretDecission!=1){
    cc:
    int targ = nrand(3);

    if(targ==1 && F1.IsAlive()) {Attack(F1); return;}
    else if (targ==1 && !F1.IsAlive()) {goto cc;}

    if(targ==2 && F2.IsAlive()) {Attack(F2); return;}
    else if (targ==2 && !F2.IsAlive()) {goto cc;}

    if(targ==3 && F3.IsAlive()) {Attack(F3); return;}
    else if (targ==3 && !F3.IsAlive()) {goto cc;}
  } else AutoHeal();
}
void GiantSkeleton::Attack(Charac& F1){
  int dmg = 30;
  if(turn>=10){ dmg = 60; cout << name << " is enraged!" << endl;}
  F1.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage to " << F1.getName() << endl;
}
void GiantSkeleton::AutoHeal(){
  int currenthealth=health;
  health = min(health+35,max_health);
  cout << name << " has healed for " << health-currenthealth << " hp." << endl;
}
