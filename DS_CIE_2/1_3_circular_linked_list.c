#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct LinkedList
{
    struct Node *head;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation failed");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
void insertAtFront(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    if (list->head == NULL)
    {
      newNode->next = newNode;
    }else{
    newNode->next = list->head;
    struct Node *current = list->head;
    while (current->next != list->head)
    {
      current = current->next;
    }
    current->next = newNode;
    }
    list->head = newNode;
}
void insertAtLast(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        newNode->next = newNode;
        return;
    }
    struct Node *current = list->head;
    while (current->next != list->head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = list->head;
}

void insertAtPosition(struct LinkedList *list, int data, int position)
{
    if (position == 1)
    {
        insertAtFront(list, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *current = list->head;
    for (int i = 1; i < position - 1; i++)
    {
        if (current == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtFront(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Nothing to delete\n Enter sth first\n");
    }
    struct Node *temp = list->head;
    list->head = list->head->next;
     if (temp == temp->next) {
        list->head = NULL;
    }else{
       struct Node *current = list->head;
        while (current->next != temp)
        {
            current = current->next;
        }
        current->next = list->head;
    }
    free(temp);
}
void deleteAtLast(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Nothing to delete\n Enter sth first\n");
        return;
    }
    if (list->head->next == list->head){
    free(list->head);
    list->head = NULL;
    return;
   }   
    
    struct Node *current = list->head;
    struct Node *previous = NULL;

    while (current->next != list->head)
    {   
        previous = current;
        current = current->next;
    }
     
    
    free(current);
}
void deleteAtPosition(struct LinkedList *list, int position)
{
    if (list->head == NULL)
    {
        printf("Nothing to delete\n Enter sth first\n");
        return;
    }
    struct Node *current = list->head;
    struct Node *previous = NULL;

    for (int i = 1; i < position; i++)
    {
        previous = current;
        current = current->next;
    }

    if (previous != NULL)
    {
        previous->next = current->next;
    }
    else
    {
        list->head = current->next;
        struct Node *temp = list->head;
        while (temp->next != current)
        {
            temp = temp->next;
        }
        temp->next = list->head; 
    }

    printf("Deleted %d\n", current->data);
    free(current);
}


void display(struct LinkedList *list)
{

    if (list->head == NULL)
    {
      printf("The list is empty. Enter sth to display");
      return;
    }
    struct Node *current = list->head;
    do{ 
      printf("%d -> ", current->data);
      current = current->next;
    }while (current != list->head);
    printf("HEAD\n");
}

int main(){
    struct LinkedList linkedList;
    linkedList.head = NULL;
    int choice, data, position;
    while (1){
        printf("\nLinked List Operations:\n1. Insert at Front\n2. Insert at Last\n3. Insert at Position\n4. Delete at front\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert \n");
            scanf("%d", &data);
            insertAtFront(&linkedList, data);
            break;
        case 2:
            printf("Enter the value to insert \n");
            scanf("%d", &data);
            insertAtLast(&linkedList, data);
            break;
        case 3:
            printf("Enter the value to insert \n");
            scanf("%d", &data);
            printf("Enter the position where  to insert \n");
            scanf("%d", &position);
            insertAtPosition(&linkedList, data, position);
            break;
        case 4:
            deleteAtFront(&linkedList);
            break;
        case 5:
            deleteAtLast(&linkedList);
            break;
        case 6:
            printf("Enter the position from which you want to delete\n");
            scanf("%d", &position);
            deleteAtPosition(&linkedList, position);
            break;
        case 7:
            display(&linkedList);
            break;
        case 8:
            printf("Exiting the program ....");
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}