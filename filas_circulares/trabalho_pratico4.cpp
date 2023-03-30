#include <iostream>
using namespace std;

#define MAX 5

void enfileirar(int v[], int &fim, int valor, int &num);
int desenfileirar(int v[], int fim, int &inicio, int &num);
void inverterFila(int v[], int fim, int inicio, int num);
int contadorDePares(int v[], int inicio, int num);
int contadorDeImpares(int v[], int inicio, int num);


int main(void) {
  int fila[MAX], execucao = 0, valor, fim = -1, inicio = 0, num = 0, i, loop, qtdPares, qtdImpares;

  cout << "--------------- MENU ------------------" << endl;
  cout << "[1] Enfileirar um inteiro positivo" << endl;
  cout << "[2] Inverter fila" << endl;
  cout << "[3] Contar os números pares da fila" << endl;
  cout << "[4] Contar os números ímpares da fila" << endl;
  cout << "[5] Desenfileirar tudo" << endl;
  cout << "[6] Encerrar" << endl;
  cout << "---------------------------------------" << endl;
  cout << ": ";
  cin >> execucao;
  
  while(execucao != 6) {

    switch(execucao) {
      case 1:
        cout << "Informe um inteiro positivo: ";
        cin >> valor;

        enfileirar(fila, fim, valor, num);
        break;

      case 2:
        inverterFila(fila, fim, inicio, num);
        cout << "A fila foi invertida" << endl;
        break;
      
      case 3:
        qtdPares = contadorDePares(fila, inicio, num);
        cout << "A fila possui " << qtdPares << " números pares" << endl;
        break;

      case 4:
        qtdImpares = contadorDeImpares(fila, inicio, num);
        cout << "A fila possui " << qtdImpares << " números impares" << endl;
        break;
      
      case 5:
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
  int pos;
  if(num > 0) {
    pos = inicio;
    inicio++;
    if(inicio >= MAX) inicio = inicio - MAX;
    num--;
    
    return v[pos];
  }
  cout << "Fila vazia" << endl;
  return -1;
}

void inverterFila(int v[], int fim, int inicio, int num) {
  int aux, troca1, troca2;
  
  troca1 = inicio;
  troca2 = fim;
  
  while(num > 1) {
    aux = v[troca1];
    v[troca1] = v[troca2];
    v[troca2] = aux;

    troca1++;
    if (troca1 >= MAX) troca1 = troca1 - MAX;
    troca2 --;
    if (troca2 < 0) troca2 = MAX - 1;
    num -= 2;
  }
}

int contadorDePares(int v[], int inicio, int num) {
  int contador=0, pos;
  
  pos = inicio;
  
  while(num > 0) {
    if(v[pos]%2 == 0) contador++;
    
    pos++;
    if(pos >= MAX) pos = pos - MAX;
    num--;
  }
  
  return contador;
}

int contadorDeImpares(int v[], int inicio, int num) {
  int contador=0, pos;
  
  pos = inicio;
  
  while(num > 0) {
    if(v[pos]%2 != 0) contador++;
    
    pos++;
    if(pos >= MAX) pos = pos - MAX;
    num--;
  }
  
  return contador;
}
