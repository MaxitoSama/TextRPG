#include <iostream>

#include "../include/utils.h"

using namespace std;

int main_info_chars();
int main_info_enems();

int main_info_tanks();
int main_info_heals();
int main_info_dps();

int main_info(){

  choose_again:

  cout << "--------------------" << endl;
      vector<string> info_list_vector;
      info_list_vector.push_back("Characters");
      info_list_vector.push_back("Enemies");
      info_list_vector.push_back("Back");

      int c = choose_menu("Select from the list: ",info_list_vector);
      switch(c){
        case 1:
        {
          main_info_chars();
          goto choose_again;
          break;
        }
        case 2:
        {
          main_info_enems();
          goto choose_again;
          break;
        }
        case 3:
        {
          break;
        }
        default:
        break;

      }

      return 0;
}

int main_info_chars(){
  choose_again_chars:

  cout << "--------------------" << endl;

      vector<string> heroes_list_vector;
      heroes_list_vector.push_back("Tanks");
      heroes_list_vector.push_back("Healers");
      heroes_list_vector.push_back("Damagers");
      heroes_list_vector.push_back("Back");
      int c = choose_menu("Select from the list: ", heroes_list_vector);
      switch(c){
        case 1:
        {
          main_info_tanks();
          goto choose_again_chars;
          break;
        }
        case 2:
        {
          main_info_heals();
          goto choose_again_chars;
          break;
        }
        case 3:
        {
          main_info_dps();
          goto choose_again_chars;
          break;
        }
        case 4:
        {
          break;
        }
        default:
        cout << "Insert a valid option" << endl;
        goto choose_again_chars;
        break;

      }
  return 0;
}

int main_info_tanks(){
  choose_again_tanks:

  cout << "--------------------" << endl;
  cout << "Select from the list: " << endl
      << "1. Armoured Fighter" << endl
      << "2. Protector" << endl
      << "3.Back" << endl;


      int c;
      cin >> c;
      switch(c){
        case 1:
        {
          cout << "Name: Armoured Fighter" << endl
               << "Basic tank with moderate quantities of health and damage." << endl
               << "Skills:" << endl << endl
               << "1. Attack: deals a low amount of damage." << endl
               << "2. First aid: heals the tank a small amount of damage." << endl
               << "3. (Passive) Combat Mastery: each turn, the Armoured Fighter has a 10" << '%' << " chances to increase its maximum health." << endl;
           goto choose_again_tanks;
          break;
        }
        case 2:
        {
          cout << "Name: Protector" << endl
               << "Tank with a shield that absorbs 10" << '%' << " of damage passively. Has a great amount of health, but very poor damage." << endl
               << "Skills:" << endl << endl
               << "1. Shield Strike: deals a very low amount of damage." << endl
               << "2. Rest: increases the maximum health of the tank for a small amount resting over two turns." << endl
               << "3. (Passive) Fast Preparation: reduces by one turn the time of Rest." << endl;
          goto choose_again_tanks;
          break;
        }
        case 3:
        {
          break;
        }
        default:
        cout << "Insert a valid option" << endl;
        goto choose_again_tanks;
        break;

      }
  return 0;
}

int main_info_heals(){
  choose_again_heals:

  cout << "--------------------" << endl;
  cout << "Select from the list: " << endl
      << "1. Medic" << endl
      << "2. Divine Priest" << endl
      << "3. Back" << endl;


      int c;
      cin >> c;
      switch(c){
        case 1:
        {
          cout << "Name: Medic" << endl
               << "Combat medic that heals his allies and is capable of using some powerful medicines." << endl
               << "Skills:" << endl << endl
               << "1. Heal: heals an ally for a moderate amount of health." << endl
               << "2. Blood Transfusion: sacrifices half of the maximum health of the medic to fully heal an ally." << endl
               << "3. (Passive) Herbal Essence: each turn, if the medic is below half of its maximum life, it will heal himself for a small amount." << endl;
          goto choose_again_heals;
          break;
        }
        case 2:
        {
          cout << "Name: Divine Priest" << endl
               << "Priest that uses divine magic to support its allies." << endl
               << "Skills:" << endl << endl
               << "1. Divine Heal: heals an ally for a moderate amount of health." << endl
               << "2. Resurrection: resurrects a dead ally and rests for two turns." << endl
               << "3. (Passive) Divine Aura: each time the priest uses divine heal, the ally with the lowest health receives a fraction of the amount healed." << endl;
          goto choose_again_heals;
          break;
        }
        case 3:
        {
          break;
        }
        default:
        cout << "Insert a valid option" << endl;
        goto choose_again_heals;
        break;

      }
  return 0;
}

