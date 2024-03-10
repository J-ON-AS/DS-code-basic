#include <stdio.h>
void dfs(int adjacencyMatrix[20][20], int numberOfNodes, int u, int visited[])
{
  int v;
  visited[u] = 1;
  for (v = 0; v < numberOfNodes; v++)
  {
    if (adjacencyMatrix[u][v] == 1 && visited[v] == 0)
    {
      dfs(adjacencyMatrix, numberOfNodes, v, visited);
    }
  }
}
int main()
{
  int adjacencyMatrix[20][20], numberOfNodes, u, flag, visited[20];
  printf("Enter the number of nodes : ");
  scanf("%d", &numberOfNodes);
  printf("Enter the adjacency Matrix : \n");
  for (int i = 0; i < numberOfNodes; i++)
  {
    for (int j = 0; j < numberOfNodes; j++)
    {
      scanf("%d", &adjacencyMatrix[i][j]);
    }
  }
  int isConnected = 0;
  for (int j = 0; j < numberOfNodes; j++)
  {
    for (int i = 0; i < numberOfNodes; i++)
    {
      visited[i] = 0;
    }
    dfs(adjacencyMatrix, numberOfNodes, j, visited);
    flag = 0;
    for (int i = 0; i < numberOfNodes; i++)
    {
      if (visited[i] == 0)
      {
        flag = 1;
      }
    }
    if (flag == 0)
    {
      isConnected = 1;
    }
  }
  if (isConnected == 1)
  {
    printf("The Graph is connected");
  }
  else
  {
    printf("The Graph is not connected");
  }

  return 0;
}