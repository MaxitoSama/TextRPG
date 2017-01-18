#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "../include/Enemies/enemies.h"
#include "../include/Heroes/heroes.h"

using namespace std;
/////
int main_battle(int level, int char1, int char2, int char3, int enemy1);
/////
int show_enemies_2(){
  enemieslist:
  cout << "Enemies list: " << endl
      << "1. Gladiator(BOSS)" << endl
      << "2. Magic Worm(level 7)" << endl
      << "3. Previous Page" << endl;
      int a1;
      cin >> a1;
      if(a1<1 || a1>3) goto enemieslist;
      if(a1==3){
        return 0;
      }
      return a1;
}
int show_enemies_1(){
  enemieslist:
  cout << "Enemies list: " << endl
      << "1. Goblin(level 1)" << endl
      << "2. Skeleton(level 2)" << endl
      << "3. Giant Skeleton(BOSS)" << endl
      << "4. Bandit(level 4)" << endl
      << "5. Rogue Bandit(level 5)" << endl
      << "6. Next Page" << endl;
      int a1;
      cin >> a1;
      if(a1<1 || a1>6) goto enemieslist;
      if(a1==6){
        a1 = show_enemies_2()+5;
        if(a1==5) goto enemieslist;
        return a1;
      }
      return a1;
}

int ExperienceRequired(int level){
  int a= 20*level + (level-1)*5;
  return a;
}

