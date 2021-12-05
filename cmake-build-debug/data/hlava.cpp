#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool TestSoub(string Jmeno){
  ifstream temp;
  temp.open(Jmeno.c_str(), ios::binary);
  if (temp.is_open()){
     temp.close();
     return true;
  } else return false;
}

bool JeJmeno(string &pom, int pocet, char *param[]){
  bool vysled=false;
  if (pocet>1) {
    pom=""; pom.append(param[1]);
    if (TestSoub(pom)) vysled=true; 
  }
  if (not vysled) {
    char *XX = getenv("ZDROJ");
    pom=""; if (strlen(XX)>0) pom.append(XX); 
    if (TestSoub(pom)) vysled=true;
  }
  return vysled;
}

int main(int pocpar, char *par[]){
  string jmeno;
  if (JeJmeno(jmeno, pocpar, par)) {
     char X;
     ifstream data (jmeno.c_str(), ios::binary);
     for (int i=1; i<=10; i++){
       data.get(X);
       cout << int(X) << " ";
     }
     cout << endl;
     return 0;
  } else {cerr << "Nenalezen vstupní soubor."<<endl;
     return 4;
  }
}