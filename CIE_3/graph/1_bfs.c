#include <stdio.h>

void breadthFirstSearch(int adjacencyMatrix[20][20], int numberOfNodes, int source, int traversal[20][2], int visited[])
{
  int front, rear, queue[20], u, v, k = 0, i;

  // Initialize visited array to all 0s
  for (i = 0; i < numberOfNodes; i++)
    visited[i] = 0;

  // Initialize front, rear, and k to 0
  front = rear = k = 0;

  // Enqueue the source node
  queue[rear] = source;
  visited[source] = 1;

  // Perform BFS
  while (front <= rear)
  {
    u = queue[front++];

    // Explore adjacent nodes of u
    for (v = 0; v < numberOfNodes; v++)
    {
      if (adjacencyMatrix[u][v] == 1 && visited[v] == 0)
      {
        visited[v] = 1;
        queue[++rear] = v;
        traversal[k][0] = u;
        traversal[k][1] = v;
        k++;
      }
    }
  }
}

int main()
{
  int numberOfNodes, adjacencyMatrix[20][20], source, traversal[20][2], flag, visited[20], i, j;

  // Input the number of nodes
  printf("Enter the number of nodes: ");
  scanf("%d", &numberOfNodes);

  // Input the adjacency matrix
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < numberOfNodes; i++)
  {
    for (j = 0; j < numberOfNodes; j++)
      scanf("%d", &adjacencyMatrix[i][j]);
  }

  // Input the source node
  printf("Enter the source node: ");
  scanf("%d", &source);

  // Perform BFS
  breadthFirstSearch(adjacencyMatrix, numberOfNodes, source, traversal, visited);

  // Check if all nodes are reachable
  flag = 0;
  for (i = 0; i < numberOfNodes; i++)
  {
    if (visited[i] == 0)
    {
      printf("Vertex %d is not reachable\n", i);
      flag = 1;
    }
    else
    {
      printf("Vertex %d is reachable\n", i);
    }
  }

  // Output BFS traversal
  if (flag == 1)
  {
    printf("Some nodes are not visited\n");
  }
  else
  {
    printf("The BFS traversal is:\n");
    for (i = 0; i < numberOfNodes - 1; i++)
      printf("%d %d\n", traversal[i][0], traversal[i][1]);
  }

  return 0;
}
