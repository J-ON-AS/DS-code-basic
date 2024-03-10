#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;
Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode; 
}
Node *insert(Node *treeNode, int value)
{
  if (treeNode == NULL)
  {
    return createNode(value);
  }
  if (treeNode->data > value)
  {
    treeNode->left = insert(treeNode->left, value);
  }
  if (treeNode->data < value)
  {
    treeNode->right = insert(treeNode->right, value);
  }
  return treeNode;
}

Node *minValue(Node *treeNode)
{
  Node *current = treeNode;
  while (current != NULL && current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

Node *deleteNode(Node *root, int value)
{
  if (root == NULL)
  {
    return root;
  }
  if (value < root->data)
  {
    root->left = deleteNode(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = deleteNode(root->right, value);
  }
  else
  {
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = minValue(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void inOrderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    inOrderTraversal(treeNode->left);
    printf("%d ", treeNode->data);
    inOrderTraversal(treeNode->right);
  }
}
void preOrderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    printf("%d ", treeNode->data);
    preOrderTraversal(treeNode->left);
    preOrderTraversal(treeNode->right);
  }
}
void postOrderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    postOrderTraversal(treeNode->left);
    postOrderTraversal(treeNode->right);
    printf("%d ", treeNode->data);
  }
}
void display(Node *treeNode)
{
  printf("\nThe Inorder Traversal : ");
  inOrderTraversal(treeNode);
  printf("\nThe preOrder Traversal : ");
  preOrderTraversal(treeNode);
  printf("\nThe postOrder Traversal : ");
  postOrderTraversal(treeNode);
}

void main()
{
  int value, deleteValue;
  Node *root = NULL;
  char ch;

  do
  {
    printf("Enter the value : ");
    scanf("%d", &value);
    root = insert(root, value);
    printf("\nDo You want to enter more values (Y/N): ");
    getchar();
    scanf("%c", &ch);
  } while (ch == 'y' || ch == 'Y');
  display(root);
  printf("\nEnter the Node you want to delete : ");
  scanf("%d", &deleteValue);
  root = deleteNode(root, deleteValue);
  printf("\nAfter deleting %d",deleteValue);
  display(root);
}