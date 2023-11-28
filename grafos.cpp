#include <stdio.h>
#include <stdbool.h>
 
#define MAX_VERTICES 100
 
// Fun��o para adicionar uma aresta ao grafo
void adicionarAresta(int grafo[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    grafo[u][v] = 1;
    grafo[v][u] = 1;
}
 
// Fun��o para imprimir a colora��o do grafo
void imprimirColoracao(int cor[MAX_VERTICES], int vertices) {
    printf("Coloracao do Grafo:\n");
 
    for (int i = 0; i < vertices; ++i) {
        printf("Vertice %d esta colorido com a cor %d\n", i, cor[i]);
    }
}
 
// Fun��o para verificar se � seguro atribuir uma cor a um v�rtice
bool ehCorSegura(int grafo[MAX_VERTICES][MAX_VERTICES], int vertice, int cor[], int c, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        if (grafo[vertice][i] && cor[i] == c) {
            return false;
        }
    }
    return true;
}
 
// Fun��o principal para colorir o grafo usando o algoritmo Guloso
void colorirGrafo(int grafo[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int cor[MAX_VERTICES];
 
    for (int i = 0; i < vertices; ++i) {
        cor[i] = -1; // Inicializa todas as cores como -1 (n�o atribu�das)
    }
 
    for (int u = 0; u < vertices; ++u) {
        for (int c = 0; c < vertices; ++c) {
            if (ehCorSegura(grafo, u, cor, c, vertices)) {
                cor[u] = c;
                break;
            }
        }
    }
 
    imprimirColoracao(cor, vertices);
}
 
int main() {
    int vertices = 5;
    int grafo[MAX_VERTICES][MAX_VERTICES] = {0};
 
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 4);
 
    colorirGrafo(grafo, vertices);
 
    return 0;
}
