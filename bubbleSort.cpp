#include <iostream>
using namespace std;

void listar(float v[], int n);
void inserirCresc(float v[], int &n, int max, float valor);
/*void buscaBinaria(float v[], int qtd, float valor);*/
void bobbleSort(float *v, int n);

int main(void) {

    float notas[50], nota;
    int n = 0, valor;

    do {
        cout << "Digite uma nota: ";
        cin >> nota;
        if (nota >= 0) inserirCresc(notas, n, 50, nota);
    } while (nota >= 0);

    listar(notas, n);
    
    /*
    cout << "Informe o valor a buscar: " << endl;
    cin >> valor;
    buscaBinaria(notas, n, valor);
    */
    float vetor[] = {1.4, 1.5, 1.6, 1.7, 1.3};
    n = 5;
    bobbleSort(vetor, n);
    listar(vetor, n);
}

void inserirCresc(float v[], int &n, int max, float valor) {
    int i, pos;
    
    // Verifica se há espaço na lista
    if (n == max) {
        cout << "ERRO: Lista cheia!" << endl;
        return;
    }
    
    // Encontrar posição de inserção
    i = 0;
    while (v[i]<valor && i<n) i++;
    pos = i;
    
    // Move para frente tudo que estiver após a posição
    for (i=n; i>pos; i--) v[i]=v[i-1];
    
    // Insere o elemento na posição
    v[pos] = valor;
    n++;
}

/*
void buscaBinaria(float v[], int qtd, float valor) {
	int inicial, final, mediana;
	
	inicial = 0;
	final = qtd-1;
	mediana = (inicial + final)/2;
	
	while(true) {
		if(v[mediana] == valor) {
			cout << "Posicao: " <<  mediana << endl;
			break;
		}
		else if(valor == v[final]) {
			cout << "Posição :" << final << endl;
			break;
		}
		else if (valor == v[inicial]) {
			cout << "Posição : " << inicial << endl;
			break;
		}
		else if(valor > v[mediana]) {
			inicial = mediana;
			mediana = (inicial + final)/2;
		}
		else {
			final = mediana;
			mediana = (inicial + final)/2;
		}
	}
}
*/

void listar(float v[], int n) {
    int i;
    for (i=0; i<n; i++) cout << v[i] << endl;
}

void bobbleSort(float *v, int n) {
	int i,j=1, aux;
	while(j != 0) {
		j=0;
		for(i = 0; i < n; i++) {
			if(v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				j++;
			}
		}
	}
}
