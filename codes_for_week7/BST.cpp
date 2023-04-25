#include <iostream>
using namespace std;

struct Node 
{
  int key;
  struct Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) 
{
  if (root != nullptr)
  {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct Node *insertNode(struct Node *node, int value) 
{
  if (node == nullptr) 
  {
    node = new Node{value, nullptr, nullptr};
  }

  else if (value < node->key )
  {
    node->left = insertNode(node->left, value);
  }
  
  else
  {
    node->right = insertNode(node->right, value);
  }

  return node;
}

// Deleting a node

struct Node *find_minimum(struct Node* data)
{
  while (data->left != nullptr)
  {
    data = data->left;
  }
  
  return data;
}

struct Node *deleteNode(struct Node *root, int value) 
{
  if (root == nullptr)
  {
    return nullptr;
  }

  else if (value < root->key)
  {
    root->left = deleteNode(root->left, value);
  }

  else if (value > root->key)
  {
    root->right = deleteNode(root->right, value);
  }

  else
  {
    if (root->left == nullptr && root->right == nullptr)
    {
      delete root;
      root = nullptr;
    }

    else if (root->left == nullptr)
    {
      struct Node *temp = root;
      root = root->right;
      delete temp;
    }

    else if (root->right == nullptr)
    {
      struct Node *temp = root;
      root = root->left;
      delete temp;
    }

    else
    {
      struct Node *temp = find_minimum(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  return root;
}

// Driver code
int main() 
{
  struct Node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}