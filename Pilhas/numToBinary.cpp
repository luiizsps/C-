#include <iostream>
using namespace std;

void addPilha(int v[], int &topo, int valor);
void imprimePilha(int v[], int topo);
void numToBinary(int v[], int &topo, int valor);

int main(void) {
  int v[20], valor, topo = -1, n;
  n = 20;

  cout << "Informe um inteiro: ";
  cin >> valor;
  if(topo < (n-1)) {
      numToBinary(v, topo, valor);
  }
  imprimePilha(v, topo);
}
void addPilha(int v[], int &topo, int valor) {
  topo++;  
  v[topo] = valor;
}

void numToBinary(int v[], int &topo, int valor) {
  do {
    addPilha(v, topo, valor % 2);
    valor /= 2;
  } while(valor > 0);
}

void imprimePilha(int v[], int topo) {
  for(; topo >= 0; topo--) {
    cout << v[topo];
  }
}
