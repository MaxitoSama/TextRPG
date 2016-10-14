#include "heroes.h"

using namespace std;

Damager1::Damager1(int lvl){
  turn = 0;
  turn_rest = 0;
  level = lvl;
  aggro = 1;
  health=5+7*level;
  max_health = health;
  name = "Mage";
  SkillsList.push_back("Fireball");
  SkillsList.push_back("Blood Freezing");
}

void Damager1::Fireball(Charac& Target){
  int dmg=2 + 3*level + nrand(2*level);
  if(level >= 10){
    dmg=dmg*1.1;
  }
  Target.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage throwing a fireball." << endl;
}

void Damager1::BloodFreeze(Charac& Target){
  int dmg = min(Target.getHealth()*0.3,5+8*level);
  Target.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage freezing " << Target.getName() << "'s blood." << endl;
}

void Damager1::ChooseAction(Charac& C1, Charac& C2, Charac& C3, Charac& Target){
  ++turn;
  if(turn < turn_rest) return;
  ChooseActionAgain:
  if(!IsAlive()){
    cout << name << " is dead!" << endl;
    return;
  }
  cout << "-------------------" << endl;
  cout << "What should " << name << " do?" << endl;
  for(int i=1;i<=SkillsByLevel(level);++i){
    cout << i << ". " << SkillsList[i-1] << endl;
  }
  int a;
  cin >> a;
  if(a>SkillsByLevel(level)) goto ChooseActionAgain;
  switch(a){
    case 1:
      Fireball(Target);
      break;
    case 2:
      BloodFreeze(Target);
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}
