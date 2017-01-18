#include "../../include/Enemies/enemies.h"

using namespace std;

Skeleton::Skeleton(){
  max_health=45;
  health=40;
  XPperKill=14;
  name="Skeleton";
}
void Skeleton::DealDamage(int dmg){
  health = max(health-dmg,0);
  //health = health-dmg;
}

void Skeleton::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  int SecretDecission=nrand(6);
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
void Skeleton::Attack(Charac& F1){
  int dmg = 10;
  F1.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage to " << F1.getName() << endl;
}
void Skeleton::AutoHeal(){
  int currenthealth=health;
  health = min(health+10,max_health);
  cout << name << " has healed for " << health-currenthealth << " hp." << endl;
}
