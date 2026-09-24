#include "AVL.h"
#include <iostream>

Node *AVLTree::insertHelper(Node *node, string name, string ufid, bool &successful)
{
  return nullptr;
}

Node *AVLTree::removeHelper(Node *node, string ufid, bool &successful)
{
  return nullptr;
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

vector<string> AVLTree::getInorder(){
  return vector<string>();
}

vector<string> AVLTree::getPreorder(){

}

vector<string> AVLTree::getPostorder(){

}