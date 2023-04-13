#include <iostream>
#include <string>
using namespace std;

#define MAX 20

void inserirElemento(int lista[], int num, int &quantidade);
void removerElemento(int lista[], int num, int &quantidade);
int buscaBinaria(int lista[], int num, int quantidade);
void imprimirLista(int lista[], int quantidade);

// Vamos partir do principio que a lista esta organizada,
// e adicionaremos elementos mantendo ela organizada de forma crescente
int main(void) {
  int quantidade = 0, num, lista[MAX], execucao = 0, pos;

  while (execucao != 5) {
    cout << "--------------- MENU ------------------" << endl;
    cout << "| [1] Adicionar um inteiro positivo   |" << endl;
    cout << "| [2] Imprimir lista                  |" << endl;
    cout << "| [3] Busca binaria                   |" << endl;
    cout << "| [4] Remover inteiro                 |" << endl;
    cout << "| [5] Encerrar execucao               |" << endl;
    cout << "---------------------------------------" << endl;
    cout << ": ";
    cin >> execucao;

	switch (execucao) {
		case 1:
			cout << "Informe um numero inteiro positivo: ";
			cin >> num;
			if (num >= 0 && quantidade < MAX)
			inserirElemento(lista, num, quantidade);
			break;

		case 2:
			imprimirLista(lista, quantidade);
			break;

		case 3:
			cout << "Informe o numero a ser buscado: ";
			cin >> num;
			pos = buscaBinaria(lista, num, quantidade);
			if(pos == -1)
				cout << "O numero informado nao se encontra na lista" << endl;
			else
				cout << "O numero informado se encontra na posicao: " << pos << endl;
			break;

		case 4:
			cout << "Informe o numero a ser removido: ";
			cin >> num;
			removerElemento(lista, num, quantidade);
    }
  }
}

void inserirElemento(int lista[], int num, int &quantidade) {
  int i, j;
  for (i = 0; i < quantidade; i++) {
    if (lista[i] > num) {
      for (j = quantidade; j > i; j--) {
        lista[j] = lista[j - 1];
      }
      lista[i] = num;
      quantidade++;
      return;
    }
  }
  lista[i] = num;
  quantidade++;
}

void imprimirLista(int lista[], int quantidade) {
  int i;
  for (i = 0; i < quantidade; i++) {
    if (i == 0) {
      cout << "[" << lista[i];
    } else {
      cout << ", " << lista[i];
    }
    if (i == quantidade -1) cout << "]" << endl;
  }
}

int buscaBinaria(int lista[], int num, int quantidade) {
	int mediana, inicio, fim, pos, loop;

	inicio = 0;
	fim = quantidade - 1;
	mediana = fim/2;
	
	while(loop != 1) {
		if(fim == inicio) loop = 1;
		if(num > lista[mediana]) {
			inicio = mediana+1;
			mediana = (inicio+fim)/2;
		}
		else if(num < lista[mediana]) {
			fim = mediana-1;
			mediana = (inicio+fim)/2;
		}
		else if(num == lista[mediana]) {
			return mediana;
		}
	}
	return -1;
}

void removerElemento(int lista[], int num, int &quantidade) {
	int pos, i;
	
	pos = buscaBinaria(lista, num, quantidade);

	for(i=pos; i < quantidade; i++) {
		lista[i] = lista[i+1];
	}
	quantidade--;
}
