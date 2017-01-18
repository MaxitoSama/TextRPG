#include "../include/characters.h"

using namespace std;

void Charac::ChooseAction(Charac& C1, Charac& C2, Charac& C3, Charac& target){}

bool Charac::IsAlive(){
  if(health==0) return false;
  else return true;
}

int Charac::getHealth(){
  return health;
}
int Charac::getMaxHealth(){
  return max_health;
}
void Charac::AddHealth(int quant){
  health = min(health+quant,max_health);
}

string Charac::getName(){
  return name;
}

void Charac::DealDamage(int dmg){
  health = max(0,health-dmg);
}
