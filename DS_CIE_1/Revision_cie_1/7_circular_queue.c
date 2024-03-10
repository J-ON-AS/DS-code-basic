#include <stdio.h>

#define size 6
int front = -1;
int rear = -1;
int cir_que_arr[size];

void enqueue(int value)
{
  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("The queue is full!!!!\n");
  }
  else
  {if(front == -1){
    front = 0;
  }
    rear = (rear + 1) % size;
    cir_que_arr[rear] = value;
  }
}
void dequeue()
{
  if (front == -1)
  {
    printf("Queue is empty");
  }
  else
  {
    if (rear == front)
    {
      front = -1;
      rear = -1;
    }
    int element = cir_que_arr[front];
    front = (front + 1) % size;
    printf("The deleted value is %d \n",element);
  }
}
void display()
{
  if (front == -1)
  {
    printf("Queue is empty");
  }
  else
  {
    printf("The elements of the circular queue are as follows : ");
    for (int i = front; i != rear; i = (i + 1) % size)
    {
      printf("%d ", cir_que_arr[i]);
    }
    printf("%d",cir_que_arr[rear]);
    printf("\n");
  }
}
int main()
{ int choice, value, run = 1;
  while (run)
  {
    printf("Enter the choice 1. enqueue 2 . dequeue 3 .display and 4 to exit the program : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the value you want to add in queue : ");
      scanf("%d", &value);
      enqueue(value);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      run = 0;
      break;
    default:
      break;
    }
  }
  printf("The program is exited\n");
  return 0;
}