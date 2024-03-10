#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree node
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new node
Node *createNode(int value)
{
  // Allocate memory for a new node
  Node *newNode = (Node *)malloc(sizeof(Node));
  // Initialize the node with the given value and NULL left and right pointers
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a value into the binary search tree
Node *insert(Node *treeNode, int value)
{
  // If the tree is empty, create a new node with the given value
  if (treeNode == NULL)
  {
    return createNode(value);
  }
  // If the value is less than the current node's value, insert into the left subtree
  if (value < treeNode->data)
  {
    treeNode->left = insert(treeNode->left, value);
  }
  // If the value is greater than the current node's value, insert into the right subtree
  else if (value > treeNode->data)
  {
    treeNode->right = insert(treeNode->right, value);
  }
  // Return the (unchanged) node pointer
  return treeNode;
}

// Function to find the minimum value node in a subtree
Node *minValueNode(Node *node)
{
  Node *current = node;

  // Loop down to find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Function to delete a node with a given value from the binary search tree
Node *deleteNode(Node *root, int value)
{
  // Base case: if the tree is empty, return NULL
  if (root == NULL){
    printf("1");
    return root;
  }
  // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
  if (value < root->data){
    printf("2");
    root->left = deleteNode(root->left, value);
  }
  // If the value to be deleted is greater than the root's value, then it lies in the right subtree
  else if (value > root->data){
    printf("3");
    root->right = deleteNode(root->right, value);
  }
  // If the value is the same as the root's value, then this is the node to be deleted
  else
  {
    printf("4");
    // Node with only one child or no child
    if (root->left == NULL)
    {
    printf("5");
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
    printf("6");
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children: get the inorder successor (smallest in the right subtree)
    Node *temp = minValueNode(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
    printf("7");
  }
  return root;
}

// Function for in-order traversal
void inorderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    inorderTraversal(treeNode->left); // Traverse left subtree
    printf("%d ", treeNode->data);    // Print current node's data
    inorderTraversal(treeNode->right); // Traverse right subtree
  }
}

// Function for pre-order traversal
void preorderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    printf("%d ", treeNode->data);     // Print current node's data
    preorderTraversal(treeNode->left); // Traverse left subtree
    preorderTraversal(treeNode->right);// Traverse right subtree
  }
}

// Function for post-order traversal
void postorderTraversal(Node *treeNode)
{
  if (treeNode != NULL)
  {
    postorderTraversal(treeNode->left); // Traverse left subtree
    postorderTraversal(treeNode->right);// Traverse right subtree
    printf("%d ", treeNode->data);      // Print current node's data
  }
}

// Function to display the binary search tree
void displayTree(Node *treeNode)
{
  printf("Elements in the binary search tree:\n");
  printf("\nIn-order traversal: ");
  inorderTraversal(treeNode); // Print in-order traversal
  printf("\nPre-order traversal: ");
  preorderTraversal(treeNode);// Print pre-order traversal
  printf("\nPost-order traversal: ");
  postorderTraversal(treeNode);// Print post-order traversal
}

// Main function
int main()
{
  int value;
  char ch;
  Node *root = NULL;

  // Prompt the user to enter values and build the binary search tree
  do
  {
    printf("\nEnter The value : ");
    scanf("%d", &value);
    root = insert(root, value); // Insert the value into the tree
    printf("\nDo You want to enter more values (Y/N): ");
    getchar(); // Clear input buffer
    scanf("%c", &ch); // Read user's choice
  } while (ch == 'y' || ch == 'Y'); // Continue loop if user enters 'y' or 'Y'

  // Display the binary search tree
  displayTree(root);

  // Deleting a node from the tree
  int deleteValue;
  printf("\nEnter the value to delete: ");
  scanf("%d", &deleteValue);
  root = deleteNode(root, deleteValue); // Delete the node with given value from the tree

  // Display the tree after deletion
  printf("\nAfter deleting %d:\n", deleteValue);
  displayTree(root);

  return 0;
}
