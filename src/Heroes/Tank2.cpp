#include "../../include/Heroes/heroes.h"

using namespace std;

Tank2::Tank2(int lvl){
  turn = 0;
  turn_rest = 0;
  level = lvl;
  aggro = 1;
  max_health=40*level;
  health=max_health;
  name="Protector";
  SkillsList.push_back("Shield Strike");
  SkillsList.push_back("Rest");
}

void Tank2::DealDamage(int dmg){
  health=max(health-dmg*0.9,0);
  cout << name << " absorbed " << dmg*0.1 << " damage!" << endl;
}

void Tank2::Attack(Charac& Target){
  int dmg = level+nrand(level);
  Target.DealDamage(dmg);
  cout << name << " attacks " << Target.getName() << " for " << dmg << " dmg" << endl;
}

void Tank2::RestSkill(){
  turn_rest=turn+3;
  if(level>=10) --turn_rest;
  max_health += 5*level;
}

void Tank2::ChooseAction(Charac& C1,Charac& C2,Charac& C3,Charac& Target){
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
      Attack(Target);
      break;
    case 2:
      RestSkill();
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}
