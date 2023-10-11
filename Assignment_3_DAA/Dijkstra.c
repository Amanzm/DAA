#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INFINITY INT_MAX

struct Graph {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initializeGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    graph->edges = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
}

void addEdge(struct Graph* graph, int source, int destination, int weight) {
    graph->adjacencyMatrix[source][destination] = weight;
    graph->edges++;
}

void dijkstra(struct Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < graph->vertices; i++) {
        distance[i] = INFINITY;
        visited[i] = 0;
    }

    distance[startVertex] = 0;

    for (int i = 0; i < graph->vertices - 1; i++) {
        int minDistance = INFINITY;
        int u;

        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && graph->adjacencyMatrix[u][v] != INFINITY) {
                if (distance[u] + graph->adjacencyMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph->adjacencyMatrix[u][v];
                }
            }
        }
    }


    printf("Vertex\tDistance from Start Vertex %d\n", startVertex);
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    FILE* file = fopen("sssp.txt", "r");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int vertices, edges;
    fscanf(file, "%d %d", &vertices, &edges);

    struct Graph graph;
    initializeGraph(&graph, vertices);

    for (int i = 0; i < edges; i++) {
        int source, destination, weight;
        fscanf(file, "%d %d %d", &source, &destination, &weight);
        addEdge(&graph, source, destination, weight);
    }

    fclose(file);

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(&graph, source);
    return 0;
}

     

 
