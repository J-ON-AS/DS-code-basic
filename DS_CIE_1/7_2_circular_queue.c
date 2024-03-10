#include <stdio.h>

#define size 5
int front = -1;
int rear = -1;
int cir_que_arr[size];

void enqueue(int value)
{
  if((front == rear +1) || ( front == 0 && rear == size -1)){
    printf("The queue is in overflow!!!");
  }else{
    if(front == -1){
      front = 0;
    }
    rear = (rear+1)%size;
    cir_que_arr[rear] = value;    
  }
}
void dequeue(){
  if(front == -1){
    printf("Queue is in underflow!!!");
  }else{
    int element = cir_que_arr[front];
    front = (front+1)%size;
    printf("The Deleted value is %d",element);
  }
}
void display(){
  if (front == -1)
  {
   printf("The queue is empty!!!!!!!");
  }
  else{
    printf("The element of the circular queue are : ");
    for (int i = front; i != rear;i = ((i + 1) %size))
    {
      printf("%d ",cir_que_arr[i]);
    }
    printf("%d",cir_que_arr[rear]);
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
  printf("Exited the program!!!!!!!!!!!!!");
  return 0;
}