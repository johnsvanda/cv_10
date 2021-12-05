#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int frequency_of_primes (int n) {
  int i,j;
    int freq=n-1;
      for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
        return freq;
        }
        

int main(){

  clock_t t;
  int f;
  t = clock();


  t = clock() - t;
  cout<<"Čas trvání "<< t <<" tiků ("<<(((float)t)/CLOCKS_PER_SEC)<<" sec.).\n";
  return 0;
}