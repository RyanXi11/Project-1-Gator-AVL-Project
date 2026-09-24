#include "AVL.h"
#include <iostream>

Node *AVLTree::insertHelper(Node *node, string name, string ufid, bool &successful){
  if(node == nullptr){
    successful = true;
    return new Node(name, ufid);
  }

  if(ufid < node->ufid){
    node->left = insertHelper(node->left, name, ufid, successful);
  }else if(ufid > node->ufid){
    node->right = insertHelper(node->right, name, ufid, successful);
  }else{
    // UFID already exists, reject insertion
    successful = false;
    return node;
  }

  // Update height of this ancestor node
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  // Get balance factor 
  int balance = getBalanceFactor(node);

  // Left heavy case (Balance > 1)
  if(balance > 1){
    if(getBalanceFactor(node->left) >= 0){
      return rotateRight(node); // Left-Left case
    }else{
      return rotateLeftRight(node); // Left-Right case
    }
  }

  // Right heavy case (Balance < -1)
  if(balance < -1){
    if(getBalanceFactor(node->right) <= 0){
      return rotateLeft(node); // Right-Right case
    }else{
      return rotateRightLeft(node); // Right-Left case
    }
  }

  return node; // Return the unmodified node pointer if perfectly balanced
}

Node *AVLTree::removeHelper(Node *node, string ufid, bool &successful){
  if(node == nullptr){
    successful = false;
    return node;
  }

  if(ufid < node->ufid){
    node->left = removeHelper(node->left, ufid, successful);
  }else if(ufid > node->ufid){
    node->right = removeHelper(node->right, ufid, successful);
  }else{
    successful = true;

    if(node->left == nullptr){
      Node* rightChild = node->right;
      delete node;
      return rightChild;
    }else if(node->right == nullptr){
      Node* leftChild = node->left;
      delete node;
      return leftChild;
    }else{
      Node* successor = getInorderSuccessor(node);
      node->name = successor->name;
      node->ufid = successor->ufid;
      node->right = removeHelper(node->right, successor->ufid, successful);
    }
  }

  // Update height of this ancestor node
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  // Get balance factor
  int balance = getBalanceFactor(node);

  // Left heavy case (Balance > 1)
  if (balance > 1)
  {
    if (getBalanceFactor(node->left) >= 0)
    {
      return rotateRight(node); // Left-Left case
    }
    else
    {
      return rotateLeftRight(node); // Left-Right case
    }
  }

  // Right heavy case (Balance < -1)
  if (balance < -1)
  {
    if (getBalanceFactor(node->right) <= 0)
    {
      return rotateLeft(node); // Right-Right case
    }
    else
    {
      return rotateRightLeft(node); // Right-Left case
    }
  }

  return node; // Return the unmodified node pointer if perfectly balanced
}

void AVLTree::inorderHelper(Node* node, vector<string>& result){
  if(node == nullptr){
    return;
  }

  inorderHelper(node->left, result);
  result.push_back(node->name);
  inorderHelper(node->right, result);
}

void AVLTree::inorderUfidHelper(Node *node, vector<string> &result){
  if (node == nullptr){
    return;
  }

  inorderUfidHelper(node->left, result);
  result.push_back(node->ufid);
  inorderUfidHelper(node->right, result);
}

void AVLTree::preorderHelper(Node *node, vector<string>& result){
  if(node == nullptr){
    return;
  }

  result.push_back(node->name);
  preorderHelper(node->left, result);
  preorderHelper(node->right, result);
}
void AVLTree::postorderHelper(Node *node, vector<string>&result){
  if(node == nullptr){
    return;
  }

  postorderHelper(node->left, result);
  postorderHelper(node->right, result);
  result.push_back(node->name);
}

Node* AVLTree::searchHelper(Node* node, string targetUfid){
  if (node == nullptr){
    return nullptr;
  }

  if(targetUfid == node->ufid){
    return node;
  } 

  if(targetUfid < node->ufid){
    return searchHelper(node->left, targetUfid);
  }else{
    return searchHelper(node->right, targetUfid);
  }
}

