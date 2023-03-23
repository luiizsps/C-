#include <iostream>
using namespace std;

#define MAX 15

void enfileirar(int v[], int &fim, int valor);
int desenfileirar(int v[], int fim, int &inicio);

int main(void) {
  int fila[MAX], execucao = 0, valor, fim = -1, inicio = 0;

  cout << "--------------- MENU ------------------" << endl;
  cout << "[1] Enfileirar um inteiro positivo" << endl;
  cout << "[2] Desenfileirar tudo e imprimir os multiplos de 5" << endl;
  cout << "[3] Encerrar o programa" << endl;
  cout << "---------------------------------------" << endl;
  cout << ": ";
  cin >> execucao;
  
  while(execucao != 3) {

    switch(execucao) {
      case 1:
      cout << "Informe um inteiro positivo: ";
      cin >> valor;

      enfileirar(fila, fim, valor);
      break;

      case 2:
      while(inicio <= fim) {
        valor = desenfileirar(fila, fim, inicio);

        if(valor % 5 == 0) cout << valor << endl;
      }
      break;

      default:
      cout << "Operação inválida." << endl;
      break;
    }

    cout << "O que deseja fazer agora?" << endl << ": ";
    cin >> execucao;
  }
}

void enfileirar(int v[], int &fim, int valor) {
  if(fim < (MAX - 1)) {
    fim++;
    v[fim] = valor;
    return;
  }
  cout << "Fila cheia" << endl;
  return;
}

int desenfileirar(int v[], int fim, int &inicio) {
  if(inicio <= fim) {
    inicio++;
    return v[inicio-1];
  }
  cout << "Fila vazia" << endl;
  return -1;
}
