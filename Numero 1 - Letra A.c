#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MaxNumVertices 5

typedef int TipoPeso;
typedef struct {
    TipoPeso Mat[MaxNumVertices][MaxNumVertices];
    int NumVertices;
    int NumArestas;
} TipoGrafo;

void FGVazio(TipoGrafo* Grafo) {
    int i, j;
    Grafo->NumVertices = MaxNumVertices;
    Grafo->NumArestas = 0;
    for (i = 0; i < Grafo->NumVertices; i++)
        for (j = 0; j < Grafo->NumVertices; j++)
            Grafo->Mat[i][j] = 0;
}

void InsereAresta(int V1, int V2, TipoPeso Peso, TipoGrafo* Grafo) {
    Grafo->Mat[V1][V2] = Peso;
    Grafo->Mat[V2][V1] = Peso; 
    Grafo->NumArestas++;
}

int ExisteAresta(int Vertice1, int Vertice2, TipoGrafo Grafo) {
    return Grafo.Mat[Vertice1][Vertice2] > 0;
}

int ListaAdjVazia(int Vertice, TipoGrafo Grafo) {
    int Aux, ListaVazia;
    ListaVazia = 1;
    Aux = 0;
    while ((Aux < Grafo.NumVertices) && (ListaVazia == 1)) {
        if (Grafo.Mat[Vertice][Aux] > 0) {
            ListaVazia = 0;
            return ListaVazia;
        }
        else
            Aux++;
    }
    return ListaVazia;
}

void MostraGrafo(TipoGrafo Grafo) {
    int i, j;
    for (i = 0; i < Grafo.NumVertices; i++) {
        for (j = 0; j < Grafo.NumVertices; j++) {
            printf("%d ", Grafo.Mat[i][j]);
        }
        printf("\n");
    }
}

void prim_mst(TipoGrafo Grafo) {
    int num_vertices = Grafo.NumVertices;
    int visited[num_vertices];
    int i, j, count;
	for (i = 0; i < num_vertices; i++)
        visited[i] = 0;
        
    visited[0] = 1;
    
    
    int mst[num_vertices-1][3];
    int mst_count = 0;
    
    
    char cidades[MaxNumVertices][40] = {
        "Frederico W.",
        "Seberi",
        "Tres Passos",
        "Palmeira das Missoes",
        "Santa Maria"
    };
    
    for (count = 0; count < num_vertices - 1; count++) {
        int min = INT_MAX;
        int u, v;
        
        for (i = 0; i < num_vertices; i++) {
            if (visited[i]) {
                for (j = 0; j < num_vertices; j++) {
                    if (!visited[j] && Grafo.Mat[i][j] && Grafo.Mat[i][j] < min) {
                        min = Grafo.Mat[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        visited[v] = 1;
        
        
        mst[mst_count][0] = u;
        mst[mst_count][1] = v;
        mst[mst_count][2] = min;
        mst_count++;
    }
    
    
    printf("\nmst = [\n");
    for (i = 0; i < mst_count; i++) {
        printf("(%s, %s, %d),\n", cidades[mst[i][0]], cidades[mst[i][1]], mst[i][2]);
    }
    printf("]\n");

	printf("\nmst = [\n");
    for (i = 0; i < mst_count; i++) {
        printf("(%d, %d, %d),\n", mst[i][0], mst[i][1], mst[i][2]);
    }
    printf("]\n");
}

int main() {
    TipoGrafo G;
    FGVazio(&G);
    InsereAresta(0, 1, 2, &G);
    InsereAresta(0, 3, 6, &G);
    InsereAresta(1, 2, 3, &G);
    InsereAresta(1, 3, 8, &G);
    InsereAresta(1, 4, 5, &G);
    InsereAresta(2, 4, 7, &G);
    InsereAresta(3, 4, 9, &G);
    
    MostraGrafo(G);
    
    printf("\n");
    
    prim_mst(G);

    return 0;
}

