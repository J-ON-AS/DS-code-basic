#include <stdio.h>
int k;
void bfs(int AdjacencyMatrix[20][20], int numberOfNodes, int source, int traversal[20][2], int visited[])
{
  int front, rear, queue[20], u, v, i;
  for (i = 0; i < numberOfNodes; i++)
  {
    visited[i] = 0;
  }
  front = rear = k = 0;

  queue[rear] = source;
  visited[source] = 1;
  while (front <= rear)
  {
    u = queue[front++];
    for (int j = 0; j < numberOfNodes; j++)
    {
      if (AdjacencyMatrix[u][j] == 1 && visited[j] == 0)
      {
        visited[j] = 1;
        queue[++rear] = j;
        traversal[k][0] = u;
        traversal[k][1] = j;
        k++;
      }
    }
  }
}
int main()
{
  int numberOfNodes, AdjacencyMatrix[20][20], traversal[20][2], source, flag, visited[20], i, j;
  printf("Enter the number of nodes You want to Enter : ");
  scanf("%d", &numberOfNodes);
  printf("Enter the Adjacency Matrix :\n");
  for (i = 0; i < numberOfNodes; i++)
  {
    for (j = 0; j < numberOfNodes; j++)
    {
      scanf("%d", &AdjacencyMatrix[i][j]);
    }
  }
  printf("Enter the source node : ");
  scanf("%d", &source);
  bfs(AdjacencyMatrix, numberOfNodes, source, traversal, visited);
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
  if (flag == 1)
  {
    printf("Some nodes are not reachable\n");
  }
  else
  {
    printf("The BFS traversal is :");
    for (i = 0; i < k; i++)
    {
      printf("%d%d ", traversal[i][0], traversal[i][1]);
    }
  }
  return 0;
}