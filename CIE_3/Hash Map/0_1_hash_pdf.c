#include <stdio.h>

#define size 5

int arr[size];

void init()
{
  int i;
  for (i = 0; i < size; i++)
  {
    arr[i] = -1;
  }
}

void insert(int value)
{
  int key = value % size;
  if (arr[key] == -1)
  {
    arr[key] = value;
    printf("%d is inserted at %d\n", value, key);
  }
  else
  {
    printf("Collision occured ,%d value is already present at %d location\n", arr[key], key);
  }
}
void delete(int value){
  int key = value % size;
  if (arr[key] == value)
  {
    arr[key] = -1;
    printf("%d is deleted from %d (Hash Map)\n", value, key);
  }
  else
  {
    printf("Value not present in the Hash Map\n");
  }
}
void search(int value){
  int key = value % size;
  if (arr[key] == value)
  {
    printf("%d is found at  %d in the Hash Map\n", value, key);
  }
  else
  {
    printf("Value not present in the Hash Map\n");
  }
}
void printMap(){
  int i ;
  for ( i = 0; i < size; i++)
  {
    printf("Bucket[%d] -> %d\n",i,arr[i]);
  }  
}

int main (){
  int run = 1, choice,value;
  init();
  while(run == 1){
    printf("Enter the operation to perform 1. Insert , 2.Delete , 3.Search , 4.Print And 5 to exit : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: printf("Enter the value to insert : ");
    scanf("%d",&value);
    insert(value);
      break;
    case 2: printf("Enter the value to insert : ");
    scanf("%d",&value);
    delete(value);
    break;
    case 3: printf("Enter the value to search : ");
    scanf("%d",&value);
    search(value);
    break;
    case 4:printMap();
    break;
    case 5 :run = 0;
    break;
    default:
      break;
    }
  }
  printf("Exiting the program !!!");
}