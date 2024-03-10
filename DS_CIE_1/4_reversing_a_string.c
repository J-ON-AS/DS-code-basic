#include <stdio.h>
#include <string.h>
#define MAX 1000
int top = -1;
char stack_string[MAX];
void push(char value);
int pop();
int main()
{
  char str[MAX];
  printf("Enter the string to reverse ");
  scanf("%[^\n]s", str);
  for (int i = 0; i < strlen(str); i++)
  {
    push(str[i]);
  }
  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = pop();
  }
  printf("The reverse string is (%s)",str);

  return 0;
}

void push(char value){
  stack_string[++top] = value;
}
int pop(){
  return stack_string[top--];
}