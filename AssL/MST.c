#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int *parent, *rank;
    int n;
};

struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->n = n;
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
    return set;
}

int find(struct DisjointSet* set, int i) {
    if (i != set->parent[i])
        set->parent[i] = find(set, set->parent[i]);
    return set->parent[i];
}

void unionSets(struct DisjointSet* set, int x, int y) {
    int xRoot = find(set, x);
    int yRoot = find(set, y);

    if (xRoot != yRoot) {
        if (set->rank[xRoot] < set->rank[yRoot])
            set->parent[xRoot] = yRoot;
        else if (set->rank[xRoot] > set->rank[yRoot])
            set->parent[yRoot] = xRoot;
        else {
            set->parent[yRoot] = xRoot;
            set->rank[xRoot]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Edge* edges, int n, int e, FILE* ou) {
    qsort(edges, e, sizeof(struct Edge), compareEdges);

    struct Edge* result = (struct Edge*)malloc(n * sizeof(struct Edge));
    int i = 0, j = 0;
    struct DisjointSet* set = createSet(n);

    while (i < n - 1 && j < e) {
        struct Edge nextEdge = edges[j++];
        int x = find(set, nextEdge.src);
        int y = find(set, nextEdge.dest);

        if (x != y) {
            result[i++] = nextEdge;
            unionSets(set, x, y);
        }
    }

    fprintf(ou, "Edges in the Minimum Spanning Tree (Kruskal's):\n");
    for (i = 0; i < n - 1; i++) {
        fprintf(ou, "%d - %d (%d)\n", result[i].src, result[i].dest, result[i].weight);
    }
    fprintf(ou, "\n");
    free(result);
    free(set->parent);
    free(set->rank);
    free(set);
}

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n, FILE* ou) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    fprintf(ou, "Edges in the Minimum Spanning Tree (Prim's):\n");
    for (int i = 1; i < n; i++) {
        fprintf(ou, "%d - %d (%d)\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n, e;
    FILE* in = fopen("io.txt", "r");
    fscanf(in, "%d %d", &n, &e);

    struct Edge edges[e];
    int graph[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        fscanf(in, "%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        graph[edges[i].src][edges[i].dest] = edges[i].weight;
        graph[edges[i].dest][edges[i].src] = edges[i].weight;
    }

    fclose(in);

    FILE* ou = fopen("io.txt", "a");

    kruskalMST(edges, n, e, ou);
    primMST(graph, n, ou);

    fclose(ou);

    return 0;
}
