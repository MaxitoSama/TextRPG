/*This file implements functions needed to display menus in the console. It includes:
  - A function choose_menu to show a menu on the console screen and choose an action.*/

#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"

using namespace std;

//typedef vector<string> VS;
//const int items_per_menu = 5;

  int choose_menu(string title, VS options) {
    cout << title << ':' << endl;
    int size = options.size();
    if (size == 0) {
      cout << "Error with list " << title << ": list not foud." << endl;
      return 0;
    }

    //n counts the number of pages we need to show.
    int n = (size - 1)/items_per_menu + 1;

    int option_chosen;

    if (n == 1) {
      //This is a single page menu:
      for (int i = 0; i<size; ++i) cout << i + 1 << ". " << options[i] << '.' << endl;
      cout << "Which option do you choose? : ";
      cin >> option_chosen;
      if (option_chosen<=size and option_chosen > 0) return option_chosen;
      cout << "Invalid answer. Please choose a valid answer." << endl;
      return choose_menu(title,options);
    } else {
      for (int page = 0; page < n;) {
        //Here we show a submenu:
        int i = 0;
        for (; i<items_per_menu and page * items_per_menu + i < size; ++i) cout << i+1 << ". " << options[page * items_per_menu + i] << '.' << endl;
        bool is_last_page = (page * items_per_menu + i >= size);
        int last_item = i++;
        if (page) cout << i++ << ". Previous page." << endl;
        if (!is_last_page) cout << i << ". Next page." << endl;
        cout << "last_item: " << last_item << endl;
        cout << "Which option do you choose? : ";
        cin >> option_chosen;

        if (option_chosen < 1) {
          cout << "Invalid answer. Please choose a valid answer." << endl;
          continue;
        }
        if (option_chosen <= last_item) return page * items_per_menu + option_chosen;

        if (page == 0) {
          if (option_chosen - last_item == 1) {
            ++page;
            continue;
          } else {
            cout << "Invalid answer. Please choose a valid answer." << endl;
            continue;
          }
        }

        if (option_chosen - last_item == 1) {
          --page;
        } else {
          if (!is_last_page) option_chosen--;
          if (option_chosen - last_item == 1) ++page;
          else {
            cout << "Invalid answer. Please choose a valid answer." << endl;
            continue;
          }
        }
      }
    }
    return 0;
  }
  /*
  int main() {
    VS stuff;
    stuff.push_back("Gallina1"); stuff.push_back("Gallina2"); stuff.push_back("Gallina3"); stuff.push_back("Gallina4"); stuff.push_back("Gallina5"); stuff.push_back("Gallina6"); stuff.push_back("Gallina7");
    int response = choose_menu("Les meues gallines", stuff);

    cout << "Heu triat la gallina numero " << response << '.' << endl;
  }
*/
