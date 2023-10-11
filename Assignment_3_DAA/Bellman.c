#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100


struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};


void readGraph(struct Graph* graph, const char* filename) {
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d %d", &graph->V, &graph->E);

    for (int i = 0; i < graph->E; i++) {
        fscanf(file, "%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    fclose(file);
}


void printSolution(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}


void bellmanFord(struct Graph* graph, int src) {
    int dist[MAX_VERTICES];

    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int i = 1; i < graph->V; i++) {
        for (int j = 0; j < graph->E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    printSolution(dist, graph->V);
}

int main() {
    struct Graph graph;
    readGraph(&graph, "sssp.txt");

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Bellman-Ford Algorithm:\n");
    bellmanFord(&graph, source);

    return 0;
}

