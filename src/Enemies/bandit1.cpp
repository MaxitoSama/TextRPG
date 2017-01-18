#include "../../include/Enemies/enemies.h"

using namespace std;


Bandit::Bandit(){
  max_health=75;
  health=75;
  XPperKill=25;
  name="Bandit";
}
void Bandit::DealDamage(int dmg){
  health = max(health-dmg,0);
  //health = health-dmg;
}
void Bandit::ChooseAction(Charac& F1,Charac& F2,Charac& F3,Charac& F123){
  ++turn;
  chooseagain:
  int target = nrand(4);
  if((target==1 || target==2) && F1.IsAlive()) {Attack(F1);Infect(target,F1,F2,F3);
  } else if((target==1 || target==2) && !F1.IsAlive()) goto chooseagain;
  if(target==3 && F2.IsAlive()) {Attack(F2);Infect(target,F1,F2,F3);
  } else if(target==3 && !F2.IsAlive()) goto chooseagain;
  if(target==4 && F3.IsAlive()) {Attack(F3);Infect(target,F1,F2,F3);
  } else if(target==4 && !F3.IsAlive()) goto chooseagain;

  ApplyVenom(F1,F2,F3);
}
void Bandit::Attack(Charac& F1){
int dmg=18;
F1.DealDamage(dmg);
cout << name << " deals " << dmg << " damage to " << F1.getName() << endl;
}
void Bandit::Infect(int ninfect,Charac& F1, Charac& F2, Charac& F3){
if ((ninfect==1 || ninfect==2) && V1==0) {V1=1;cout << name << " has infected " << F1.getName() << endl;}
if(ninfect==3 && V2==0) {V2=2;cout << name << " has infected " << F2.getName() << endl;}
if(ninfect==4 && V3==0) {V2=3;cout << name << " has infected " << F3.getName() << endl;}
}

void Bandit::ApplyVenom(Charac& F1, Charac& F2, Charac& F3){
  if(V1>0 && F1.IsAlive()){
    F1.DealDamage(V1);
    cout << "The venom deals " << V1 << " damage to " << F1.getName() << "!" << endl;
    ++V1;
  }
  if(V2>0 && F2.IsAlive()){
    F2.DealDamage(V2);
    cout << "The venom deals " << V2 << " damage to " << F2.getName() << "!" << endl;
    ++V2;
  }
  if(V3>0 && F3.IsAlive()){
    F3.DealDamage(V3);
    cout << "The venom deals " << V3 << " damage to " << F3.getName() << "!" << endl;
    ++V3;
  }
}
