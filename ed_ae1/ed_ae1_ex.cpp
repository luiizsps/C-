#include <iostream>
using namespace std;

void inserirSemRepetir(int v[], int valor, int &pos, int max);
bool pertenceALista(int v[], int valor, int pos);
void listar(int v[], int pos);
int intercalaElementos(int v[], int v2[], int vetor, int &pos, int &pos2,
                       int &contador);
int intersecElementos(int inter[], int intersec[], int pos, int i,
                      int &contador);
void uniao(int *vetorUniao, int contador);
void removerPeloIndicie(int *v, int contador, int pos);

int main(void) {
  int v[10], v2[10], inter[20], vetorUniao[20], intersec[10], ordenada[20],
      valor, pos = 0, posv, pos2 = 0, tamanhoTotal, valorAnterior, pos2v,
             max = 10, i, contador = 0, contador2 = 0, contador3 = 0, aux, aux2;

  do {
    cout << "Primeiro vetor - Informe um inteiro, digite -1 para encerrar: ";
    cin >> valor;
    inserirSemRepetir(v, valor, pos, max);
  } while (valor >= 0 && pos < max);

  do {
    cout << "Segundo vetor - Informe um inteiro, digite -1 para encerrar: ";
    cin >> valor;
    inserirSemRepetir(v2, valor, pos2, max);
  } while (valor >= 0 && pos2 < max);

  cout << "Lista 1: " << endl;
  listar(v, pos);
  cout << "Lista 2: " << endl;
  listar(v2, pos2);

  tamanhoTotal = pos + pos2;
  posv = pos;
  pos2v = pos2;

  for (i = 0; i < tamanhoTotal; i++) {
    aux = intercalaElementos(v, v2, i, posv, pos2v, contador);
    inter[i] = aux;
    vetorUniao[i] = aux;
  }
  posv = i;
  cout << "Lista intercalada: " << endl;
  listar(inter, posv);

  for (i = 0; i < posv; i++) {
    aux = intersecElementos(inter, intersec, posv, i, contador2);
    if (aux != -1) {
      intersec[contador2] = aux;
      contador2++;
    }
  }

  if (contador2 == 0) {
    cout << "Sem intersecções." << endl;
  } else {
    cout << "Lista de intersecções: " << endl;
    listar(intersec, contador2);
  }
  contador3 = posv - contador2;
  cout << "Lista união: " << endl;
  uniao(vetorUniao, posv);
  listar(vetorUniao, contador3);

  cout<< "Informe o indície do vetor a ser removida: " << endl;
  cin >> pos;
  if (pos < 0 || pos > contador3 - 1) {
    cout << "O índicie informado é inválido." << endl;
  } else {
    removerPeloIndicie(vetorUniao, contador3, pos);
    cout << "Nova lista: " << endl;
    listar(vetorUniao, contador3-1);
  }
}

void inserirSemRepetir(int v[], int valor, int &pos, int max) {
  if (valor >= 0 && pos < max) {
    if (!pertenceALista(v, valor, pos)) {
      v[pos] = valor;
      pos++;
    }
  }
}

bool pertenceALista(int v[], int valor, int pos) {
  int i;

  for (i = 0; i < pos; i++) {
    if (valor == v[i]) {
      return true;
    }
  }
  return false;
}

void listar(int v[], int pos) {
  int i;

  for (i = 0; i < pos; i++) {
    cout << v[i] << endl;
  }
}

int intercalaElementos(int v[], int v2[], int i, int &pos, int &pos2,
                       int &contador) {
  if (pos == 0) {
    pos2--;
    contador++;
    return v2[contador - 1];
  } else if (pos2 == 0) {
    pos--;
    contador++;
    return v[contador - 1];
  } else {
    if (i % 2 == 0) {
      pos--;
      return v[contador];
    } else {
      pos2--;
      contador++;
      return v2[contador - 1];
    }
  }
}

int intersecElementos(int inter[], int intersec[], int pos, int i,
                      int &contador2) {
  int j;

  for (j = 0; j < pos; j++) {
    if (j != i) {
      if (inter[j] == inter[i]) {
        if (!pertenceALista(intersec, inter[i], contador2)) {
          return inter[i];
        }
      }
    }
  }
  return -1;
}

void uniao(int *vetorUniao, int contador) {
  int i, j, aux, vetorAux[20];

  for (i = 0; i < contador - 1; i++) {
    for (j = i + 1; j < contador; j++) {
      if (!pertenceALista(vetorAux, vetorUniao[j], i)) {
        if (vetorUniao[i] > vetorUniao[j]) {
          aux = vetorUniao[i];
          vetorUniao[i] = vetorUniao[j];
          vetorUniao[j] = aux;
        }
      } else {
        aux = vetorUniao[j];
        vetorUniao[j] = vetorUniao[contador - 1];
        vetorUniao[contador - 1] = aux;
        contador--;
      }
      vetorAux[i] = vetorUniao[i];
    }
  }
}

void removerPeloIndicie(int *v, int contador, int pos) {
  int i, j=0, vetorAux[19];
  for(i=0; i < contador; i++) {
    if(i != pos) {
      vetorAux[j] = v[i];
      j++;
    }
  }

  for(i=0; i<contador-1; i++) {
    v[i] = vetorAux[i];
  }
}
