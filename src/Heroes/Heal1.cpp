#include "../../include/Heroes/heroes.h"

using namespace std;

Heal1::Heal1(int lvl){
  turn = 1;
  turn_rest = 1;
  level = lvl;
  aggro = 1;
  health=5+15*level;
  max_health = health;
  name = "Medic";
  SkillsList.push_back("Heal");
  SkillsList.push_back("Blood Transfusion");
}

void Heal1::ChooseAction(Charac& C1,Charac& C2,Charac& C3,Charac& Target){
  ++turn;
  if(level >= 10 && health < max_health/2){
      health += level;
      cout << name << " has healed himself for "<< level <<" hp." << endl;
  }
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
      Healing(C1,C2,C3);
      break;
    case 2:
      if(C1.IsAlive()==false && C3.IsAlive()==false){
        cout << "All other targets are dead!" << endl;
        goto ChooseActionAgain;
      }
      BloodTrans(C1,C2,C3);
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}

void Heal1::Healing(Charac& C1, Charac& C2, Charac& C3){
choose_again:
  cout << "Choose a target!" << endl;
  cout << "1. " << C1.getName() << '(' << C1.getHealth() << '/'<< C1.getMaxHealth() << ')' << endl;
  cout << "2. " << C2.getName() << '(' << C2.getHealth() << '/'<< C2.getMaxHealth() << ')' << endl;
  cout << "3. " << C3.getName() << '(' << C3.getHealth() << '/'<< C3.getMaxHealth() << ')' << endl;
  int cc;
  cin >> cc;
  if(cc!=1 && cc!=2 && cc!=3){
    cout << "Choose a valid target!" << endl;
    goto choose_again;
  }
  if(cc==1 && C1.IsAlive()==false){
    cout << "Choose a valid target!" << endl;
    goto choose_again;
  }
  if(cc==2 && C2.IsAlive()==false){
    cout << "Choose a valid target!" << endl;
    goto choose_again;
  }
  if(cc==3 && C3.IsAlive()==false){
    cout << "Choose a valid target!" << endl;
    goto choose_again;
  }
  if(cc==1){ int quant = 3+7*level+nrand(2*level); C1.AddHealth(quant);
  cout << name << " has healed " << C1.getName() << " to " << C1.getHealth() << " hp" << endl;}
  if(cc==2){ int quant = 3+7*level+nrand(2*level); C2.AddHealth(quant);
  cout << name << " has healed " << C2.getName() << " to " << C2.getHealth() << " hp" << endl;}
  if(cc==3){ int quant = 3+7*level+nrand(2*level); C3.AddHealth(quant);
  cout << name << " has healed " << C3.getName() << " to " << C3.getHealth() << " hp" << endl;}
}

void Heal1::BloodTrans(Charac& C1, Charac& C2, Charac& C3){
  choose_again:
    cout << "Choose a target!" << endl;
    cout << "1. " << C1.getName() << endl;
    cout << "2. " << C3.getName() << endl;
    int cc;
    cin >> cc;
    if(cc!=1 && cc!=2){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==1 && C1.IsAlive()==false){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==2 && C3.IsAlive()==false){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==1){ int quant = C1.getMaxHealth(); C1.AddHealth(quant);
    DealDamage(max_health/2);
    cout << name << " has healed " << C1.getName() << " to " << C1.getHealth() << " hp" << endl;}
    if(cc==2){ int quant = C3.getMaxHealth(); C3.AddHealth(quant);
    DealDamage(max_health/2);
    cout << name << " has healed " << C3.getName() << " to " << C3.getHealth() << " hp" << endl;}
}
