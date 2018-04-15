/*
* TRABALHO DE PAA 
AUTORES: FELIPE COELHO, LEONARDO PALIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
 
using namespace std;
//ESTRUTURA QUE REPRESENTA UMA ARESTA COM PESO
struct Edge
{
    int src, dest, weight;
};
 
//ESTRUTURA QUE REPRESENTA UM GRAFO CONEXO SIMPLES E COM PESO
struct Graph
{
    // V->NUMERO DE VERTICESs, E->NUMERO DE ARESTAS
    int V, E; 
    
    struct Edge* edge;
};
 
// ALOCACAO DO GRAFO COM V VERTICES E "E" ARESTAS
struct Graph* createGraph(int V, int E)
{
    struct Graph*  graph2 = (struct Graph*) malloc( sizeof(struct Graph) );
     graph2->V = V;
     graph2->E = E;
     graph2->edge = (struct Edge*) malloc(  graph2->E * sizeof( struct Edge ) );
 
    return  graph2;
}
 
// PRINTA A SOLUCAO
void printArr(int dist[], int n, int ordem)
{
    cout << "===============================================" << endl;
    cout << "GRAFO " << ordem << ":" << endl;
    printf("Vertice \t\t Distancia da origem\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    cout << "===============================================" << endl << endl;
}
 
// ENCONTRA O MENOR CAMINHO DO SOURCE ATE O OS VERTICES
// TAMBEM DETERMINA CICLOS NEGATIVOS
void BellmanFord(struct Graph*  graph2, int src, int ordem, int FLAG)
{
    int V =  graph2->V;
    int E =  graph2->E;
    int dist[V];
 
    // Inicializa as distancias do source ate cada vertice como infinito
    for (int i = 0; i < V; i++){
	dist[i]   = INT_MAX;
    }
    dist[src] = 0;
 
    //ALGORITMO DE RELAXAMENTO
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u =  graph2->edge[j].src;
            int v =  graph2->edge[j].dest;
            int weight =  graph2->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // VERIFICA CICLOS NEGATIVOS

    for (int i = 0; i < E; i++)
    {
        int u =  graph2->edge[i].src;
        int v =  graph2->edge[i].dest;
        int weight =  graph2->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
		cout << "===============================================" << endl; 
	        cout << "GRAFO " << ordem << ":" << endl;
		printf("O grafo possui ciclo negativo\n");
		cout << "===============================================" << endl << endl;
		FLAG = 0;
	}
	
            
    }
 
    if(FLAG) printArr(dist, V, ordem);
 
    return;
}
 
