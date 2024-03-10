#include <stdio.h>
#include <stdlib.h>
int *ht, size;
int count = 0;

void initHashTable()
{
  ht = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    ht[i] = -1;
  }
}

void insert(int value)
{
  int index = value % size;
  while (ht[index] != -1)
  {
    index = (index + 1) % size;
  }
  ht[index] = value;
  count++;
}
void display(){
  if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }
 printf("\nHash Table contents are:\n ");
    for(int i = 0; i < size; i++) {
        printf("\n T[%d] --> %d ", i, ht[i]);
    }
}
int main(){
  int n ;
  printf("Enter the number of employees for which data need to be entered {N}:");
  scanf("%d",&n);
  printf("Enter the size of Hash Map :");
  scanf("%d",&size);
  initHashTable();
  int value;
  printf("Enter the key values for the Employees {N} : ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&value);
    if (count == size)
    {
      printf("The Hash Map is fULl");
      break;
    }
    insert(value);    
  }
  display();
  return 0;
}