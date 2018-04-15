/*
* TRABALHO DE PAA 
AUTORES: FELIPE COELHO, LEONARDO PALIS
*/


#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <stdlib.h>
#include "paa_teste2.cpp"
using namespace std;

/*===================================================================
	GRAPH
====================================================================*/


int ** graph;
int lengthGraph = 0;

int minDistance(int dist[], bool isIncluded[], int lengthGraph)
{
   // Find min value
   int min = INT_MAX, smaller;
   for (int i = 0; i < lengthGraph; i++)
     
	if (isIncluded[i] == false && dist[i] <= min){
		min = dist[i];
	        smaller = i;
	}
         
 
   return smaller;
}
 
int printSolution(int dist[], int n)
{
   cout << "===============================================" << endl;
   printf("Vertice\t\tDistancia da origem\n");
   for (int i = 0; i < n; i++)
      printf("%d \t\t\t %d\n", i, dist[i]);
   cout << "===============================================" << endl << endl;
}

void inicializaDijkstra(int dist[], bool isIncluded[], int n){

     // Inicializa o vetor isInclude com false, indicando que nenhum vertice foi incluido, e odas distancias infinitas
     for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, isIncluded[i] = false;
}
 

void dijkstra(int src, int tam)
{
     int dist[tam];     // Vetor de saida com as distancias
                
     bool isIncluded[tam]; // vetor com os vertices ja inseridos (bool)
                         
     inicializaDijkstra(dist,isIncluded, tam);
 
     //Distancia do vertice inicial com ele mesmo e 0
     dist[src] = 0;
 	
     // Encontrar menor caminho
     for (int count = 0; count < tam-1; count++)
     {
       //u recebe a menor distancia 
       int u = minDistance(dist, isIncluded,tam);
      
       //sinaliza o vertice de menor distancia como visitado
       isIncluded[u] = true;
      
       for (int v = 0; v < tam; v++){
 	 
         // Muda o valoe de dist[v] apenas se ele nao foi visitado
         // encontra um outro menor caminho
         if (!isIncluded[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]){
            dist[v] = dist[u] + graph[u][v];
		
	 }

	 
	}
     }
 
     //Printa a saida
     printSolution(dist, tam);
}

/*
* Q01 - Esse metodo e responsavel por fazer a leitura da entrada e chamar a funcao dijkstra, passando como paramento
* o vertice inicial e o tamanho do grafo (numero de vertices)
*/
void Q01(){
	cout << "QUESTAO 01 - \n\n";
	int lengthGraph;
        cin >> lengthGraph;
	
	while ( lengthGraph != -1){
		graph = (int **) calloc (lengthGraph, sizeof(int *));   //aloca a memoria para o tamanho de linhas do grafo
		 
		  //aloca a memoria para o tamanho de colunas do grafo
		  for ( int i = 0; i <= lengthGraph; i++ ) {
		      graph[i] = (int*) calloc (lengthGraph, sizeof(int*));   
		
		      }

	
		for(int i = 0; i < lengthGraph; i++){
				for(int j = 0; j < lengthGraph; j++){
					cin >> graph[i][j];		//faz a leitura de cada posicao do grafo
				}
		}

	
		dijkstra(0, lengthGraph);	//chamada da funcao, com os paramentros: (vertice inicial, numero de vertices)
		cin >> lengthGraph;		//le o proximo grafo
	}


}

void Q02(){
		
	    cout << "QUESTAO 02 - \n\n";
	 /* Let us create the  graph2 given in above example */
	    int quant, ordem = 1;
	    int vertice, arestas, src,dest,weight;
	    
	    cin >> quant;
		
	    while( quant-- ){

		cin >> vertice;	
		cin >> arestas;

		struct Graph*  graph2 = createGraph(vertice, arestas);

		for(int i = 0; i < arestas; i++){
			 cin >> src;
		 	 cin >> dest;
			 cin >> weight;

			 graph2->edge[i].src = src;
			 graph2->edge[i].dest = dest;
			 graph2->edge[i].weight = weight;
	 
		}
		BellmanFord( graph2, 0, ordem, 0);
		ordem++;

	    }
	   
}

void Q03(){
		
	    cout << "QUESTAO 03 - \n\n";
	  
	    int quant, ordem = 1; // quant -> quantidade de grafos a serem lidos  ordem -> numero do grafo corrente

	    int vertice, arestas, src,dest,weight;
	    
	    cin >> quant;	
		
	    while( quant-- ){

		cin >> vertice;	
		cin >> arestas;

		struct Graph*  graph2 = createGraph(vertice, arestas);	//aloca a memoria para o grafo a ser criado

		for(int i = 0; i < arestas; i++){
			 cin >> src;
		 	 cin >> dest;
			 cin >> weight;

			 graph2->edge[i].src = src;
			 graph2->edge[i].dest = dest;
			 graph2->edge[i].weight = weight;
	 
		}
		BellmanFord( graph2, 0, ordem, 1);
		ordem++;

	    }
	   
}

/*
*FUNCAO PRINCIPAL
*/
int main()
{
	
        
        cout << "THIS PROGRAM WAS DEVELOPED BY FELIPE COELHO AND LEONARDO PALIS.\nPROJETO E ANALISE DE ALGORITMOS - TP1\n\n";
    
	//Q01();  //questao 1

	//Q02();  //questao 2
	
	Q03();  //questao 3
        return 0;
}