void AVLTree::searchNameHelper(Node* node, string targetName, bool& found){
  if(node == nullptr){
    return;
  }

  if(node->name == targetName){
    cout << node->ufid << endl;
    found = true;
  }

  searchNameHelper(node->left, targetName, found);
  searchNameHelper(node->right, targetName, found);
}

int AVLTree::getHeight(Node* node){
  if(node == nullptr){
    return 0;
  }
  return node->height;
}

int AVLTree::getBalanceFactor(Node* node){
  if(node == nullptr){
    return 0;
  }
  return getHeight(node->left) - getHeight(node->right);
}

Node* AVLTree::rotateLeft(Node *node){
  Node* newRoot = node->right;
  Node* displacedLeftChild = newRoot->left;

  //Perform rotation
  newRoot->left = node;
  node->right = displacedLeftChild;

  //Update heights
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
  
  return newRoot;
}

Node* AVLTree::rotateRight(Node *node){
  Node* newRoot = node->left;
  Node* displacedRightChild = newRoot->right;

  // Perform rotation
  newRoot->right = node;
  node->left = displacedRightChild;

  // Update heights
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

  return newRoot;
}

Node* AVLTree::rotateLeftRight(Node *node){
  node->left = rotateLeft(node->left);
  return rotateRight(node);
}

Node* AVLTree::rotateRightLeft(Node *node){
  node->right = rotateRight(node->right);
  return rotateLeft(node);
}

Node* AVLTree::getInorderSuccessor(Node* node){
  Node* current = node->right;
  while(current != nullptr && current->left != nullptr){
    current = current->left;
  }
  return current;
}

bool AVLTree::insert(string name, string ufid){
  bool successful = false;

  //Call helper, starting from root
  root = insertHelper(root, name, ufid, successful);

  if(successful){
    cout << "successful" << endl;
  }else{
    cout << "unsuccessful" << endl;
  }

  return successful;
}

bool AVLTree::remove(string ufid){
  bool successful = false;
  root = removeHelper(root, ufid, successful);

  if(successful){
    cout << "successful" << endl;
  }else{
    cout << "unsuccessful" << endl;
  }

  return successful;
}

bool AVLTree::removeInorder(int N){
  vector<string> inorderUfidList;
  inorderUfidHelper(root, inorderUfidList);

  if(N < 0 || N >= inorderUfidList.size()){
    cout << "unsuccessful" << endl;
    return false;
  }

  string targetUfid = inorderUfidList[N];

  return remove(targetUfid);
}

bool AVLTree::searchID(string ufid){
  Node* result = searchHelper(root, ufid);
  if(result == nullptr){
    cout << "unsuccessful" << endl;
    return false;
  }else{
    cout << result->name << endl;
    return true;
  }
}

bool AVLTree::searchName(string name){
  bool found = false;
  searchNameHelper(root, name, found);

  if(!found){
    cout << "unsuccessful" << endl;
  }

  return found;
}

void AVLTree::printInorder(){
  vector<string> result;
  inorderHelper(root, result);

  for(size_t i = 0; i < result.size(); i++){
    cout << result[i];
    if(i != result.size() - 1){
      cout << ", ";
    }
  }
  cout << endl;
}

void AVLTree::printPreorder(){
  vector<string> result;
  preorderHelper(root, result);

  for(size_t i = 0; i < result.size(); i++){
    cout << result[i];
    if(i != result.size() - 1){
      cout << ", ";
    }
  }
  cout << endl;
}

void AVLTree::printPostorder(){
  vector<string> result;
  postorderHelper(root, result);

  for(size_t i = 0; i < result.size(); i++){
    cout << result[i];
    if(i != result.size() - 1){
      cout << ", ";
    }
  }
  cout << endl;
}

int AVLTree::printLevelCount(){
  int levels = 0;

  if(root != nullptr){
    levels = root->height;
  }

  cout << levels << endl;
  return levels;
}