#include "../../include/Heroes/heroes.h"

using namespace std;

Heal2::Heal2(int lvl){
  turn = 0;
  turn_rest = 0;
  level = lvl;
  aggro = 1;
  health=1+13*level;
  max_health = health;
  name = "Divine Priest";
  SkillsList.push_back("Divine Heal");
  SkillsList.push_back("Resurrection");
}

void Heal2::ChooseAction(Charac& C1,Charac& C2,Charac& C3,Charac& Target){
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
      Healing(C1,C2,C3);
      break;
    case 2:
      if(C1.IsAlive()==true && C3.IsAlive()==true){
        cout << "All other targets are alive!" << endl;
        goto ChooseActionAgain;
      }
      Resurrection(C1,C3);
      break;
    default:
      cout << "Invalid option!" << endl;
      goto ChooseActionAgain;
      break;
  }

}

void Heal2::Healing(Charac& C1, Charac& C2, Charac& C3){
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
  int sh=5+9*level+nrand(2*level);
  if(cc==1){ C1.AddHealth(sh);
  cout << name << " has healed " << C1.getName() << " to " << C1.getHealth() << " hp" << endl;}
  if(cc==2){ C2.AddHealth(sh);
  cout << name << " has healed " << C2.getName() << " to " << C2.getHealth() << " hp" << endl;}
  if(cc==3){ C3.AddHealth(sh);
  cout << name << " has healed " << C3.getName() << " to " << C3.getHealth() << " hp" << endl;}

  if(level>=10){
  sh = sh*0.2;
  string nn;
  int a1=C1.getHealth(); int a2=C2.getHealth(); int a3=C3.getHealth();
  int m1 = min(a1,a2); int m2 = min(a1,a3); int m3 = min(m1,m2);
  if(m3==a1) C1.AddHealth(sh); nn=C1.getName();
  if(m3==a2) C2.AddHealth(sh); nn=C2.getName();
  if(m3==a3) C3.AddHealth(sh); nn=C3.getName();
  cout << nn << "Divine Aura heals " << nn << " for " << sh << " hp." << endl;
  }
}

void Heal2::Resurrection(Charac& C1, Charac& C3){
  choose_again:
    cout << "Choose a target!" << endl;
    cout << "1. " << C1.getName();
    if(C1.IsAlive()) cout << " (alive)" << endl;
    else cout << " (dead)" << endl;
    cout << "2. " << C3.getName();
    if(C3.IsAlive()) cout << " (alive)" << endl;
    else cout << " (dead)" << endl;
    int cc;
    cin >> cc;
    if(cc!=1 && cc!=2){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==1 && C1.IsAlive()==true){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==2 && C3.IsAlive()==true){
      cout << "Choose a valid target!" << endl;
      goto choose_again;
    }
    if(cc==1){ C1.AddHealth(C1.getMaxHealth()*0.1);
    cout << name << " has resurrected " << C1.getName() << " with " << C1.getHealth() << " hp" << endl;}
    if(cc==2){ C3.AddHealth(C3.getMaxHealth()*0.1);
    cout << name << " has resurrected " << C3.getName() << " with " << C3.getHealth() << " hp" << endl;}
    turn_rest=turn+3;
}
