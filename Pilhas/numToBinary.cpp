#include <iostream>
using namespace std;

void addPilha(int v[], int &topo, int valor, int n);
void imprimePilha(int v[], int topo);
void numToBinary(int v[], int &topo, int valor, int n);

int main(void) {
  int v[20], valor, topo = -1, n;
  n = 20;

  cout << "Informe um inteiro: ";
  cin >> valor;
  if(topo < (n-1)) {
      numToBinary(v, topo, valor, n);
  }
  imprimePilha(v, topo);
}
void addPilha(int v[], int &topo, int valor, int n) {
  if(topo < (n-1)) {
    topo++;  
    v[topo] = valor;
  } else {
   cout << "Lista cheia." << endl;
    return;
  }
}

void numToBinary(int v[], int &topo, int valor, int n) {
  do {
    addPilha(v, topo, valor % 2, n);
    valor /= 2;
  } while(valor > 0);
}

void imprimePilha(int v[], int topo) {
  for(; topo >= 0; topo--) {
    cout << v[topo];
  }
}
