#include <iostream>
using namespace std;

void listar(int v[], int n);
void ordenaSelecao(int v[], int n);
/*void inserir(float v[], int &n, int max, float valor);
void bubbleSort(float v[], int n);*/

int main(void) {

	int cartas[9] = {1, 7, 8, 3, 2, 9, 6, 4, 5};
	
	listar(cartas, 9);
	ordenaSelecao(cartas, 9);
  cout << endl << "Lista ordenada: " << endl;
	listar(cartas, 9);
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
/*
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
*/
void listar(int v[], int n) {
    int i;
    for (i=0; i<n; i++) cout << v[i] << endl;
}
