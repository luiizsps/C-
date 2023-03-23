#include <iostream>
using namespace std;

#define MAX 15

void enfileirar(char v[], int &fim, char valor);
char desenfileirar(char v[], int fim, int &inicio);
void empilhar(char v[], int &topo, char valor);
char desempilhar(char v[], int &topo);
void verificaAlfabeto(char &valor);

int main(void) {
  int fim, inicio, topo, i;
  char fila[MAX], pilha[MAX], valor;

  fim = -1;
  inicio = 0;
  topo = -1;
  
  for(i=0; i<MAX; i++) {
    
    cout<<"Informe um caracter: ";
    cin >> valor;

    // caso o usuário digite '/', a inserção encerra.
    if(valor == '/') break;
    
    enfileirar(fila, fim, valor);
  }

  while(inicio <= fim) {
    valor = desenfileirar(fila, fim, inicio);

    if (valor == '/') break;

    // verifica se o caracter pertence ao alfabeto.
    verificaAlfabeto(valor);

    empilhar(pilha, topo, valor);
  }

  while(topo >= 0) {
    valor = desempilhar(pilha, topo);

    if (valor == '/') break;
  
    // a saída deve ser o inverso da entrada
    cout << valor;
  }
}

void enfileirar(char v[], int &fim, char valor) {
  if(fim < (MAX - 1)) {
    fim++;
    v[fim] = valor;
    return;
  }
  cout << "Fila cheia" << endl;
  return;
}

char desenfileirar(char v[], int fim, int &inicio) {
  if(inicio <= fim) {
    inicio++;
    return v[inicio-1];
  }
  cout << "Fila vazia" << endl;
  return '/';
}

void empilhar(char v[], int &topo, char valor) {
  if(topo < MAX - 1) {
    topo++;
    v[topo] = valor;
    return;
  }
  cout << "Erro! Pilha cheia." << endl;
  return;
}

char desempilhar(char v[], int &topo) {
  if(topo >= 0) {
    return v[topo--];
  }
  cout << "Pilha vazia" << endl;
  return '/';
}

void verificaAlfabeto(char &valor) {
  switch(valor) {
    case 'a':
    valor = 'A';
    break;
  
    case 'b':
    valor = 'B';
    break;
  
    case 'c':
    valor = 'C';
    break;
  
    case 'd':
    valor = 'D';
    break;
  
    case 'e':
    valor = 'E';
    break;
  
    case 'f':
    valor = 'F';
    break;
  
    case 'g':
    valor = 'G';
    break;
  
    case 'h':
    valor = 'H';
    break;
  
    case 'i':
    valor = 'I';
    break;
  
    case 'j':
    valor = 'J';
    break;
  
    case 'k':
    valor = 'K';
    break;
  
    case 'l':
    valor = 'L';
    break;
  
    case 'm':
    valor = 'M';
    break;
  
    case 'n':
    valor = 'N';
    break;
  
    case 'o':
    valor = 'O';
    break;
  
    case 'p':
    valor = 'P';
    break;
  
    case 'q':
    valor = 'Q';
    break;
  
    case 'r':
    valor = 'R';
    break;
  
    case 's':
    valor = 'S';
    break;
  
    case 't':
    valor = 'T';
    break;
  
    case 'u':
    valor = 'U';
    break;
  
    case 'v':
    valor = 'V';
    break;
  
    case 'w':
    valor = 'W';
    break;
  
    case 'x':
    valor = 'X';
    break;
  
    case 'y':
    valor = 'Y';
    break;
  
    case 'z':
    valor = 'Z';
    break;

    default:
    break;
  }
}
