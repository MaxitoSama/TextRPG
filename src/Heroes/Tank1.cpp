#include "heroes.h"

using namespace std;

//#include "characters.h"

Tank1::Tank1(int lvl){
  turn = 0;
  turn_rest = 0;
  level = lvl;
  aggro = 1;
  max_health=10+25*level;
  health=max_health;
  name="Armoured Fighter";
  SkillsList.push_back("Attack");
  SkillsList.push_back("First Aid");
}

void Tank1::Attack(Charac& Target){
  int dmg = 2+level+nrand(2+level);
  Target.DealDamage(dmg);
  cout << name << " attacks " << Target.getName() << " for " << dmg << " dmg" << endl;
}

void Tank1::FirstAid(){
  health = min(max_health,health+max_health*0.15);
}

void Tank1::ChooseAction(Charac& C1,Charac& C2,Charac& C3,Charac& Target){
  ++turn;

  int rn = rand()%10+1;
  if(level >= 10 && rn==1) {max_health=max_health*1.05; cout << name << " has increased its maximum health!" << endl;}

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
      FirstAid();
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}
