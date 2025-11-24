#include <stdio.h>
#include <stdlib.h>

#define MAX 20


int adjMatrix[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

void resetVisitArrays() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
}

//cycle detection (dfs based)
int detectCycleDFS(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i]) {
            if (!visited[i] && detectCycleDFS(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

// Function to check if the graph has a cycle
int isCyclic() {
    resetVisitArrays();
    for (int i = 0; i < n; i++) {
        if (!visited[i] && detectCycleDFS(i))
            return 1;
    }
    return 0;
}

//read from file
void readGraphFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    printf("Reading graph from file with %d vertices...\n", n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &adjMatrix[i][j]);

    fclose(fp);
}

//read as adjacency list
void readGraphAdjList() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
    }
}

//addjacency matrix 
void readGraphAdjMatrix() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMatrix[i][j]);
}

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("  CYCLE DETECTION IN GRAPH\n");
        printf("==============================\n");
        printf("1. Detect cycle (Input from file)\n");
        printf("2. Detect cycle (Adjacency List)\n");
        printf("3. Detect cycle (Adjacency Matrix)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char filename[50];
                printf("Enter filename (e.g., graph.txt): ");
                scanf("%s", filename);
                readGraphFromFile(filename);
                if (isCyclic())
                    printf("Cycle detected in the graph (from file)\n");
                else
                    printf("No cycle detected in the graph (from file)\n");
                break;
            }

            case 2:
                readGraphAdjList();
                if (isCyclic())
                    printf("Cycle detected (Adjacency List)\n");
                else
                    printf("No cycle detected (Adjacency List)\n");
                break;

            case 3:
                readGraphAdjMatrix();
                if (isCyclic())
                    printf("Cycle detected (Adjacency Matrix)\n");
                else
                    printf("No cycle detected (Adjacency Matrix)\n");
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
