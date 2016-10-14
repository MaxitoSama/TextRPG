#ifndef UTILS
#define UTILS

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> VS;
const int items_per_menu = 5;

int choose_menu(string title, VS options);

#endif