int main_game(int lvl, int char1, int char2, int char3, int xp){
  int req_exp = ExperienceRequired(lvl);
  cout << "---------------------" << endl;
  cout << "Level: " << lvl << endl;
  cout << "Experience: " << xp << "/" << req_exp << endl;

  if(char1==0){
    choose_tank:
    cout <<"Choose a tank: " << endl;
    cout << "1 - Armmoured Fighter" << endl;
    cout << "2 - Protector" << endl;
    cin >> char1;
    if( char1 != 1 && char1 != 2 ) goto choose_tank;
  }
  if(char2==0){
    choose_heal:
    cout <<"Choose a healer: " << endl;
    cout << "1 - Medic" << endl;
    cout << "2 - Divine Priest" << endl;
    cin >> char2;
    if( char2 != 1 && char2 != 2) goto choose_heal;
  }
  if(char3==0){
    choose_damager:
    cout <<"Choose a damager: " << endl;
    cout << "1 - Mage" << endl;
    cout << "2 - Assassin" << endl;
    cin >> char3;
    if(char3 != 1 && char3 != 2) goto choose_damager;
  }
  choose_action_game:

  req_exp = ExperienceRequired(lvl);

  cout << "--------------------" << endl;
  cout << "Choose an option:" << endl
      << "1.Fight!" << endl
      << "2.Save game" << endl
      << "3.Exit" << endl;

      int act1;
      cin>>act1;

      switch(act1){
        case 1:
        {
          int act2=show_enemies_1(); //CHOOSING THE ENEMY FROM THE LIST
          int xx = main_battle(lvl,char1,char2,char3,act2); //battle!
          xp += xx;

          //if (xx!=0) cout << "Gained " << xx << " experience points!" << endl;

          if(xp>=req_exp){
            ++lvl;
            xp = xp-req_exp;
            cout << "You have leveled up to level " << lvl << "!" << endl;
          }

          cout << "You now have " << xp << "/" << ExperienceRequired(lvl) << " xp points." << endl;

          goto choose_action_game;
          break;
        }
        case 2:
        {
          ofstream a_file("save.txt");
          a_file << 12346590 << " " << lvl << " " << char1 << " " << char2 << " " << char3 << " " << xp << " " << char1+char2+char3-lvl;
          a_file.close();
          goto choose_action_game;
          break;
        }
        case 3:
        {
          break;
        }

      }

  return 0;
}
//////////////// BATTLE FUNCTIONS
void type_lives(Hero& C1, Hero& C2, Hero& C3, Enemy& Foe){
  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
  cout << C1.getName() << " has " << C1.getHealth() << "/" << C1.getMaxHealth() <<  " hp." << endl;
  cout << C2.getName() << " has " << C2.getHealth() << "/" << C2.getMaxHealth() << " hp." << endl;
  cout << C3.getName() << " has " << C3.getHealth() << "/" << C3.getMaxHealth() << " hp." << endl;
  cout << endl;
  cout << Foe.getName() << " has " << Foe.getHealth() << "/" << Foe.getMaxHealth() << " hp." << endl;
  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

void actions_turn(Hero& C1, Hero& C2, Hero& C3, Enemy& Foe){


}

bool end_battle(Hero& C1, Hero& C2, Hero& C3, Enemy& F){
  if((C1.getHealth()==0 && C2.getHealth()==0 && C3.getHealth()==0) || (F.getHealth()==0)) return true;
  else return false;
}
bool winner_battle(Hero& C1, Hero& C2, Hero& C3){
  if(C1.getHealth()==0 & C2.getHealth()==0 & C3.getHealth()==0) return false;
  else return true;
}

//////////////////

int main_battle(int level, int char1, int char2, int char3, int enemy1){
  int current_turn=1;

  unique_ptr<Hero> Tank; //tank variable allocation
  unique_ptr<Hero> Heal; //heal variable allocation
  unique_ptr<Hero> Damager; //dps variable allocation
  unique_ptr<Enemy> Foe; //enemy variable allocation

  if(char1==1){
  Tank = unique_ptr<Hero>(new Tank1(level));
  } else if(char1==2){
  Tank = unique_ptr<Hero>(new Tank2(level));
  }

  if(char2==1){
  Heal = unique_ptr<Hero>(new Heal1(level));
  } else if(char2==2){
  Heal = unique_ptr<Hero>(new Heal2(level));
  }

  if(char3==1){
  Damager = unique_ptr<Hero>(new Damager1(level));
  } else if(char3==2){
  Damager = unique_ptr<Hero>(new Damager2(level));
  }

  if(enemy1==1) Foe = unique_ptr<Enemy>(new Goblin1());
  if(enemy1==2) Foe = unique_ptr<Enemy>(new Skeleton());
  if(enemy1==3) Foe = unique_ptr<Enemy>(new GiantSkeleton());
  if(enemy1==4) Foe = unique_ptr<Enemy>(new Bandit());
  if(enemy1==5) Foe = unique_ptr<Enemy>(new RogueBandit());
  if(enemy1==6) Foe = unique_ptr<Enemy>(new Gladiator());
  if(enemy1==7) Foe = unique_ptr<Enemy>(new MagicWorm());

  while(true){
    type_lives(*Tank,*Heal,*Damager,*Foe);
    cout << "****" << endl;
    Tank->ChooseAction(*Tank,*Heal,*Damager,*Foe);
    if(end_battle(*Tank,*Heal,*Damager,*Foe)) break;
    cout << "****" << endl;
    Heal->ChooseAction(*Tank,*Heal,*Damager,*Foe);
    if(end_battle(*Tank,*Heal,*Damager,*Foe)) break;
    cout << "****" << endl;
    Damager->ChooseAction(*Tank,*Heal,*Damager,*Foe);
    if(end_battle(*Tank,*Heal,*Damager,*Foe)) break;
    cout << "****" << endl;
    Foe->ChooseAction(*Tank,*Heal,*Damager, *Foe);
    if(end_battle(*Tank,*Heal,*Damager,*Foe)) break;
    cout << "******" << endl;
    cout << "Press ENTER to continue" << endl;
    cin.get();
    cin.get();
    current_turn++;
  }
  /// END OF BATTLE
  if(winner_battle(*Tank,*Heal,*Damager)){
     int XPGAIN=Foe->XPperKill;
     Tank.release();
     Heal.release();
     Damager.release();
     Foe.release();
     cout << "You have won! You earned " << XPGAIN << " xp." << endl;
     return XPGAIN;
   } else{
     Tank.release();
     Heal.release();
     Damager.release();
     Foe.release();
     cout << "You have lost!" << endl;
     return 0;
   }
  ///
}
