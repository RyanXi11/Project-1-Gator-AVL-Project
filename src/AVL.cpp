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
  return nullptr;
}

void AVLTree::inorderHelper(Node* node, vector<string>& result){
  if(node == nullptr){
    return;
  }

  inorderHelper(node->left, result);
  result.push_back(node->name);
  inorderHelper(node->right, result);
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
  return successful;
}

bool AVLTree::removeInorder(int N){

}

bool AVLTree::searchID(string ufid){
  return false;
}

bool AVLTree::searchName(string name){

}

void AVLTree::printInorder(){
  vector<string> result;
  inorderHelper(root, result);

  for(size_t i = 0; i < result.size(); i++){
    cout << result[i];
    if(i != result.size() - 1){
      cout << ",";
    }
  }
  cout << endl;
}

void AVLTree::printPreorder(){

}

void AVLTree::printPostorder(){

}

int printLevelCount(){

}