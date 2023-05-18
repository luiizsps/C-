#include <iostream>
using namespace std;

struct no {
  int valor;
  no * nxt;
};

struct aluno {
  int matricula;
  float media;
  aluno * nxt;
};

no * enfileirar(no * inicio, int valor);
no * desenfileirar(no * inicio, int &valor);
void imprimirFila(no * inicio);
int contador(no * inicio);

aluno * enfileirarAluno(aluno * inicio, int matricula, float media);
aluno * desenfileirarAluno(aluno * inicio, int &matricula, float &media);
void imprimirAlunos(aluno * inicio);

int main(void) {
  no * inicio = NULL;
  aluno * inicio2 = NULL;
  int i, valor, tamanho, quantidade_alunos, matricula;
  float media;

  // 1
   
  do {
    cout << "Informe um valor: ";
    cin >> valor;

    inicio = enfileirar(inicio, valor);
  } while(valor >= 0);

  inicio = desenfileirar(inicio, valor);
  if(inicio == NULL) cout << "Fila vazia" << endl;
  else cout << valor << " foi desenfileirado" << endl;

  tamanho = contador(inicio);
  cout << "A fila tem " << tamanho << " elementos" << endl;

  do {
    inicio = desenfileirar(inicio, valor);
    if(valor % 2 == 0) {
      cout << valor << " ";
    }
  } while(inicio != NULL);
  cout << endl;

  // 2

  cout << "Informe a quantidade de alunos: ";
  cin >> quantidade_alunos;
  
  for(i=1; i<=quantidade_alunos; i++) {
    cout << "Informe a matricula do aluno " << i <<": ";
    cin >> matricula;
    cout << "Informe a media do aluno " << i <<": ";
    cin >> media;

    if(matricula < 0) break;
    if(media < 0) break;

    inicio2 = enfileirarAluno(inicio2, matricula, media);
  }

  imprimirAlunos(inicio2);

  do {
    inicio2 = desenfileirarAluno(inicio2, matricula, media);
    if(media >= 5) cout << "Matricula: " << matricula << endl;
  } while(inicio2 != NULL);

  imprimirAlunos(inicio2);
}

no * enfileirar(no * inicio, int valor) {
  no * tmp, * aux;

  tmp = new no;
  tmp->valor = valor;
  tmp->nxt = NULL;

  if(inicio == NULL) inicio = tmp;
  else {
    aux = inicio;
    while(aux->nxt != NULL) {
      aux = aux->nxt;
    }
    aux->nxt = tmp;
  }

  return inicio;
}

no * desenfileirar(no * inicio, int &valor) {
  no * tmp;

  if(inicio == NULL) return NULL;
  tmp = inicio;
  valor = inicio->valor;
  inicio = inicio->nxt;

  delete tmp;

  return inicio;
}

void imprimirFila(no * inicio) {
  no * tmp;

  tmp = inicio;

  while(tmp != NULL) {
    cout << tmp->valor << endl;
    tmp = tmp->nxt;
  }

  return;
}

int contador(no * inicio) {
  no * tmp;
  int contador;

  if(inicio == NULL) return 0;
  else {
    tmp = inicio;
    contador = 0;

    while(tmp != NULL) {
      tmp = tmp->nxt;
      contador++;
    }
  }

  return contador;
}

aluno * enfileirarAluno(aluno * inicio, int matricula, float media) {
  aluno * tmp, * aux;

  tmp = new aluno;
  tmp->matricula = matricula;
  tmp->media = media;
  tmp->nxt = NULL;

  if(inicio == NULL) inicio = tmp;
  else {
    aux = inicio;
    while(aux->nxt != NULL) {
      aux = aux->nxt;
    }
    aux->nxt = tmp;
  }

  return inicio;
}

void imprimirAlunos(aluno * inicio) {
  aluno * tmp;

  tmp = inicio;

  while(tmp != NULL) {
    cout << "Matricula: " << tmp->matricula << " Media: " << tmp->media << endl;
    tmp = tmp->nxt;
  }

  return;
}

aluno * desenfileirarAluno(aluno * inicio, int &matricula, float &media) {
  aluno * tmp;

  if(inicio == NULL) return NULL;
  tmp = inicio;
  matricula = inicio->matricula;
  media = inicio->media;
  inicio = inicio->nxt;

  delete tmp;

  return inicio;
}
