#include <stdio.h>

#define size 2
int queue_array[size];
int front = -1;
int rear = -1;
void enqueue(int value)
{
  if (rear >= size - 1)
  {
    printf("Queue Overflow\n");
  }
  else
  {
    if (front == -1)
    {
      front = front + 1;
    }
    queue_array[++rear] = value;
  printf("The value is enqueued\n");
  }
}
void dequeue()
{
  if (rear == -1 || front > rear)
  {
    printf("Queue Underflow\n");
  }
  else
  {
    printf("The dequeued element is %d\n", queue_array[front++]);
  }
}
void display()
{
  printf("The elements in the queue are as follow : ");
  for (int i = front; i <= rear; i++)
  {
    printf("%d ", queue_array[i]);
  }
  printf("\n");
}
int main()
{
  int choice, value, run = 1;
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