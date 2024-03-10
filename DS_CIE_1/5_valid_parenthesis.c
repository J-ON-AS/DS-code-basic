#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
int top = -1;
int match (char a , char b){
  if (a=='[' && b == ']'){
    return 1;
  }
  else if(a=='{' && b == '}'){
    return 1;
  }
  else if(a=='(' && b == ')'){
    return 1;
  }
  return 0;
}
int stack[MAX];
void push(char);
char pop();
int match(char a, char b);
int check(char[]);

int main()
{
  char exp[MAX];
  int valid;
  printf("Enter an algebraic expression : ");
  scanf("%[^\n]s", exp);
  valid = check(exp);
  if (valid == 1)
  {
    printf("Valid Expression!!!");
  }
  else
  {
    printf("Invalid Expression!!!!!!");
  }
  return 0;
}
int check(char exp[])
{
  int i;
  char temp;
  for (i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    {
      push(exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {

      if (top == -1)
      {
        printf("Right parenthesis are more than left parentheses");
        return 0;
      }
      else
      {
        temp = pop();
        if (!match(temp, exp[i]))
        {
          printf("Mismatched parentheses are : ");
          printf("%c and %c \n", temp, exp[i]);
          return 0;
        }
      }
    }
  }
  if(top==-1){
    printf("Balanced Parentheses\n");
    return 1;
  }
  else{
    printf("Left parentheses more than right parentheses\n");
    return 0;
  }
}
void push(char value){
  if(top == (MAX-1)){
    printf("Stack OverFlow\n");
    return;
  }
  stack[++top] = value;
}
char pop(){
  if(top == -1){
    printf("Stack Underflow\n");
    exit(1);
  }
  return stack[top--];
}