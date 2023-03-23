#include <iostream>
using namespace std;

#define MAX 5

void enfileirar(int v[], int &fim, int valor, int &num);
int desenfileirar(int v[], int fim, int &inicio, int &num);

int main(void) {
  int fila[MAX], execucao = 0, valor, fim = -1, inicio = 0, num = 0, i, loop;

  cout << "--------------- MENU ------------------" << endl;
  cout << "[1] Enfileirar um inteiro positivo" << endl;
  cout << "[2] Desenfileirar um número e imprimir seu dobro" << endl;
  cout << "[3] Desenfileirar tudo" << endl;
  cout << "[4] Encerrar o programa" << endl;
  cout << "---------------------------------------" << endl;
  cout << ": ";
  cin >> execucao;
  
  while(execucao != 4) {

    switch(execucao) {
      case 1:
        cout << "Informe um inteiro positivo: ";
        cin >> valor;

        enfileirar(fila, fim, valor, num);
        break;

      case 2:
        valor = desenfileirar(fila, fim, inicio, num);
        cout << valor*2 << endl;
        break;

      case 3:
        loop = num;
        for(i = 0; i < loop; i++) {
          valor = desenfileirar(fila, fim, inicio, num);

          cout << valor << endl;
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

void enfileirar(int v[], int &fim, int valor, int &num) {
  if(num < MAX) {
    fim++;
    if(fim == MAX) fim = fim - MAX;
    num++;
    v[fim] = valor;
    return;
  }
  cout << "Fila cheia" << endl;
  return;
}

int desenfileirar(int v[], int fim, int &inicio, int &num) {
  if(num > 0) {
    inicio++;
    if(inicio >= MAX) inicio = inicio - MAX;
    num--;
    return v[inicio-1];
  }
  cout << "Fila vazia" << endl;
  return -1;
}
