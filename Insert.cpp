#include <iostream>
using namespace std;

void listar(int v[], int n);
void ordenaSelecao(int v[], int n);
void ordenaInsercao(int v[], int n);
void inserir(float v[], int &n, int max, float valor);
void bubbleSort(float v[], int n);

int main(void) {
  int menu;
	int cartas[9] = {1, 7, 8, 3, 2, 9, 6, 4, 5};
	
	listar(cartas, 9);

  cout << "Qual a forma de ordenação?\n[1] bubbleSort\n[2] seleção\n[3] insersão" << endl;
  cin << menu;

  switch(menu) {
    case 1:
    bubbleSort(cartas, 9);
    break;
    case 2:
    
  }
	ordenaInsercao(cartas, 9);
  cout << endl << "Lista ordenada: " << endl;
	listar(cartas, 9);
}

void ordenaInsercao(int v[], int n) {
  int i, j, inicial, atual, aux;
  
  for(i=0; i<n-1; i++) {
    for(j = i+1; j > 0; j--) {
      inicial = j;
      atual = j-1;

      if(v[inicial] < v[atual]) {
        aux = v[inicial];
        v[inicial] = v[atual];
        v[atual] = aux;
      }
    }
  } 
}

void ordenaSelecao(int v[], int n) {
	int i, j, aux;
	
	for (i = 0; i < n - 1; i++) {
    	for (j = i + 1; j < n; j++) {
        	if (v[i] > v[j]) {
          		aux = v[i];
          		v[i] = v[j];
          		v[j] = aux;
			}
		}
	}
}

void bubbleSort(float v[], int n) {
    int i, fim;
    bool inverteu;
    float temp;
    
	fim = n-1;
    // Repete rotina de inversões enquanto alguma inversão ocorrer
    do {
        inverteu = false;
        // Rotina de inversões
        for (i=0; i<fim; i++) {
            if (v[i]>v[i+1]) {
                temp = v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
                inverteu = true;
            }
        }
        fim--;
    } while(inverteu);
}


void inserir(float v[], int &n, int max, float valor) {
    int i;
    // Verifica se há espaço na lista
    if (n == max) {
        cout << "ERRO: Lista cheia!" << endl;
        return;
    }
    // Insere elemento
    v[n] = valor;
    n++;
}

void listar(int v[], int n) {
    int i;
    for (i=0; i<n; i++) cout << v[i] << endl;
}
