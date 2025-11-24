#include <stdio.h>
#include <stdlib.h>

int n;
int adj[20][20];
int visited[20];

void dfs(int v, int skipNode) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (i != skipNode && adj[v][i] == 1 && visited[i] == 0)
            dfs(i, skipNode);
    }
}

int isConnected(int skipNode) {
    int startNode = -1;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        if (i != skipNode && startNode == -1)
            startNode = i;
    }

    dfs(startNode, skipNode);

    for (int i = 0; i < n; i++) {
        if (i != skipNode && visited[i] == 0)
            return 0;
    }
    return 1;
}

int main() {
    printf("Enter number of nodes in the network: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (!isConnected(-1)) {
        printf("\nNetwork is already disconnected!\n");
        return 0;
    }

    printf("\nDetecting single node failures...\n");

    for (int node = 0; node < n; node++) {
        if (isConnected(node))
            printf("Removing Node %d → Network still connected.\n", node);
        else
            printf("Removing Node %d → Network DISCONNECTED! (Node %d is a critical node)\n", node, node);
    }

    return 0;
}
