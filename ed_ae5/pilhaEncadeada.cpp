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
no * insereFim(no * inicio, int valor);
no * removeFim(no * inicio);
no * concatena(no * inicio1, no * inicio2);

int main(void) {
  no * inicio = NULL, * novo_inicio = NULL, * endereco;
  int i, valor, contador, pos, tamanho;

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


  cout << "Informe o tamanho da nova lista: ";
  cin >> tamanho;
  for(i=0; i < tamanho; i++) {
    cout << "Digite um valor a inserir no fim da lista: ";
    cin >> valor;
    if(valor < 0) break;
    novo_inicio = insereFim(novo_inicio, valor);
  }
  imprimir(novo_inicio);

  removeFim(novo_inicio);

  imprimir(novo_inicio);

  concatena(inicio, novo_inicio);

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

no * insereFim(no * inicio, int valor) {
  no * tmp, * aux;
  tmp = new no;
  tmp->valor = valor;
  tmp->ptr = NULL;

  if(inicio == NULL) inicio = tmp;
  else {
    aux = inicio;
    while(aux->ptr != NULL) {
      aux = aux->ptr;
    }
    aux->ptr = tmp;
  }

  return inicio;
}

no * removeFim(no * inicio) {
  no * tmp = inicio, * aux;

  while(tmp->ptr != NULL) {
    aux = tmp;
    tmp = tmp->ptr;
  }

  aux->ptr = NULL;
  delete tmp;

  return inicio;
}

no * concatena(no * inicio1, no * inicio2) {
  no * tmp;
  if (inicio1 == NULL) {
    inicio1 = inicio2;
  } else {
    tmp = inicio1;
    while(tmp->ptr != NULL) {
      tmp = tmp->ptr;
    }
    tmp->ptr = inicio2;
  }

  return inicio1;
}
