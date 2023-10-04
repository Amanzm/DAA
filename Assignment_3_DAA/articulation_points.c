
#include "articulation_points.h"

#define min(a, b) ((a < b) ? a : b)

void DFS(Graph* G, int u, int* vis, int* disc, int* low, int* par, int* ap) {
    static int time = 0;
    int child = 0;
    vis[u] = 1;
    disc[u] = low[u] = ++time;

    Node* current = G->Adj[u];

    while (current != NULL) {
        int v = current->v;

        if (!vis[v]) {
            child++;
            par[v] = u;
            DFS(G, v, vis, disc, low, par, ap);

            low[u] = min(low[u], low[v]) ;

            if (par[u] == -1 && child > 1) {
                ap[u] = 1;
            }
            if (par[u] != -1 && low[v] >= disc[u]) {
                ap[u] = 1;
            }
        } else if (v != par[u]) 
            low[u] = min(low[u] ,disc[v]);
        

        current = current->next;
    }
}

void Ap(Graph* G) {
    int* vis = (int*)malloc(G->V * sizeof(int));
    int* disc = (int*)malloc(G->V * sizeof(int));
    int* low = (int*)malloc(G->V * sizeof(int));
    int* par = (int*)malloc(G->V * sizeof(int));
    int* ap = (int*)malloc(G->V * sizeof(int));

    for (int i = 0; i < G->V; i++) {
        vis[i] = 0;
        par[i] = -1;
        ap[i] = 0;
    }

    for (int i = 0; i < G->V; i++) 
        if (!vis[i]) DFS(G, i, vis, disc, low, par, ap);
   
    printf("Articulation points in the graph:\n");
    for (int i = 0; i < G->V; i++) 
         if(ap[i])  printf("       %d ", i);
        
    

    free(vis);
    free(disc);
    free(low);
    free(par);
    free(ap);
}
