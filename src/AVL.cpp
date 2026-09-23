#include "AVL.h"
#include <iostream>

int Node::getHeight(Node* node){
  if(node == nullptr){
    return 0;
  }
  return node->height;
}

int Node::getBalanceFactor(Node* node){
  if(node == nullptr){
    return 0;
  }
  return getHeight(node->left) - getHeight(node->right);
}

bool AVLTree::insert(string name, string ufid){
  bool successful = false;
  return successful;
}

bool AVLTree::remove(string ufid){
  bool successful = false;
  return successful;
}

bool AVLTree::search(string ufid){
  return false;
}

vector<string> AVLTree::getInorder(){
  return vector<string>();
}

Node* AVLTree::insertHelper(Node* node, string name, string ufid, bool& successful){
  return nullptr;
}

Node* AVLTree::removeHelper(Node* node, string ufid, bool& successful){
  return nullptr;
}