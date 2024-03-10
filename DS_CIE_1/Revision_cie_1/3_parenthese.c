#include <stdio.h>
#include <string.h>

#define max 20
int top = -1;

char stack_array[max];

void push(char value)
{
  if (top >= max - 1)
  {
    printf("Stack overflow");
  }
  else
  {
    stack_array[++top] = value;
  }
}
char pop()
{
  if (top < 0)
  {
    printf("Stack underflow");
  }
  else
  {
    return stack_array[top--];
  }
}
int match(char  , char );
int check(char exp[])
{
  char temp;
  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
    {
      push(exp[i]);
    }else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
      if(top == -1){
        printf("Right parenthesis are more than left parenthesis!\n");
        return 0;
      }else{
        temp = pop();
        if(!match(temp,exp[i])){
          printf("Mismatched parenthesis are : ");
          printf("%c and %c\n",temp,exp[i]);
          return 0;
        }
      }
    }
  }
  if(top == -1){
    printf("Balanced Parenthesis!\n");
    return 1;
  }
  else{
    printf("Left parenthesis are more than right parentesis\n");
    return 0;
  }
}
int match(char a , char b){
  if(a == '{' && b == '}'){
    return 1;
  }
  else if(a == '(' && b == ')'){
    return 1;
  }
  else if(a == '[' && b==']'){
    return 1;
  }
  return 0;
}

int main()
{
  char exp[100];
  printf("Enter the expression to evaluate : ");
  scanf("%[^\n]s",exp);
  int valid = check(exp);
  if(valid == 1){
    printf("Valid Parenthesis");
  }
  else if(valid == 0){
    printf("InValid Parenthesis");
  }

  return 0;
}