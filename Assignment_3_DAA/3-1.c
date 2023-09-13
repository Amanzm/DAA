#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int v;
	struct Node * next;

}Node;

Node * CreateNode(int x){

	Node * t=(Node*)malloc(sizeof(Node));
	t->v=x;
	t->next=NULL;
return t;
}


typedef struct Graph {

int V;
Node** Adj;
}Graph;


Graph * CreateGraph(int Vertices){

 	Graph *G=(Graph*)malloc(sizeof(Graph));
 	Node ** listOfV=(Node **)malloc(Vertices *sizeof(Node *));
 	
 	G->Adj= listOfV;
 	G->V=Vertices;
 	
 	int i;
 	for(i=0;i<Vertices; i++)
 		G->Adj[i]=NULL;
return G;
}



void AddEdge(Graph *G, int s, int d)
{
	Node * t= CreateNode (s);
	t->next=G->Adj[d];
	G->Adj[d]=t;
	
	t=CreateNode (d);
	t->next=G->Adj[s];
	G->Adj[s]=t;
	
}
void PrintGraph(Graph* G) {
    for (int i = 0; i < G->V; i++) {
        printf("Adjacency list for vertex %d: ", i);
        Node* current = G->Adj[i];
        while (current != NULL) {
            printf("%d -> ", current->v);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 4;
    Graph* G = CreateGraph(V);
    

    AddEdge(G, 0, 1);
    AddEdge(G, 0, 2);
    AddEdge(G, 1, 2);
    AddEdge(G, 2, 0);
    AddEdge(G, 2, 3);
    AddEdge(G, 3, 3);
    

    PrintGraph(G);
    
    return 0;
}


