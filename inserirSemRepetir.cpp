#include <iostream>
using namespace std;

void inserirSemRepetir(int v[], int valor, int &pos, int max);
void listar(int v[], int pos);
bool pertenceALista(int v[], int valor, int &pos);

int main(void) {
  int v[50], valor, pos = 0, max = 50;

  do {
    cout << "Informe um inteiro, digite -1 para encerrar: ";
    cin >> valor;
    inserirSemRepetir(v, valor, pos, max);
  } while (valor >= 0 && pos < max);
  listar(v, pos);
}

void inserirSemRepetir(int v[], int valor, int &pos, int max) {
  if (valor >= 0 && pos < max) {
    if (!pertenceALista(v, valor, pos)) {
      v[pos] = valor;
      pos++;
    }
  }
}

bool pertenceALista(int v[], int valor, int &pos) {
  int i;

  for (i = 0; i < pos; i++) {
    if (valor == v[i]) {
      return true;
    }
  }
  return false;
}

void listar(int v[], int pos) {
  int i;

  for (i = 0; i < pos; i++) {
    cout << v[i] << endl;
  }
}
