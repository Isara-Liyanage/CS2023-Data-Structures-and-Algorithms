#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Return the pointer to the minimum element in the tree.
node* findMin(node* root)
{
	while(root->left != NULL) {
        root = root->left;
    }
	return root;
}


// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {

  // If the tree is empty, new node becomes the root.
  if (root == NULL) {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  // Recursive call to insert the new node.
  if (key < root->key) {
    root->left = insertNode(root->left, key);
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node no child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    
    // One child
    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    } else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      delete temp;
    }
    // Two children
		else { 
			struct node *temp = findMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
	return root;
}


// Driver code
int main() {
  struct node *root = NULL;

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
    }
  }
  
  traverseInOrder(root);
}