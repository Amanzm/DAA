#include "bridges.h"

#define min(a, b) ((a < b) ? a : b)

void Dfs(Graph* G, int u, int* vis, int* disc, int* low, int* par) {
    static int t = 0;
    vis[u] = 1;
    disc[u] = low[u] = ++t;

    Node* current = G->Adj[u];

    while (current != NULL) {
        int v = current->v;

        if (!vis[v]) {
            par[v] = u;
            Dfs(G, v, vis, disc, low, par);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                printf("        %d-----%d\n", u, v);
            }
        } else if (v != par[u]) {
            low[u] = min(low[u], disc[v]);
        }

        current = current->next;
    }
}

void FindBridges(Graph* G) {
    int* vis = (int*)malloc(G->V * sizeof(int));
    int* disc = (int*)malloc(G->V * sizeof(int));
    int* low = (int*)malloc(G->V * sizeof(int));
    int* par = (int*)malloc(G->V * sizeof(int));

    for (int i = 0; i < G->V; i++) {
        vis[i] = 0;
        par[i] = -1;
    }

    for (int i = 0; i < G->V; i++) {
        if (!vis[i]) {
            Dfs(G, i, vis, disc, low, par);
        }
    }

    free(vis);
    free(disc);
    free(low);
    free(par);
}
