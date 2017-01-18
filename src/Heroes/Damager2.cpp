#include "../../include/Heroes/heroes.h"

using namespace std;

Damager2::Damager2(int lvl){
  turn = 0;
  turn_rest = 0;
  level = lvl;
  aggro = 1;
  health=8+7.3*level;
  max_health = health;
  name = "Assassin";
  SkillsList.push_back("Stab");
  SkillsList.push_back("Stealth");
}

void Damager2::Stab(Charac& Target){
  int dmg=level+nrand(2*level);

  if(level >= 10){
    dmg=dmg*2;
  }
  if(RogueStealth) {dmg=dmg*2.5; RogueStealth=false;}
  Target.DealDamage(dmg);
  cout << name << " deals " << dmg << " damage stabbing the enemy." << endl;
}

void Damager2::Stealth(){
  RogueStealth=true;
  cout << name << " is now hidden to backstab the enemy." << endl;
  }

void Damager2::ChooseAction(Charac& C1, Charac& C2, Charac& C3, Charac& Target){
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
      Stab(Target);
      break;
    case 2:
      Stealth();
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}
