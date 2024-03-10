#include <stdio.h>
#define size 5
typedef struct Product
{
  int code;
  int memoryAddress;
} Product;

Product hashTable[size];

void init()
{
  int i;
  for (i = 0; i < size; i++)
  {
    hashTable[i].code = -1;
    hashTable[i].memoryAddress = -1;
  }
}
int hash(int code)
{
  return code % size;
}
void insert(int code, int memoryAddress)
{
  int index = hash(code);
  int i = 0;
  while (hashTable[index].code != -1)
  {
    index = (index + 1) % size;
    i++;
    if (i == size)
    {
      printf("The hash Map is completely full\n");
      return;
    }
  }
  hashTable[index].code = code;
  hashTable[index].memoryAddress = memoryAddress;
  printf("The product with code %d is inserted at memory address %d \n", code, memoryAddress);
}
void search(int code)
{
  int index = hash(code);
  int i = 0;
  while (hashTable[index].code != code)
  {
    index = (index + 1) % size;
    i++;
    if (hashTable[i].code == -1 || i == size)
    {
      printf("The product with code %d is not found in the Hash Map\n", code);
      return ;
    }
  }
  printf("The product with code %d is found at memory address %d in Hash Map\n",code , hashTable[index].memoryAddress);
}
void printMap(){
  int i ;
  for ( i = 0; i < size; i++)
  {
    printf("Bucket[%d] -> %d @ address ->%d\n",i,hashTable[i].code,hashTable[i].memoryAddress);
  }  
}

int main (){
  int run = 1, choice,value,ma;
  init();
  while(run == 1){
    printf("Enter the operation to perform 1. Insert , 2.Search ,3.display And 4 to exit : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: printf("Enter the code and memoryAddress to insert : ");
    scanf("%d",&value);
    scanf("%d",&ma);
    insert(value,ma);
      break;
    case 2: printf("Enter the code to search : ");
    scanf("%d",&value);
    search(value);
    break;
    case 3 :printMap();
    break;
    case 4 :run = 0;
    break;
    default:
      break;
    }
  }
  printf("Exiting the program !!!");
  return 0;
}