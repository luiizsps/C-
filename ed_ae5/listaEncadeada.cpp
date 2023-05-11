#include <iostream>
using namespace std;

struct no {
  int valor;
  no * ptr;
};

no * insereFrente(no * inicio, int valor);
void imprimir(no * inicio);
void substituir(no * inicio, int valor, int novoValor);
no * removerInicio(no * inicio);

int main(void) {
  no * inicio = NULL;
  int valor, contador=0, pos;

  while(true) {
    cout << "Informe um inteiro: ";
    cin >> valor;

    if(valor == -1) break;

    inicio = insereFrente(inicio, valor);
    contador++;
  }

  imprimir(inicio);

  cout << "Informe a posicao do no a ser alterado: ";
  cin >> pos;
  if(pos < 1 || pos > contador) {
    cout << "Posicao invalida";
  } else {
    cout << "Informe o valor: ";
    cin >> valor;

    substituir(inicio, pos, valor);
  }

  imprimir(inicio);

  if(inicio == NULL) {
    cout << "Lista vazia" << endl;
  } else {
    inicio = removerInicio(inicio);
  }

  imprimir(inicio);
}

no * insereFrente(no * inicio, int valor) {
  no * tmp;
  tmp = new no;
  tmp->valor = valor;
  tmp->ptr = NULL;

  if(inicio == NULL) {
    inicio = tmp;
  } else {
    tmp->ptr = inicio;
    inicio = tmp;
  }

  return inicio;
}

void imprimir(no * inicio) {
  no * tmp;
  tmp = inicio;

  while(tmp != NULL) {
    cout << tmp->valor << endl;
    tmp = tmp->ptr;
  }
}

void substituir(no * inicio, int valor, int novoValor) {
  if(inicio == NULL) return;

  no * tmp = inicio;

  for(int i=1; i < valor; i++) {
    tmp = tmp->ptr;
  }

  tmp->valor = novoValor;
}

no * removerInicio(no * inicio) {
  no * tmp;

  tmp = inicio;
  inicio = tmp->ptr;

  delete tmp;

  return inicio; 
}
