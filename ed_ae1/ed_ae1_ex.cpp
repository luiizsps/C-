#include <iostream>
using namespace std;

void inserirSemRepetir(int v[], int valor, int &pos, int max);
bool pertenceALista(int v[], int valor, int &pos);
void listar(int v[], int pos);

int main(void) {
  int v[10], v2[10], valor, pos = 0, pos2 = 0, max = 10, i=0;

   do {
    cout << "Primeiro vetor - Informe um inteiro, digite -1 para encerrar: ";
    cin >> valor;
    inserirSemRepetir(v, valor, pos, max);
  } while (valor >= 0 && pos < max);

  do {
    cout << "Segundo vetor - Informe um inteiro, digite -1 para encerrar: ";
    cin >> valor;
    inserirSemRepetir(v2, valor, pos2, max);
  } while (valor >= 0 && pos2 < max);

  listar(v, pos);
  listar(v2, pos2);
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

int intercalaElementos (int v[], int v2[], int &vetor, int &contador) {
  if(vetor%2 == 0) {
    return v[contador];
  } else {
    return v2[contador];
    contador++;
  }
}
