#include <iostream>
using namespace std;

struct no {
  int valor;
  no *ptr;
};

void inserirFila(no *inicio, no *fim, int valor);

int main(void) {
  no *inicio = NULL, *fim = NULL;
  int valor=1;

  while (valor > 0) {
    cout << "Informe um inteiro: ";
    cin >> valor;

    inserirFila(inicio, fim, valor);
  }
}

void inserirFila(no *inicio, no *fim, int valor) {
  no *tmp;
  tmp->valor = valor;
  tmp->ptr = NULL;

  if (inicio == NULL) {
    inicio = tmp;
    fim = inicio;
  } else {
    fim->ptr = tmp;
    fim = tmp;
  }
}

void imprimirFila(no * inicio) {
  no * tmp;
  tmp = inicio;
  while(tmp != NULL) {
    cout << tmp->valor << " ";
    tmp = tmp->ptr;
  }
}
