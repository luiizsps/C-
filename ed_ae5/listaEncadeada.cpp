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
no * busca(no * inicio, int valor);
int contaNos(no * inicio);

int main(void) {
  no * inicio = NULL, * endereco;
  int valor, contador, pos;

  while(true) {
    cout << "Informe um inteiro: ";
    cin >> valor;

    if(valor == -1) break;

    inicio = insereFrente(inicio, valor);
  }

  imprimir(inicio);

  contador = contaNos(inicio);
  
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

  
  cout << "Digite um valor a buscar: ";
  cin >> valor;
  endereco = busca(inicio, valor);

  if(endereco == NULL) cout << "Valor nao encontrado" << endl;
  else cout << "O valor " << endereco->valor << " foi encontrado." << endl;

  
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

no * busca(no * inicio, int valor) {
  no * tmp;

  tmp = inicio;

  while(tmp != NULL) {
    if(tmp->valor == valor) {
      return tmp;
    }
    tmp = tmp->ptr;
  }

  return NULL;
}

int contaNos(no * inicio) {
  no * tmp;
  int quantidade=0;

  tmp = inicio;

  while(tmp != NULL) {
    quantidade++;
    tmp = tmp->ptr;
  }

  return quantidade;
}
