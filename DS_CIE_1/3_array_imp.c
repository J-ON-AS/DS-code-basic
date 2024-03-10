#include<stdio.h>

#define size 5
void push (int);
void pop();
void display();
int stack[size] , top = -1;

int main(){
  int choice;
  int value;
  int i = 0;
  while(i == 0){
  printf("Enter the choice 1. push , 2. pop , 3 . display 4 . close : ");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:
    printf("Enter the value to push into the stack \n");
    scanf("%d",&value);
    push(value);
    break;
  case 2: pop();
  break;
  case 3: display();
  break;
  case 4: i = 1;
  break;
  default:
    break;
  }}
  return 0;
}

void push(int value){
  stack[++top] = value;
  printf("The value has been pushed into the stack !!!\n");
}
void pop(){
  if(top > -1){
  int a = stack[top--];
  printf("The popped value is %d \n",a);
  }
}
void display(){
  if(top == -1){
    printf("The stack is empty !!!\n");
  }else{
    printf("The value in stack are as follow : ");
    for(int i = top ;i>-1 ;i--){
      printf(" %d",stack[i]);
    }
    printf("\n");
  }
}