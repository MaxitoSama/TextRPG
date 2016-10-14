#ifndef FUNCTIONS_CHARACTERS_C
#define FUNCTIONS_CHARACTERS_C

#include <iostream>

#include "functionscharacters.h"
using namespace std;


int SkillsByLevel(int level){
if (level<5) return 1;
else if (level < 10) return 2;
return 0;
}
int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int min(int a, int b){
  if(a>b) return b;
  else return a;
}
int max_aggro(int a1, int a2, int a3){
  return max(max(a1,a2),max(a1,a3));
}
int nrand(int n){
srand(time(NULL));
int a=rand()%n+1;
return a;
}

#endif
