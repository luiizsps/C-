#include <iostream>
using namespace std;

#define MAX 5

void enfileirar(int fila[], int num, int &fim);
void enfileirarCircular(int fila[], int num, int &fim, int &quantidade);

void desenfileirar(int fila[], int &inicio);
void desenfileirarCircular(int fila[], int &inicio, int &quantidade);

void imprimeFila(int fila[], int fim, int inicio);
void imprimeFilaCircular(int fila[], int fim, int inicio, int quantidade);

int main(void) {
	int fila[MAX], num, fim, inicio, quantidade;

	quantidade = 0;
	fim = -1;
	inicio = 0;

	while(true) {
		cout << "Informe um numero: ";
		cin >> num;

		if(num == -1) break;

		enfileirarCircular(fila, num, fim, quantidade);
	}
	imprimeFilaCircular(fila, fim, inicio, quantidade);
}

void enfileirar(int fila[], int num, int &fim) {

	if(fim >= MAX -1) return;

	fim++;
	fila[fim] = num;
}

void desenfileirar(int fila[], int &inicio) {
	
	if(inicio < MAX) inicio++;
	return;
}

void imprimeFila(int fila[], int fim, int inicio) {
	int i;

	for (i=inicio; i <= fim; i++) {
		if(i==inicio) cout << "[" << fila[i];
		else cout << ", " << fila[i];
		if(i==fim) cout << "]" << endl;
	}
}

void enfileirarCircular(int fila[], int num, int &fim, int &quantidade) {
	
	fim++;

	if(quantidade >= MAX) return;
	if(fim == MAX) fim = 0;

	fila[fim] = num;
	quantidade++;
}

void desenfileirarCircular(int fila[], int &inicio, int &quantidade) {

	if(quantidade <= 0) return;
	
	inicio++;
	if(inicio == MAX) inicio = 0;
	
	quantidade--;
}

void imprimeFilaCircular(int fila[], int inicio, int fim, int quantidade) {

	for(;quantidade>0; quantidade--) {
		cout << fila[inicio] << " ";
		inicio++;
		if(inicio == MAX) inicio = 0;	
	}
}
