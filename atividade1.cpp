#include <iostream>
#include <locale.h>
using namespace std;


// Protótipos
void inserir (float v[], float n, int &pos, int max);
void listar (int quantidade, float v[]);
int buscar (float v[], float n, int quantidade);
int remove(float v[], int &quantidade, float valor);


// Programa Principal
int main(void) {
	setlocale(LC_ALL, "");
    // Declaração da lista de notas
    int notas[10], valor;
    int quantidade;
    int resultado;
    // Valor a ser lido
    float n;

    // Inicializa a Lista: contém, inicialmente, zero elementos
    quantidade = 0;

    // Leitura de N dado
    do {
        cout << "Digite valor: ";
        cin >> n;
        if (n != 0) inserir (notas, n, quantidade, 10);
    } while(n != 0);
	
	listar(quantidade, notas);
	
	cout << "Qual numero deseja buscar?";
	cin >> n;
	
	resultado = buscar(notas, n, quantidade);
	if (resultado != -1) {
		cout << "O valor "<< n << " está na posição: " << resultado << "." << endl;
	}
	else {
		cout << "O valor " << n << " não foi encontrado."; 
	}
	
	cout << "Informe um valor a ser removido: ";
	cin >> valor;
	remove(notas, quantidade, valor);
	listar(quantidade, notas);
}

// Função que Insere N na posição POS da lista V
void inserir (float v[], float n, int &pos, int max) {
    if (pos >= max) cout << "ERRO: Lista cheia!" << endl;
    else {
        v[pos] = n;
        pos++;
    }
}

void listar (int quantidade, float v[]) {
	int i = 0;
	for(;i < quantidade;i++) {
		cout << v[i] << endl;
	}
}

int buscar (float v[], float n, int quantidade) {
	int i;
	
	for (i = 0; i < quantidade; i++) {
		if (v[i] == n) return i;
	}
	return -1;
}

int remove(float v[], int &quantidade, float valor) {
	int resultadoBusca;
	
	resultadoBusca = buscar(v, valor, quantidade);
	
	if (resultadoBusca == -1){
		return -1;	
	} 
	
	v[resultadoBusca] = v[quantidade-1];
	quantidade --;
	return 0;
}
