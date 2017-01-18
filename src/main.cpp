#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"

using namespace std;

int main_info();
int main_game(int lvl, int char1, int char2, int char3, int xp);
void aboutinfo();

void aboutinfo(){
  cout << "*************************************" << endl;
  cout << "*  Created by and idea of Katakras  *" << endl;
  cout << "*          Version 0.2              *" << endl;
  cout << "*           July 2016               *" << endl;
  cout << "*************************************" << endl;
}


int main(){

  typeagain_intro:
  cout << "*----------------*" << endl;
  cout  << "MAIN MENU" << endl << endl
        << "1. New Game" << endl
        << "2. Load Game" << endl
        << "3. Info" << endl
        << "4. About" << endl
        << "5. Exit" << endl;
        cout << "*----------------*" << endl;
  int c;
  typeagain:

  cin >> c;
  switch(c){
      case 1:
      {
        main_game(1,0,0,0,0);
        goto typeagain_intro;
        break;
      }
      case 2:
      {
        insertsaveagain:
        int checker_save1; int checker_save2; int lv; int h1; int h2; int h3; int xp;
        ifstream a_file("save.txt");
        a_file >> checker_save1;
        if(checker_save1 != 12346590){
          cout << "Insert a valid save.txt file. Press ENTER to load again." << endl;
          cin.get();
          cin.get();
          goto insertsaveagain;
        }
        a_file >> lv >> h1 >> h2 >> h3 >> xp >> checker_save2;
        if(checker_save2 != h1+h2+h3-lv){
          cout << "Insert a valid save.txt file. Press ENTER to load again." << endl;
          cin.get();
          cin.get();
          goto insertsaveagain;
        }
        a_file.close();
        main_game(lv,h1,h2,h3,xp);
        goto typeagain_intro;
        break;
      }
      case 3:
      {
        main_info();
        goto typeagain_intro;
        break;
      }
      case 4:
      {
        aboutinfo();
        goto typeagain_intro;
      }
      case 5:
      {
        break;
      }
      default:
        cout << "Insert a valid option" << endl;
        goto typeagain;
        break;
  }

return 0;
}