int main_info_dps(){
  choose_again_dps:

  cout << "--------------------" << endl;
  cout << "Select from the list: " << endl
      << "1. Mage" << endl
      << "2. Assassin" << endl
      << "3. Back" << endl;


      int c;
      cin >> c;
      switch(c){
        case 1:
        {
          cout << "Name: Mage" << endl
               << "Magician that domines arcane powers and the elements to deal damage." << endl
               << "Skills:" << endl << endl
               << "1. Fireball: casts a fireball that deals moderate damage" << endl
               << "2. Blood Freezing: freezes the blood of the enemy, dealing less damage as the enemy's health decreases." << endl
               << "3. (Passive) Fire harmonization: increases damage dealt by fireball." << endl;
          goto choose_again_dps;
          break;
        }
        case 2:
        {
          cout << "Name: Assassin" << endl
               << "Assassin with training in the combat field." << endl
               << "Skills:" << endl << endl
               << "1. Stab: stabs the enemy with a dagger, dealing a moderate amount of damage." << endl
               << "2. Stealth: hides in the shadows increasing the damage of the next stab." << endl
               << "3. (Passive) Double dagger: doubles the damage of each stab." << endl;
          goto choose_again_dps;
          break;
        }
        case 3:
        {
          break;
        }
        default:
        cout << "Insert a valid option" << endl;
        goto choose_again_dps;
        break;

      }
  return 0;
}

bool main_info_enems_1(){
  choose_again_enems:

  cout << "--------------------" << endl;
  cout << "Select from the list: " << endl
      << "1. Bandit" << endl
      << "2. Rogue Bandit" << endl
      << "3. Gladiator (boss)" << endl
      << "4. Previous Page" << endl
      << "5. Next Page" << endl;

      int a;
      cin >> a;
      switch(a){
        case 1:
        {
          cout << "Bandit that poisons its enemies dealing increased damage with time." << endl;
          break;
        }
        case 2:
        {
          cout << "Bandit that can dodge attacks agains him." << endl;
          break;
        }
        case 3:
        {
          cout << "Boss of high damage and health. After 50%% of his life, he becomes enraged and returns a fraction of the damage dealt to him." << endl;
          break;
        }
        case 4:
        {
          return true;
          break;
        }
        case 5:
        {

          break;
        }
        default:
        {
          cout << "Choose a valid option!" << endl;
          goto choose_again_enems;
        }
      }
      return false;
}

int main_info_enems(){
  choose_again_enems:

  cout << "--------------------" << endl;
  cout << "Select from the list: " << endl
      << "1. Goblin" << endl
      << "2. Skeleton" << endl
      << "3. Giant Skeleton (boss)" << endl
      << "4. Back" << endl
      << "5. Next Page" << endl;

      int a;
      cin >> a;
      switch(a){
        case 1:
        {
          cout << "Enemy with low hp and low basic attack" << endl;
          break;
        }
        case 2:
        {
          cout << "Enemy with low hp and low basic attack. It heals sometimes." << endl;
          break;
        }
        case 3:
        {
          cout << "First boss of the game. High amount of hp and moderate attack. It heals sometimes and becomes enraged after 10 turns, doubling its attack" << endl;
          break;
        }
        case 4:
        {

          break;
        }
        case 5:
        {
          if(main_info_enems_1()) goto choose_again_enems;
          break;
        }
        default:
        {
          cout << "Choose a valid option!" << endl;
          goto choose_again_enems;
        }
      }
  return 0;
}
