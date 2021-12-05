#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Element {
    string data;
    Element *next;
};

typedef Element *elPointer;

void push(elPointer &top, string data) {
    if( top == NULL) {
        top = new Element;
        top->data = data;
        top->next = NULL;
    }
    else {
        elPointer pom = top;
        top = new Element;
        top->data = data;
        top->next = pom;
    }
}


void Hledej(elPointer &top, string fileName) {
    string co;
    ifstream Soub(fileName.c_str());
    while (top->data != co and top->next != NULL) {
        top = top->next;
        Soub >> co; //přečtení hledané hodnoty
    }
    Soub.close();
}

void Napln(elPointer &top, int pocdat) {
    string x;
    for (int i = 1; i <= pocdat; i++) {
        cin >> x;
        push(top, x);

    }
}

void vemPar(int &mnozstvi, string &zdroj, int pocetParam, char* param[]) {
    mnozstvi = 1;
    zdroj ="";
    if (pocetParam > 1) mnozstvi = strtol(param[1], NULL, 10);
    if (pocetParam > 2) zdroj.append(param[2]);
}



int main(int pocetParam, char *param[]) {
    elPointer zasobnik;
    clock_t t;
    int mnozstvi;
    string zdrojDat;
    vemPar(mnozstvi, zdrojDat, pocetParam, param);
    zasobnik = NULL;
    Napln(zasobnik, mnozstvi);
    t = clock();
    for (int i=0; i< 20000; i++)
        Hledej(zasobnik, zdrojDat);
    t = clock() - t;
    cout <<"Hodnot v zásobníku: " << mnozstvi <<"; čas trvání "<< t <<" tiků("<<(((float) t) / CLOCKS_PER_SEC) <<" sec.)."<<endl;

    return 0;
}