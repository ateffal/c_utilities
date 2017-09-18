#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "D:\shared\a.teffal\Mes documents\Documents Personnels\Coursera\Algorithms Design and Analysis\Sort.cpp"
#include "D:\shared\a.teffal\Mes documents\Documents Personnels\c_utilities-master\read_csv.c"
#include "D:\shared\a.teffal\Mes documents\Documents Personnels\Coursera\Algorithms Design and Analysis\Sort.cpp"


typedef struct vertex Vertex;


struct vertex { 
	int label;
	long int cost;
	Vertex* next;
} ;


typedef struct Edge {
	int label;
	Vertex *start;
	Vertex *end;
	long int cost;
} Edge;



int main(int argc, char* argv[]) {

	const char* infile = "edges.txt";
	
	CSV_File *csvf1;
	
	csvf1=read_csv_0(infile);
	
	int i;
	
	
//	printf("Entête = %s\n",csvf1->header);
//	for(i=0;i<10;i++) {
//		printf("Ligne %d : ",i);
//		printf("%s\n",csvf1->data[i]);
//	}
	
	// The first line contains the number of verticies and the number of edges
	//separated by a space
	int n,m;
	char *token;
	token = strtok(csvf1->header," ");
	n= atoi(token);
	token = strtok(NULL," ");
	m = atoi(token);
	
	//printf("n = %d\n",n);
	//printf("m = %d\n",m);
	int vertex_added[n];
	int edge_added[m];
	
	for(i=0;i<n;i++) {
		vertex_added[i] = 0;
	}
	
	for(i=0;i<m;i++) {
		edge_added[i] = 0;
	}
	
	//storing the edges of the graphe
	Edge edges[m];
	for(i=0;i<m;i++) {
		edges[i].label=i;
		token = strtok(csvf1->data[i]," ");
		edges[i].start=atoi(token);
		token = strtok(NULL," ");
		edges[i].end=atoi(token);
		token = strtok(NULL," ");
		edges[i].cost=atoi(token);
	}
	
	
	//Sorting edges by increasing order of cost
	float costs[m][2];
	for(i=0;i<m;i++) {
		costs[i][0]=edges[i].cost;
		costs[i][1]=i;
	}
	MergeSort(costs,0,m);
	
	
//	for(i=0;i<10;i++) {
//		printf("Edge %d : start : %d  :  end :  %d  cost : %d \n",i,edges[i].start,edges[i].end,edges[i].cost);
//	}
//	
//	printf("Minimum cost = %f   pour edge number %d",costs[0][0],edges[(int)costs[0][1]].label);
	
	//enter the first vertex
	vertex_added[0]=1;
	int j=0;
	int k;
	int l; //The correct indice that sorts the costs
	int Start;
	int End;
	long int min_cost;
	min_cost =0;
	while(j<n) {
		for(k=0;k<m;k++) {
			l=costs[k][1];
			Start = edges[l].start;
			End = edges[l].end;
			if((vertex_added[Start-1]==1 && vertex_added[End-1]==0 && edge_added[l]==0 )) {
				edge_added[l]=1;
				vertex_added[End-1]=1;
				min_cost=min_cost+edges[l].cost;
				break;
			}
			
			if((vertex_added[Start-1]==0 && vertex_added[End-1]==1 && edge_added[l]==0 )) {
				edge_added[l]=1;
				vertex_added[Start-1]=1;
				min_cost=min_cost+edges[l].cost;
				break;
			}
		}
		j=j+1;
	}
	
	printf("Minimum cost = %ld",min_cost);
	
}
