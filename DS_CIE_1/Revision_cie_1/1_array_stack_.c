#include <stdio.h>
#define size 10
int top = -1;

int array_stack[size];

void push(int);
void pop();
void display();

int main()
{ int run = 1  , choice,value; 
while (run)
{
  printf("Enter the choice 1. push , 2 . pop , 3. display and 4 . exit");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
      printf("Enter the value to put into the stack : ");
      scanf("%d",&value);
      push(value);
      break;
    case 2:
      pop();
      break;
    
    case 3:
      display();
      break;
    case 4: run = 0;
    break;
    default:
      break;
    }
}

    
    printf("The program is exited!!");
  return 0;
}

void push(int value)
{
  if (top >= size - 1)
  {
    printf("Stack overflow!");
  }
  else
  {
    array_stack[++top] = value;
    printf("The value is pushed into the stack");
  }
}

void pop()
{
  if (top < 0)
  {
    printf("Stack underflow");
  }
  else
  {
    printf("The popped value is %d", array_stack[top--]);
  }
}
void display()
{
  if (top < 0)
  {
    printf("Stack underflow");
  }
  else
  {
    printf("The value in stack are as follows : ");
    for (int i = top; i >= 0; i--)
    {
      printf("%d ", array_stack[i]);
    }
    printf("\n");
  }
}