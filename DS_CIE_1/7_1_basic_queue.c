#include <stdio.h>
#define size 20

int rear = -1;
int front = -1;
int queue_array[size];

void insert(int value)
{
  if (rear == size - 1)
  {
    printf("Queue Overflow!!!\n");
  }
  else
  {
    if (front == -1)
    {
      front = 0;
    }
    queue_array[++rear] = value;
    printf("The value is being inserted!\n");
  }
}
void delete()
{
  if (front == -1 || front > rear)
  {
    printf("Queue Underflow!!!\n");
  }
  else
  {
    printf("The deleted element is %d \n", queue_array[front++]);
  }
}

void display()
{
  if (front == -1 && rear == -1)
  {
    printf("Empty Queue!!!\n");
  }
  else
  {
    printf("The element in the queue are : ");
    for (int i = front; i <= rear; i++)
    {
      printf("%d ", queue_array[i]);
    }
    printf("\n");
  }
}

int main()
{
  int run = 1, n, value;
  while (run)
  {
    printf("Enter the requirement 1. insertion 2 . Deletion 3 . display and 4 to exit : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      printf("Enter the value to insert : ");
      scanf("%d", &value);
      insert(value);
      break;
    case 2:
      delete ();
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
  printf("Exited the program!!!!!!!!!!!!!");
  return 0;
}