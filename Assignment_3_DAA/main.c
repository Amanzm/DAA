
#include "bridges.c"
#include "articulation_points.c"


int main() {
    FILE *file = fopen("input.txt", "r"); // Open the input file in read mode
    int V;
    fscanf(file, "%d", &V); 
    Graph* G = CreateGraph(V);
    int s, d;
    while (fscanf(file, "%d %d", &s, &d) == 2) AddEdge(G, s, d);
    fclose(file); 

  // PrintGraph(G);

 printf("Bridges in the graph:\n");
    FindBridges(G);

    Ap(G);
    return 0;
}