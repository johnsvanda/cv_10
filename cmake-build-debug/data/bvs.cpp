#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct TypUzel {
   string data;
   TypUzel *Vlevo, *Vpravo;
};
typedef TypUzel * UkUzel;

void Vloz(UkUzel &S, string d){
  if (S==NULL){
    S = new TypUzel;
    S->data = d;
    S->Vlevo=NULL;
    S->Vpravo=NULL;
  } else if (d<S->data) Vloz(S->Vlevo, d);
     else Vloz(S->Vpravo, d);
}

bool Zjisti(UkUzel S, string co){
  UkUzel pom=S;
  while (pom!=NULL and pom->data!=co)
    if (co<S->data) pom=pom->Vlevo;
      else pom=pom->Vpravo;
  return pom!=NULL;
}

void Napln(UkUzel &S, int pocdat){
  string x;
  for (int i=1; i<=pocdat; i++){
    cin>>x;
    Vloz(S, x);
  }
}

void Hledej(UkUzel S, string odkud){
  string x; bool b; 
  ifstream Soub;
  Soub.open (odkud.c_str());
  for (int i=1; i<=120000; i++){
    Soub >> x;
    b=Zjisti(S, x);
  }  
  Soub.close();
}

void inorder(UkUzel S){
  if (S!=NULL) {
    inorder(S->Vlevo);
    cout << S->data<<endl;
    inorder(S->Vpravo);
  }  
}

int Hladina=0, MaxHladina=0;
void Hladin(UkUzel S){
  if (S!=NULL){
    Hladina++;
    if (Hladina>MaxHladina) MaxHladina = Hladina;
    Hladin(S->Vlevo);
    Hladin(S->Vpravo);
    Hladina--;
  }
}

void VemPar(int &mnozstvi, string &zdroj, int p, char *par[]){
  mnozstvi=1;
  zdroj="";
  if (p>1) mnozstvi=strtol(par[1], NULL, 10);
  if (p>2) zdroj.append(par[2]);
}

int main(int pocet, char *param[]){
  UkUzel strom;
  clock_t t;
  int kolik; 
  string hled_retezce;
  VemPar(kolik, hled_retezce, pocet, param);
  strom=NULL;
  cerr << "Čtení..."<<endl;
  Napln(strom, kolik);
  cerr << "Vloženo. Hledání..."<<endl;
  t = clock();
  Hledej(strom, hled_retezce);
  t = clock() - t;
  Hladin(strom);
  cout<<"Hladin stromu: "<<MaxHladina<<"; hodnot ve stromu: "
      <<kolik<<"; čas trvání "<< t <<" tiků ("
      <<(((float)t)/CLOCKS_PER_SEC)<<" sec.)."<<endl;
//  inorder(strom);
  return 0;
}