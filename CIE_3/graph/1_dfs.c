#include <stdio.h>

// Function to perform Depth-First Search (DFS)
void depthFirstSearch(int numNodes, int adjacencyMatrix[10][10], int u, int visited[]) {
    int v;
    visited[u] = 1; // Mark current node as visited

    // Explore adjacent nodes of u
    for (v = 0; v < numNodes; v++) {
        if (adjacencyMatrix[u][v] == 1 && visited[v] == 0) { // If there is an edge from u to v and v is not visited
            depthFirstSearch(numNodes, adjacencyMatrix, v, visited); // Recursively call DFS for node v
        }
    }
}

int main() {
  
    int numNodes, i, j, adjacencyMatrix[10][10], visited[10], isConnected, flag;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    isConnected = 0; // Initialize isConnected flag to 0 (false)
    for (j = 0; j < numNodes; j++) {
        // Initialize visited array for each DFS iteration
        for (i = 0; i < numNodes; i++) {
            visited[i] = 0;
        }
        depthFirstSearch(numNodes, adjacencyMatrix, j, visited); // Perform DFS starting from node j
        flag = 0;
        for (i = 0; i < numNodes; i++) {
            if (visited[i] == 0) { // If any node is not visited after DFS, set flag to 1
                flag = 1;
            }
        }
        if (flag == 0) { // If flag is still 0 after DFS, all nodes are reachable from node j
            isConnected = 1; // Set isConnected flag to 1 (true)
        }
    }

    // Output whether the graph is connected or not
    if (isConnected == 1) {
        printf("Graph is connected\n");
    } else {
        printf("Graph is not connected\n");
    }

    return 0;
}
